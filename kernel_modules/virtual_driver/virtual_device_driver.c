#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tony_Montana");
MODULE_DESCRIPTION("Cats Module");
MODULE_VERSION("1.0.0");

static char buffer[255];
static size_t buffer_pointer;

static dev_t my_device_nr;
static struct class *my_class;
static struct cdev my_device;

#define DRIVER_NAME "dummydriver"
#define DRIVER_CLASS "MyModuleClass"

static ssize_t driver_read(struct file *File, char *user_buffer, size_t len, loff_t *offset)
{
	int to_copy, not_copied, delta;

	to_copy = min(len, buffer_pointer);

	not_copied = copy_to_user(user_buffer, buffer, to_copy);

	delta = to_copy - not_copied;

	printk(KERN_ALERT "[INFO] dev_nr - read was called!\n");
	return delta;
}

static ssize_t driver_write(struct file *File, const char *user_buffer, size_t len, loff_t *offset)
{
	int to_copy, not_copied, delta;

	to_copy = min(len, sizeof(buffer));

	not_copied = copy_from_user(buffer, user_buffer, to_copy);
	buffer_pointer = to_copy;

	delta = to_copy - not_copied;
	
	printk(KERN_ALERT "[INFO] dev_nr - write was called!\n");
	return len;
}

static int driver_open(struct inode *device_file, struct file *instance)
{
	printk("[INFO] dev_nr - open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance)
{
	printk("[INFO] dev_nr - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close,
	.write = driver_write,
	.read = driver_read
};

static int __init ModuleInit(void)
{
	//int retval;

	printk(KERN_ALERT "Hello, kernel!\n");

	if(alloc_chrdev_region(&my_device_nr, 0, 1, DRIVER_NAME) < 0)
	{
		printk("[ERROR]Device Nr. could not be allocated!\n");
		return -1;
	}
	printk("[INFO] read_write - Device Nr. Major: %d, Minor: %d was registered", my_device_nr >> 20, my_device_nr && 0xfffff);

	if((my_class = class_create(DRIVER_CLASS)) == NULL)
	{
		printk("[ERROR] Device class can not be created!\n");
		goto ClassError;
	}

	if(device_create(my_class, NULL, my_device_nr, NULL, DRIVER_NAME) == NULL)
	{
		printk("[ERROR] Can not create device file!\n");
		goto FileError;
	}

	cdev_init(&my_device, &fops);
	if (cdev_add(&my_device, my_device_nr, 1) == -1)
	{
		printk("[ERROR] Registering of device to kernel failed!\n");
		goto AddError;
	}

	return 0;
AddError:
	device_destroy(my_class, my_device_nr);
FileError:
	class_destroy(my_class);
ClassError:
	unregister_chrdev(my_device_nr, DRIVER_NAME);
	return -1;
}

static void __exit ModuleExit(void)
{
	cdev_del(&my_device);
	device_destroy(my_class, my_device_nr);
	class_destroy(my_class);
	unregister_chrdev(my_device_nr, DRIVER_NAME);
	printk(KERN_ALERT "Goodbye, kernel!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
