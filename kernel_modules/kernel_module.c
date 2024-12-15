#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tony_Montana");
MODULE_DESCRIPTION("Cat Module");
MODULE_VERSION("1.0.0");

int init_module()
{
	printk(KERN_INFO "Cats module loaded!\n");
	return 0;
}

void cleanup_module()
{
	printk(KERN_INFO "Cats module unloaded!\n");
}
