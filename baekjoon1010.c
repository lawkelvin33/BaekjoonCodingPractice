#include<stdio.h>
int main(){
    int t,n,m;
    int rst,k;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        rst = 1;
        k = 1;
        scanf("%d %d", &n, &m);
        for(int j=m;j>m-n;j--){
            rst *= j;
            rst /= k++;
        }
        printf("%d\n", rst);
    }
    return 0;
}
