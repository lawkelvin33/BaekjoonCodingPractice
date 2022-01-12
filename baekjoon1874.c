#include<stdio.h>
#include<stdlib.h>

int main(){
    
    int N;
    scanf("%d", &N);
    int* stack;
    stack = (int*)malloc(sizeof(int)*(N+1));
    int tmp;
    char* order;
    order = (char*)malloc(sizeof(char)*(2*N));
    int top = 0;
    int nxt = 1;
    int ord=0;
    for(int i=0;i<N+1;i++)
        stack[i] = 0;
    
    for(int i=1;i<N+1;i++){
        scanf("%d", &tmp);
        if(stack[top]>tmp){ // 못만듦
            printf("NO");
            return 0;
        }
        else if(stack[top]<tmp){
            while(stack[top]!=tmp){
                if(nxt>N){
                    printf("NO");
                    return 0;
                }
                stack[++top] = nxt++; //push
                order[ord++] = '+';
            }
            if(stack[top]==tmp){
                stack[top--] = 0; //pop
                order[ord++] = '-';
            }
            
        }
        else{
            stack[top--] = 0; //pop
            order[ord++] = '-';
        }
    }
    for(int i=0;i<ord;i++)
        printf("%c\n", order[i]);
        
    free(stack);
    free(order);
    
    return 0;
}
