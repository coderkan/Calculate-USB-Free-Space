/**
 * This program compiled gcc. 
 * To compile : gcc -o main  main.c
 * To run     : ./main ..usb storage path...// like /media/USBDEVICE
 * */

#include <stdio.h>
#include <sys/vfs.h> // or <sys/statfs.h> 

int main(int argc, char **argv)
{
	struct statfs fsb;
	if(argc <= 1){
		printf("Please Enter a USB device path\n");
		return -1;
	}
	// argv[1] is a path that connected USB storage device.
	long long free_space;
	if(statfs(argv[1],&fsb) == 0 ){
		free_space = ((long long)fsb.f_bfree*(long long)fsb.f_bsize);
		free_space = free_space/(long long)(1024*1024); // For convert MB
		printf("USB Device has %lld MB Free Space...\n",free_space);	
	}else{
		printf("Can't Calculate USB Free Storage\n");
	}	
	return 0;
}

