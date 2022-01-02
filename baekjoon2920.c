#include <stdio.h>

int main()
{
    int num[8];
    int result[2] = {1,1}; // 0 - ascending 1 - descending 2 - mixed
    for(int i=0;i<8;i++)
        scanf("%d", &num[i]);
    
    if(num[0]!=1 && num[0]!=8){
        printf("mixed");
        return 0;
    }
        
    for(int i=1;i<8;i++){
        if(num[i] == num[i-1] - 1) //descending
            result[0] = 0;
        else if(num[i] == num[i-1] + 1) // ascending
            result[1] = 0;
        else{
            printf("mixed");
            return 0;
        }
    }
    if(result[0]&&!result[1])
        printf("ascending");
    else if(!result[0]&&result[1])
        printf("descending");
    else
        printf("mixed");
        
    return 0;
}
