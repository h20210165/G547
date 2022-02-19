obj-m := assignement_1_ADC.o
all:
	make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) modules
	
clean:
	make make -C /lib/modules/$(shell uname -r)/build/ M=$(PWD) clean

