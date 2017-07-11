# Calculate-USB-Free-Space

Shortly the program is calculate and show you inserted USB device free memory.
I used statfs function to examine it.

``` C++
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
```

**free_space** tell you how much free space in your given storage.


To compile : 
  
    gcc -o main main.c
  
To run     : 

    ./main ..usb device path.. //like /media/USBDEVICE

Have a nice coding...
