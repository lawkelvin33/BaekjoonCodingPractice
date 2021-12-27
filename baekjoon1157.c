#include<stdio.h>

int main(){
    char arr[1000000];
    int cnt[26];
    int tmp;
    int max=0;
    int maxChar=0;
    int tie = 0;
    scanf("%s", arr);
    for(int i=0;i<26;i++){
        cnt[i] = 0;
    }
    
    //65 = A, 97 = a
    for(int i=0;arr[i]!='\0';i++){
        tmp = (arr[i]-65)%32;
        cnt[tmp]++;
    }
    for(int i=0;i<26;i++){
        if(cnt[i]>max){
            max = cnt[i];
            maxChar = i;
            tie = 0;
        }
        else if(cnt[i]==max){
            tie = 1;
        }
    }
    if(tie==1)
        printf("?");
    else
        printf("%c", maxChar+65);
    
    
    return 0;
}
