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
	puts("");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// your challenge starts here , dont mind the above

void win(){

	char *flag=malloc(0x50);
	int fd=open("flag.txt",0);
	read(fd,flag,0x50);
	puts(flag);
	close(fd);

}

unsigned int size=0;

void vuln(){

	
	char buf[32];


	puts("you finally got to grandmaster ! I've waited for thee .");

	puts("no more easy games now .");

	puts("first tell me how many games it took you to get to gm . ");

	scanf("%u%*c",&size);
	if (size >32){
		puts("at this rate you'll need another 10000 to get challenger !! ");
		exit(-1);
	}

	puts("give me a brief recap of what you learned to get here !");
	fgets(buf,32,stdin);    
	
	printf(buf); // i trust you xD
	
	puts("not bad not bad . now tell me what you still lack to get challenger");
	
	read(0,buf,size);
	
	puts("xD . so you still lack everything ? xD see you in diamond ");

}


void main(){
	setup(); // dont mind this
	vuln();
	puts("maybe you should stick to master yi !");
	exit(0);

}