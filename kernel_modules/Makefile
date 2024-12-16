MODULE_NAME := kernel_module

KERNEL_DIR := /lib/modules/$(shell uname -r)/build

all:
	$(make) -C $(KERNEL_DIR) M=$(PWD)
	sudo insmod $(MODULE_NAME).ko
	sudo rmmod $(MODULE_NAME).ko
	dmesg | tail -n 2
