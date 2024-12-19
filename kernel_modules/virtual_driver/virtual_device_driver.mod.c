#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_MITIGATION_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x69ecd755, "class_create" },
	{ 0xd6ea434b, "device_create" },
	{ 0x1dffce37, "cdev_init" },
	{ 0xceb14aed, "cdev_add" },
	{ 0x1d4e34ee, "device_destroy" },
	{ 0x7b3d0365, "class_destroy" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xf81443f1, "cdev_del" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x92997ed8, "_printk" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x29fff2aa, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "C33F4E37CF7A100B3799725");
