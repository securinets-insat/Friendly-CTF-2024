#include <stdio.h>



void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	return;
}

void print_stack(long * ptr , int num){
	puts("");
	int i=0;
	printf("\033[1;31m%-20s   %-20s   %-20s\n","addresses","value1","value2");
	for (;i<num;i++){
		printf("\033[1;32m0x%016llx \033[1;37m| 0x%016llx | 0x%016llx >> ",ptr+(i*2),*(ptr+(i*2)),*(ptr+(i*2)+1));	
		int j=0;
		char * ptr_str=ptr+i*2;
		for (;j<0x10;j++){
			if (ptr_str[0x10*i+j]>0x20 && ptr_str[0x10*i+j]<0x7f) {
				printf("%c",ptr_str[0x10*i+j]);
			}
			else
				printf(".");
		}
		printf("\n");
	}
	printf("\033[1;37m");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// your challenge starts here , dont mind the above

void func(){

	char *flag=malloc(0x50);
	int fd=open("flag.txt",0);
	read(fd,flag,0x50);
	close(fd);

}


void vuln(){

	
	char buf[32];

	print_stack(buf,5);

	puts("master adventures 2 xD");	

	puts("give me a recap of your games .");
	
	fgets(buf,32,stdin);    
	
	printf(buf); // i trust you xD

	print_stack(buf,5);


}


void main(){
	setup(); // dont mind this
	func();
	vuln();
	puts("maybe you should stick to master yi !");
	exit(0);

}