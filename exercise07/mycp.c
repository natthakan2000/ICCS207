#include<stdio.h>
#include<stdlib.h>
int main(int argc, char ** argv){
    FILE *reader, *copy;
    int readNum;
    int copyNum;
    char buffer[100];
    if(argc != 3){
        fprintf(stderr, "USAGE: binary-test inputfile outputfile.\n");
        exit(1);
    }
    if((reader = fopen(argv[1],"rb"))==NULL){
        fprintf(stderr, "open read file error.\n");
        exit(1);
    }
    if((copy=fopen(argv[2],"wb"))==NULL){
        fprintf(stderr, "open write file error.\n");
        exit(1);
    }
    while (feof(reader)==0){
        if((readNum=fread(buffer,1,100,reader))!=100){
            if(ferror(reader)!=0){
                fprintf(stderr, "read file error.\n");
                exit(1);
            }else if(feof(reader)!=0);
        }
        if ((copyNum=fwrite(buffer,1,readNum,copyNum))!= readNum){
            fprintf(stderr, "write file error.\n");
            exit(1);
        }
    }
    fclose(reader);
    fclose(copy);
    return 0;
}