#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    int character;
    int array[26];
    for (int i=0;i<26;i++) 
        array[i] = 0;
    while ((character = getchar())!=EOF){
        if (isalpha(character)){
            if (islower(character)){
                int temp = array[character-97];
                temp+=1;
                array[character-97] = temp;
            }else{
                character += 32;
                int temp = array[character-97];
                temp += 1;
                array[character-97] = temp;
            }
        }
    }
    int max = 0;
    for(int y = 0; y < 26; y++){
            if (max < array[y]){
                max = array[y];
            }
    }
    for (int i = max; i >= 0; i--) {
        for (int a = 0; a < 26; ++a) {
            if (array[a] > i) {
                printf("*"); 
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int z = 0; z <26; z++){
        printf("%c", z+97);
    }
    return 0;
}