#include<stdio.h>
#include"md5.h"

void main(int argc,char *argv[]){
	MD5_u32plus sandy = 1234;
	MD5_final(sandy);
	printf("%u\n",sandy);

}
