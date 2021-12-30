#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int* result;
    int T;
    float x1,y1,x2,y2;
    int N;
    float cx,cy,r;
    scanf("%d", &T);
    result = (int*)malloc(sizeof(int)*T);
    for(int i=0;i<T;i++){
        result[i] = 0;
        scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
        scanf("%d", &N);
        for(int j=0;j<N;j++){
            scanf("%f %f %f", &cx,&cy,&r);
            if((sqrt(pow(cx-x1,2)+pow(cy-y1,2))-r)*(sqrt(pow(cx-x2,2)+pow(cy-y2,2))-r)<0)
                result[i]++;
        }
                

    }
    for(int i=0;i<T;i++)
        printf("%d\n", result[i]);

    return 0;
}

