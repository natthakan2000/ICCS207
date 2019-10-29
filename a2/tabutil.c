#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[ ] ){
int numspace = atoi(argv[2]);
char string[1000000000];
char character;
int count=0;
char prefixD[]="-d";
char prefixE[]="-e";
if(strcmp(prefixD,argv[1]) == 0){
	while((character=getchar())!= '\n'){
		string[count]= character;
		++count;}

	for(int i =0; i< count;i++){
		if(string[i]=='\t'){
		for(int j =0; j< numspace;j++){
			printf(" ");} }
		else{ printf("%c",string[i]);}}
printf("\n");
 }
else{
int count_space=0;
while((character=getchar())!= '\n'){
	string[count]= character;
	++count;}

for(int i =0; i<count;i++){
	if(string[i]!=' '){
		printf("%c",string[i]);}
	else{
		count_space++;
		if(count_space==numspace){
			printf("%c",'\t');
			count_space=0;}	}
	} 
}
printf("\n");
return 0;
}
