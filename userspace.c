#include <stdio.h> 
#include<stdlib.h>
#include<fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdint.h>
#include <sys/stat.h>
#include<sys/ioctl.h>




#define NUMBER 'A'
#define ADC_1 _IOW (NUMBER, 0, int32_t*)
#define ADC_2 _IOW (NUMBER, 1, int32_t*)
#define ADC_3 _IOW (NUMBER, 2, int32_t*)



int main()
{
	
	while(1)
	{
	int fd=open("/dev/adc-dev",O_RDWR);		// opening file
	uint16_t data;
	
	uint32_t channel, allignment,conv_mode,temp = 1;
	
	
	if(fd<0)
	{
		printf("not able to read file\n");
		return 0;
		
	}
start:	printf ( "select a channel from 0 to 7\n");
	scanf ( "%d",&channel);
	
	if(channel >= 0 && channel <= 7)
	{	
		ioctl(fd, ADC_1, (uint32_t*) &channel);	        //transfering channel number to kernel by using ioctl system call
			
	}
	
	else
	 {
		printf("please enter a correct channel number\n");
		goto start;
	 }
		
	
	printf ("Please enter allignment you want // 0 for right //and //1 for left//\n");
	scanf ("%d",&allignment);
	
	if(allignment >= 0 && allignment <=1)
	{	
		ioctl(fd, ADC_2, (uint32_t*) &allignment);	//transfering allignment type to kernel by using ioctl system call
		
	}
	
	else 
	{
		printf("wrong allignment choosen\n");
		goto start;
	}
	
	printf("please enter type of conversion mode you want, 0 for single shot and 1 for continue\n");
	scanf("%d",&conv_mode);
	
	if(conv_mode >=0 && conv_mode <=1)
	{	
		ioctl(fd, ADC_2, (uint32_t*) &conv_mode); 	//transfering conversion mode to kernel by using ioctl system call
		
	}
	else 
	{
		printf("wrong data entered\n");
		goto start;
	}
	
	read(fd, &data, 2);	// This call will open read function in file operation and will return ADC data in user space
	
	printf("Output of ADC is binary %0.4x\n", data);
	
	close (fd);
	
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
