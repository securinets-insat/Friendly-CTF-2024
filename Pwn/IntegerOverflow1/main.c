#include <stdio.h>


void setup(){
	setbuf(stdout,0);
	setbuf(stdin,0);
	setbuf(stderr,0);
}
int main(){
	setup();

	int x=0;
	int y=0;
	int z=0;

	puts("this is a 10000 BC calculator");
	puts("unfortunately , it doesnt have negative numbers .");
	puts("figure out how to make them up");

	printf("give me x : ");
	scanf("%d",&x);  // reads integer from input
	if (x<=0){
		puts("Error : x should be stricly positive");
		exit(-1);
	}

	printf("give me y : ");
	scanf("%d",&y);  // reads integer from input

	if (y<=0){
		puts("Error : y should be stricly positive");
		exit(-1);
	}

	z=x+y;
	printf("     x     +      y      =      %d\n",z);

	printf("0x%08x + 0x%08x = 0x%08x",x,y,z);


	if (z<0){
		puts("positive + positive = negative ? nothing makes sense these days .");
		puts("you earned it , here is the your flag");
		system("cat flag.txt");

	}
	return 1;
}