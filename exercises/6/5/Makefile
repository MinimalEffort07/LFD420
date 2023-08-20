obj-m += linked_list.o

make :
	+$(MAKE) -C /lib/modules/6.4.0/build M="$(PWD)" modules

clean : 
	rm -rf *.o *.ko *.mod* Module.symvers modules.order
