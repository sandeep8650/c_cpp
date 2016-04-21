//copy the file
// ./copy source_file target_file_name

#include<stdio.h>
#include<stdlib.h>

void main(int argc,char *file[]){
		int byte;
		FILE *fsource, *ftarget;
		if(argc<3){
			printf("Insufficient commandline arguments\n");
			exit(1);
		}
		fsource=fopen(file[1],"rb");
		if(fsource==NULL){
			printf("Cannot open source file\n");
			exit(2);
		}
		ftarget=fopen(file[2],"wb");
		if(ftarget==NULL){
			printf("Cannot open target file\n");
			exit(3);
		}
		while(1){
			byte=fgetc(fsource);
			if(byte==EOF){
				break;
			}
			else
				fputc(byte,ftarget);
		}
		fclose(fsource);
		fclose(ftarget);
}
