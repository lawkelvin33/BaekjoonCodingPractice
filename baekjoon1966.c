#include<stdio.h>

int main(){
    int N,M,T;
    int qu[10000];
    int order[10000];
    int cnt;
    int e,c,f;
    int check;
    scanf("%d", &T);
    for(int t=0;t<T;t++){
        scanf("%d %d", &N, &M);
        for(int i=0;i<N;i++){
            scanf("%d", &qu[i]);
            order[i] = i;
        }
        cnt = 0;
        f = 0;
        e = N-1;
        while(1){
            check = 1;
            for(c=f+1;c<=e;c++){
                if(qu[c]>qu[f]){//맨앞수보다 더 큰수가 존재하면
                    qu[++e] = qu[f];
                    order[e] = order[f++];
                    check = 0;
                    break;
                }
            }
            if(check == 1){//맨앞수보다 더 큰수가 없으면
                ++cnt;
                f++;
                if(order[f-1]==M){
                    printf("%d\n", cnt);
                    break;
                }
            }
        }
    }
    return 0;
}
