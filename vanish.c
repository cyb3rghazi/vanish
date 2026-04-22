#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]){

    if(argc < 2){
            printf("USAGE: %s [filepath]\n", argv[0]);
            return 1;
    }

    FILE *fp = fopen(argv[1], "rb+");

    if(fp!=NULL){
            printf("[+] File Loaded Successfully...\n");
            printf("[*] Searching for the end of file...\n");
            fseek(fp, 0, SEEK_END);

            printf("[*] Finding size of the %s", argv[1]);
            long size = ftell(fp);
            printf("\nFile size: %ld\n Bytes", size);
            
            printf("[*] Going back to the start of the file...\n");
            rewind(fp);

            printf("[*] Overwriting the file with 0x00s\n");
            for(long i=0; i<size; i++){
                    fputc(0x00, fp);
            }fflush(fp);

            printf("[*] Going back to the start of the file...\n");
            rewind(fp);
            
            printf("[*] Overwriting the file with 0xFFs\n");
            for(long i=0; i<size; i++){
                    fputc(0xFF, fp);
                    
            }fflush(fp);
            
            printf("[*] Forcing the system to overwrite....\n");
            fsync(fileno(fp));

            printf("[*] Closing the File...\n");
            fclose(fp);
            remove(argv[1]);
            
            printf("\n\n[+] Evidence Successfully Distroyed!!!\n");
        }else{
            printf("[-] File not found or you don't have the permissions...\n");
    }

    return 0;
}