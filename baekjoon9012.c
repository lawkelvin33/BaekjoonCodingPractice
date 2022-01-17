#include<stdio.h>

int main(){
    int T;
    scanf("%d", &T);
    int cnt;
    for(int i=0;i<T;i++){
        cnt = 0;
        char arr[51];
        scanf("%s", arr);
        for(int j=0;arr[j]!='\0';j++){
            if(arr[j]=='(')
                cnt++;
            else if(arr[j]==')')
                cnt--;
            if(cnt<0){
                printf("NO\n");
                break;
            }
        }
        if(cnt==0)
            printf("YES\n");
        else if(cnt>0)
            printf("NO\n");
    }
    return 0;
}
