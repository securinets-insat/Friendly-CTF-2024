#include <stdio.h>




void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

// your challenge starts here , dont mind the above



unsigned int size=0;

void vuln(){

	
	char buf[32];


	puts("i never doubted that you'd get here . Welcome to challenger . ");

	puts("only 1 challenge remains . Claim rank 1 on the ladder and you'll be forever remembered");

	puts("give me your current placement on the ladder .");

	scanf("%u%*c",&size);
	if (size >32 || size<=0){
		puts("if you're not top 32 , you should rethink your career mate.");
		exit(-1);
	}

	puts("what champions did you play ?");
	fgets(buf,32,stdin);
	
	printf(buf); // i trust you xD
	
	puts("very wide champion pool , i like it . ");
	if (size<=33)
		read(0,buf,size-1);
	puts("xD . so you still lack everything ? xD see you in diamond ");

}


void main(){
	setup(); // dont mind this
	vuln();
	puts("maybe you should stick to master yi !");
	exit(0);

}