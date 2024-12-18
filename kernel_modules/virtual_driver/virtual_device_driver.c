#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tony_Montana");
MODULE_DESCRIPTION("Cat Module");
MODULE_VERSION("1.0.0");

static int driver_open(struct inode *device_file, struct file *instance)
{
	printk("dev_nr - open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance)
{
	printk("dev_nr - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 90

static int __init ModuleInit(void)
{
	int retval;

	printk(KERN_ALERT "Hello, kernel!\n");
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);

	if(retval == 0)
	{
		printk("dev_nr - in registered Device number Majors: %d, Minor: %d\n", MYMAJOR, 0);
	}
	else if(retval > 0)
	{
		printk("dev_nr - in registered Device number Majors: %d, Minor: %d\n", retval>>20, retval&0xfffff);	
	}
	else
	{
		printk("Could not register device number!\n");
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
