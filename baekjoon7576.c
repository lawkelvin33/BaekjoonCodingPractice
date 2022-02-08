#include<stdio.h>
//bfs using Queue

int main(){
    int M,N;
    scanf("%d %d", &N, &M);
    int arr[M][N];
    int queue[M*N][2];
    int front=0, rear=-1;
    int total=0;
    int tim=0;
    int f=0,r=-1;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            scanf("%d", &arr[i][j]);
            if(arr[i][j]==1){
                queue[++rear][0] = i;
                queue[rear][1] = j;
                total++;
            }
            else if(arr[i][j]==0)
                total++;
        }
    }
    while(rear>r && rear<total-1){//rear에 변화가 없을 경우 or rear가 total-1 일 경우
        f = front;//본래의 front와 rear값 저장
        r = rear;
        for(int i=f;i<=r;i++){
            arr[queue[i][0]][queue[i][1]] = 1;
            if(queue[i][0]>0){//위
                if(arr[queue[i][0]-1][queue[i][1]]==0){//0일 경우에 queue의 rear에 넣어줌
                    arr[queue[i][0]-1][queue[i][1]] = 2;//2로 중복 방지
                    queue[++rear][0] = queue[i][0]-1;//y-1
                    queue[rear][1] = queue[i][1];//x
                }
            }
            if(queue[i][0]<M-1){//아래
                if(arr[queue[i][0]+1][queue[i][1]]==0){//0일 경우에 queue의 rear에 넣어줌
                    arr[queue[i][0]+1][queue[i][1]] = 2;//2로 중복 방지
                    queue[++rear][0] = queue[i][0]+1;//y+1
                    queue[rear][1] = queue[i][1];//x
                }
            }
            if(queue[i][1]>0){//왼쪽
                if(arr[queue[i][0]][queue[i][1]-1]==0){//0일 경우에 queue의 rear에 넣어줌
                    arr[queue[i][0]][queue[i][1]-1] = 2;//2로 중복 방지
                    queue[++rear][0] = queue[i][0];//y
                    queue[rear][1] = queue[i][1]-1;//x-1
                }
            }
            if(queue[i][1]<N-1){//오른쪽
                if(arr[queue[i][0]][queue[i][1]+1]==0){//0일 경우에 queue의 rear에 넣어줌
                    arr[queue[i][0]][queue[i][1]+1] = 2;//2로 중복 방지
                    queue[++rear][0] = queue[i][0];//y
                    queue[rear][1] = queue[i][1]+1;//x+1
                }
            }
            
        }
        /*printf("\n"); //// code for visualization
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("rear: %d, r: %d, front: %d, f: %d, total: %d \n\n", rear, r,front,f, total);
        */
        front = r+1;
        tim++;
        
        
    }
    if(rear==total-1)//모두 익었을 경우
        printf("%d", tim);
    else//모두 익지 못한 경우
        printf("-1");
    
    return 0;
}
