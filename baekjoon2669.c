#include <stdio.h>

int main(){
    int coor[100][100] = {0}; //*************************************
    int squa[4][4];
    int sum = 0;
   
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            scanf("%d",&squa[i][j]);
    }
    
    
    for(int i=0;i<4;i++){
        for(int j=squa[i][0];j<squa[i][2];j++){
            for(int k=squa[i][1];k<squa[i][3];k++){
                if(coor[j][k]==0){
                    sum++;
                    coor[j][k] = 1;
                }
            }
        }    
    }
    printf("%d", sum);
    
    return 0;
}
