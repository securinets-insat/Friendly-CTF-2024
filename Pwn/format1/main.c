#include <stdio.h>



void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	return;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////

// your challenge starts here , dont mind the above


void vuln(){

	char flag[0x50];
	int fd=open("flag.txt",0);
	read(fd,flag,0x50);
	close(fd);

	char buf[0x40];


	puts("you didnt escape master yet ? ");

	puts("give me a recap of your games .");
	
	fgets(buf,0x40,stdin);    
	
	printf(buf); // i trust you xD


}


void main(){
	setup(); // dont mind this
	vuln();
	puts("maybe you should stick to master yi !");
	exit(0);

}