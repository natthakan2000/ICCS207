#include <stdio.h>
#include <stdlib.h> 

int get(unsigned char *a, int idx){
    unsigned char store = *a >> idx ;
    return (int) store & 1u ;
}

void set(unsigned char *a, int idx, int val){
    unsigned char shift = 1u << idx;
    int check = get(a,idx);
    if(check != val){
        *a = *a ^ shift;
    }
}

int main(){
unsigned char *a = malloc(sizeof(char));
int num;
scanf("%d", &num);
*a = num;
printf("%d\n",get(a,5));
set(a,5,1);
printf("%d\n",get(a,5));
return 0;
}