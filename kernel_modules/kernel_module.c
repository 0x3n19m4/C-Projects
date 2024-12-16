#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tony_Montana");
MODULE_DESCRIPTION("Cat Module");
MODULE_VERSION("1.0.0");

static int __init lkm_init_module(void)
{
	printk(KERN_INFO "Cats module loaded!\n");
	return 0;
}

static void __exit lkm_exit_module(void)
{
	printk(KERN_INFO "Cats module unloaded!\n");
}

module_init(lkm_init_module);
module_exit(lkm_init_module);
