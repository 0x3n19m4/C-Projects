#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tony_Montana");
MODULE_DESCRIPTION("Cat Module");
MODULE_VERSION("1.0.0");

static char buffer[255];
static int buffer_pointer;

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

#define MYMAJOR 90

static int __init ModuleInit(void)
{
	int retval;

	printk(KERN_ALERT "Hello, kernel!\n");
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);

	if(retval == 0)
	{
		printk("[INFO] dev_nr - in registered Device number Majors: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0)
	{
		printk("[INFO] dev_nr - in registered Device number Majors: %d, Minor: %d\n", retval>>20, retval&0xfffff);	
	}
	else
	{
		printk("[ERROR] Could not register device number!\n");
		return -1;
	}
	return 0;
}

static void __exit ModuleExit(void)
{
	unregister_chrdev(MYMAJOR, "my_dev_nr");
	printk(KERN_ALERT "Goodbye, kernel!\n");
}

module_init(ModuleInit);
module_exit(ModuleExit);
