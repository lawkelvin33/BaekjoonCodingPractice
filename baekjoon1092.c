#include<stdio.h>
#include<stdlib.h>

int static descending(const void*, const void*);


int main(){
    int tim = 0;
    int mov = 1;
    int N, M;
    int remBox;
    int* crane;
    int* box;
    scanf("%d", &N);
    crane = (int*)malloc(sizeof(int)*N);
    for(int i=0;i<N;i++)
        scanf("%d", &crane[i]);
    scanf("%d", &M);
    box = (int*)malloc(sizeof(int)*M);
    for(int i=0;i<M;i++)
        scanf("%d", &box[i]);
    remBox = M;
    qsort(crane, N, sizeof(int), descending); //sort crane by capacity
    qsort(box, M, sizeof(int), descending); //sort box by weight
    while(mov>0 && remBox>0){//if # of boxes moved is zero, return -1
        mov = 0;
        for(int i=0;i<N;i++){
            for(int j=tim;j<M;j++){ //***********this part***************
                if(crane[i]>=box[j] && box[j]!=0){ 
                    remBox -= 1; //subtract one from remaining boxes
                    box[j] = 0; // remove box
                    mov += 1; //an additional box moved
                    break; // break out from inner for
                }
            }
        }
        tim += 1;
    }
    if(mov==0)
        printf("-1");
    else
        printf("%d", tim);
    free(crane);
    free(box);
    
    return 0;
}

int static descending (const void* first, const void* second){
    if (*(int*)first < *(int*)second)
        return 1;
    else if (*(int*)first > *(int*)second)
        return -1;
    else
        return 0;
}
