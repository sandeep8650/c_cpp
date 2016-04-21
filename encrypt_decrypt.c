// encrypt or decrypt file
#include<stdio.h>
#include<stdlib.h>
#define ENC(m,k) ((m << ((k%7)+1)) | (m >> (8 - (k%7)-1)))
#define DEC(m,k) ((m >> ((k%7)+1)) | (m << (8 - (k%7)-1)))
void main(int argc,char *file[]){
		int byte,ebyte;
		long int key;
		char *pswd,op;
		FILE *fsource, *ftarget;
		if(argc<4){
			printf("Insufficient commandline arguments\n");
			printf("USE:\nFor Encryption %s -e source_file_name target_file_name\nFor Decryption %s -d source_file_name target_file_name\n",file[0],file[0]);
			exit(1);
		}
		fsource=fopen(file[2],"rb");
		if(fsource==NULL){
			printf("Cannot open source file\n");
			exit(2);
		}
		ftarget=fopen(file[3],"wb");
		if(ftarget==NULL){
			printf("Cannot open target file\n");
			exit(3);
		}
		switch(file[1][1]){
			case 'e':
				printf("Enter password to encrypt(alphanumeric and max passwordlength 10): ");
				scanf("%s",pswd);
				key = strtol(pswd,NULL,36);
				printf("Encrypting.........\n");
				while(1){
					byte=fgetc(fsource); //read in binary form(byte)
					if(byte==EOF){
						break;
					}
					else
						ebyte = ENC(byte,key);
						fputc(ebyte,ftarget);
				}
				printf("Encryption complete\n");
				break;
			case 'd':
				printf("Enter password to decrypt: ");
				scanf("%s",pswd);
				key = strtol(pswd,NULL,36);
				printf("Decrypting.........\n");
				while(1){
					byte=fgetc(fsource); //read in binary form(byte)
					if(byte==EOF){
						break;
					}
					else
						ebyte = DEC(byte,key);
						fputc(ebyte,ftarget);
				}
				printf("Decryption complete\n");
				break;
			default:
				printf("Use correct option: -d or -e\n");
				exit(4);
		}
		fclose(fsource);
		fclose(ftarget);
}
