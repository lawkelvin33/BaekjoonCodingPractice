#include<stdio.h>
#include<string.h>

typedef struct{
    int arr[10000];
    int top;
}stack;

stack stk;


void push(stack* s, int num){
    s->top += 1;
    s->arr[s->top] = num;
}

void pop(stack* s){
    if(s->top>=0){
        s->top -= 1;
        printf("%d\n", s->arr[s->top+1]);
    }
    else
        printf("%d\n", -1);
}

void size(stack* s){
    printf("%d\n", s->top + 1); 
}

void empty(stack* s){
    if(s->top == -1)
        printf("1\n");
    else
        printf("0\n");
}

void top(stack* s){
    if(s->top>=0)
        printf("%d\n", s->arr[s->top]);
    else
        printf("-1\n");
}

int main(){
    int n, num;
    char cmd[6];
    stack stk;
    stk.top = -1;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%s", cmd);
   
        if(!strcmp(cmd,"push")){
            scanf("%d\n", &num);
            push(&stk,num);
        }
        else if(!strcmp(cmd,"pop")){
            pop(&stk);
        }
        else if(!strcmp(cmd,"size")){
            size(&stk);
        }
        else if(!strcmp(cmd,"empty")){
            empty(&stk);
        }
        else if(!strcmp(cmd,"top")){
            top(&stk);
        }
        
    }
    return 0;
    
}
