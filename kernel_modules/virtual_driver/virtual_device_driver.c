#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/semaphore.h>
#include <asm/uaccess.h>

struct fake_device
{
	char data[100];
	struct semaphore sem;
} virtual_device;

struct cdev *mcdev;
int numbers;
int ret;

dev_t dev_num;

#define DEVICE_NAME "fakedevice"

static int driver_entry(void)
{
	ret = alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
	if (ret < 0)
	{
		printk(KERN_ALERT "[ERROR] Failed to allocate a number");
		return ret;
	}
	number = MAJOR(dev_num);
	printk(KERN_INFO "[INFO] number is &d, number");
	printk(KERN_INFO "[INFO] \tuce \"mknod /dev/%s c %d 0\" for device file", DEVICE_NAME, number);

	mcdev = cdev_alloc();
	mcdev->ops = &fops;
	mcdev->owner = THIS_MODULE;

	ret = cdev_add(mcdev, dev_num, 1);
	if (ret < 0)
	{
		printk(KERN_ALERT "[ERROR] unable to add cdev to kernel");
		return ret;
	}

	sema_init(&virtual_device.sem, 1);

	return 0;
}

static int driver_exit(void)
{
	cdev_del(mcdev);
	unregister_chrdev_region(dev_num, 1);
	printk(KERNEL_ALERT "[INFO] unloaded module");
}
