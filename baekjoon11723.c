#include<stdio.h>
#include<string.h>

int main(){
    int set[21]={0,};
    int M;
    int tmp;
    char com[7];
    scanf("%d", &M);
    for(int i=0;i<M;i++){
        scanf("%s", com);
        if(!strcmp(com,"add")){
            scanf("%d", &tmp);
            set[tmp] = 1;
        }
        else if(!strcmp(com,"remove")){
            scanf("%d", &tmp);
            set[tmp] = 0;
        }
        else if(!strcmp(com,"check")){
            scanf("%d", &tmp);
            if(set[tmp]==1)
                printf("1\n");
            else
                printf("0\n");
        }
        else if(!strcmp(com,"toggle")){
            scanf("%d", &tmp);
            set[tmp] = !set[tmp];
        }
        else if(!strcmp(com,"all")){
            for(int i=1;i<21;i++)
                set[i] = 1;
        }
        else if(!strcmp(com,"empty")){
            for(int i=1;i<21;i++)
                set[i] = 0;
        }
    }
    return 0;
}
