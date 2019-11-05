/* Name: Natthakan Euaumpon
 * ID: 6081213
 */
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR) {
    int i = 0;
    int j = 0;
    int k = 0;
    int leftData = 0;
    int rightData = 0;
    while (k < (nL+nR))
    {
        if (i<nL){
            leftData = L[i].data;
        }else{
            leftData -1;
        }
        if (i<nR){
            rightData = L[j].data;
        }else
        {
            leftData -1;
        }

        if (((i<nL) && (leftData < rightData)) || (j>=nR)){
            output[k] = L[i];
            i++;
        }else{
            output[k] = R[j];
            j++;
        }
        k++;
    }
}

void merge_sort(Entry *entries, int n) {
    if(n>1){
        int m = n/2;
        int x = 0;
        int nL = m;
        int nR = n-m;
        Entry* R = (Entry*) malloc(sizeof(Entry)*nR);
        Entry* temp = (Entry*) malloc(sizeof(Entry)*n);
        for (int i = m; i < n; i++)
        {
            R[x] = entries[i];
            x++;
        }
        Entry* L = (Entry*) malloc(sizeof(Entry)*nL);
        for (int i = 0; i < m; i++)
        {
            L[i] = entries[i];
        }
        
        merge_sort(L,nL);
        merge_sort(R,nR);
        merge(temp,L,nL,R,nR);
        for (int i = 0; i < n; i++)
        {
            entries[i] = temp[i];
        }
        free(temp);
        free(R);
        free(L);
    }
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
    int n = 0;
    scanf("%d", &n);
    Entry* input = (Entry*) malloc(sizeof(Entry)*n);
    for (int i = 0; i < n; i++)
    {
        input[i].name = (char*) malloc(sizeof(char)*MAX_NAME_LENGTH);
        scanf("%d %s", &input[i].data, input[i].name);
    }
    merge_sort(input, n);
    printf("OUTPUT:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", input[i].data, input[i].name);
    }
    for (int i = 0; i < n; i++)
    {
        free(input[i].name);
    }
    free(input);
}
