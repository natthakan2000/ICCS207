#include<stdio.h>
#include<stdlib.h>
void main()
    {
    int num, i, j, binaryNum=0,decimalNum;
    printf("\n\nConvert Decimal to Binary:\n ");
    printf("-------------------------\n");
    printf("Enter a number you want to convert : ");
    scanf("%d",&num);
    decimalNum=num;
    i=1;
     for(j=num;j>0;j=j/2)
      {
       binaryNum=binaryNum+(num%2)*i;
       i=i*10;
       num=num/2;
      }
    printf("\nThe Binary of %d is %d.\n\n",decimalNum,binaryNum);
}