#include<stdio.h>
#include<string.h>

typedef struct{
    int arr[20000];
    int front;
    int back;
}deque;

void push_front(deque* d, int n){
    d->arr[++d->front] = n;
}

void push_back(deque* d, int n){
    d->arr[--d->back] = n;
}

void pop_front(deque* d){
    if(d->back<=d->front)
        printf("%d\n", d->arr[d->front--]);
    else
        printf("-1\n");
}

void pop_back(deque* d){
    if(d->back<=d->front)
        printf("%d\n", d->arr[d->back++]);
    else
        printf("-1\n");
}

void size(deque* d){
    printf("%d\n", d->front-d->back+1);
}

void empty(deque* d){
    if(d->front>=d->back)
        printf("0\n");
    else
        printf("1\n");
}

void front(deque* d){
    if(d->front>=d->back)
        printf("%d\n", d->arr[d->front]);
    else
        printf("-1\n");
}

void back(deque* d){
    if(d->front>=d->back)
        printf("%d\n", d->arr[d->back]);
    else
        printf("-1\n");
}

int main(){
    int N;
    scanf("%d", &N);
    deque de;
    de.front = 9999;
    de.back = 10000;
    char cmd[11];
    int num;
    for(int i=0;i<N;i++){
        scanf("%s", cmd);
        if(!strcmp(cmd,"push_front")){
            scanf("%d", &num);
            push_front(&de, num);
        }
        else if(!strcmp(cmd,"push_back")){
            scanf("%d", &num);
            push_back(&de, num);
        }
        else if(!strcmp(cmd,"pop_front")){
            pop_front(&de);
        }
        else if(!strcmp(cmd,"pop_back")){
            pop_back(&de);
        }
        else if(!strcmp(cmd,"size")){
            size(&de);
        }
        else if(!strcmp(cmd,"empty")){
            empty(&de);
        }
        else if(!strcmp(cmd,"front")){
            front(&de);
        }
        else if(!strcmp(cmd,"back")){
            back(&de);
        }
    }
    return 0;
}
