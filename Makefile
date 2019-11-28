#obj-m	+= simple_module.o
obj-m	:= teamprojectko.o
teamprojectko-objs	:= arrayList.o teamproject.o

KERNEL_DIR	:= /lib/modules/$(shell uname -r)/build
PWD	:= $(shell pwd)

default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
