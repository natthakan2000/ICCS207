#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[ ] ){
int numSpace = atoi(argv[2]);
char string[10000];
char character;
int count=0;
char prefixD[]="-d";
char prefixE[]="-e";
if(strcmp(prefixD,argv[1]) == 0){
	while((character=getchar())!= '\n'){
		string[count]= character;
		++count;
	}
	for(int i = 0; i < count;i++){
		if(string[i]=='\t'){
		for(int j = 0; j < numSpace;j++){
			printf(" ");
			} 
		}
		else{ printf("%c",string[i]);
		}
	}
	printf("\n");
 }
else{
	int spaceCounter = 0;
	while((character=getchar()) != '\n'){
		string[count]= character;
		++count;}
	for(int i = 0; i < count;i++){
		if(string[i]!=' '){
			if((spaceCounter < numSpace)&&(spaceCounter>0)){
                    for(int j=0;j<spaceCounter;j++){
                        printf(" ");
                    }
            }
			spaceCounter = 0;
			printf("%c",string[i]);
		}else{
			spaceCounter++;
			if(spaceCounter==numSpace){
				printf("%c",'\t');
				spaceCounter=0;
				}
			}
	} 
}
printf("\n");
return 0;
}
