#include<stdio.h>
#include<stdlib.h>
void prefix_sum(int *a, int *b, int *c){
    *c = *a + *b + *c;
    *b = *a + *b;
}
int main(){
    int a=3;
    int b=4;
    int c=5; 
    prefix_sum(&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}