#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double compute_det(int **a, int n) {
  if (n==1)
  {
    return a[0][0];
  }else
  {
    
  }
  return 0.0;
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  int input = 0;
  scanf("%d", &input);
  int** m = (int**) malloc(sizeof(int*)*m);
  for (int i = 0; i < input; i++)
  {
    m[i] = (int*) malloc(sizeof(int)*m);
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < m; j++)
    {
      scanf("%d",&m[i][j]);
    }
    
  }
  
}
