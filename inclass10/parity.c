#include<stdio.h>
#include<stdlib.h>

int add(int x, int y){
	while (y != 0) {
		int carry = x & y;   
		x = x ^ y;  
		y = carry << 1; 
	} 
    return x; 
}

int parity_check(int x){
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		if ((x & 1u)== 1)
		{ 
			count=add(count,1);
		}
		x = x >> 1u;

		
	}
	return count & 1u;
}
int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n",parity_check(num));
}