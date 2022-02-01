#include<stdio.h>
#include<string.h>

typedef struct{
  int arr[10000];
  int front;
  int back;
} queue;

void push(queue * q, int n){
  q->arr[++q->back] = n;
}

void pop(queue * q){
  if(q->back >= q->front)
    printf("%d\n", q->arr[q->front++]);
  else
    printf("-1\n");
}

void size(queue * q){
  printf("%d\n", q->back - q->front + 1);
}

void empty(queue * q){
  if(q->back >= q->front)
    printf("0\n");
  else
    printf("1\n");
}

void front(queue * q){
  if(q->back >= q->front)
    printf("%d\n", q->arr[q->front]);
  else
    printf("-1\n");
}

void back(queue * q){
  if(q->back >= q->front)
    printf("%d\n", q->arr[q->back]);
  else
    printf("-1\n");
}


int main(){
  int N;
  queue qu;
  scanf("%d", &N);
  qu.back = -1;
  qu.front = 0;
  int num;
  char cmd[6];
  for(int i = 0; i < N; i++){
      scanf("%s", cmd);
    if(!strcmp(cmd, "push")){
	    scanf("%d", &num);
	    push(&qu,num);
	}
    else if(!strcmp(cmd, "pop"))
	    pop(&qu);
    else if(!strcmp(cmd, "size"))
	    size(&qu);
    else if(!strcmp(cmd, "empty"))
	    empty(&qu);
    else if (!strcmp(cmd, "front"))
	    front(&qu);
    else if (!strcmp(cmd, "back"))
	    back(&qu);
    }
    return 0;
}
