#include<stdio.h>
#include<math.h>
int main(){
    int T,x,y;
    double tmp;
    int n,d,energy;
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d", &x, &y);
        d = y - x;
        n = (int)sqrt((double)d);
        if(d==n*n)
            energy = 2*n-1;
        else{
            if(d>n*n+n)
                energy = 2*n+1;
            else
                energy = 2*n;
        }
        printf("%d\n", energy);
        
    }
    return 0;
}

/*여러가지 시행착오
<attempt1>
k = f(k-1,d) ==> dp problem(2-d array) ==> 이거 아님


inference)
time=2sec 
space=512mb==>probably dp==>기각 why??=>다 저장하려면 512mb초과(2048mb+@)

<attempt2>
inference)

n(n+1)/2 = (n^2 + n)/2

1~n~1 : n(n+1)/2 + (n-1)n/2 = n^2
1~n+1~1 : (n+1)^2 = n^2 + 2n + 1
total::> 2n-1

곧, 2n + 1 의 차이 발생

n = sqrt(d)
if(d == n*n)//완벽히 1~n~1이 성립할때
energy = 2n-1
else
energy = 2n

(test1)
d = 1
--
n = 1
d == n*n
energy = 2*1-1 = 1

(test2)
d = 2
--
n = 1
d != 1*1
energy = 2*1

(test3)WRONG!
d = 3
--
n = 1
d != 1*1
energy = 2*1
WRONG! answer = 3
(test4)
d = 4
n = 2
d == 2*2
energy = 4-1 = 3
(test5)
d = 5
n = 2
d != 2*2
energy = 4
(test6)==>insight earned=> need to separate odd, even cases(energy)
d = 8
n = 2
d != 2*2
energy = 4
WRONG!! (correct answer)5
12321 = 9 // energy = 5
121 = 4 // energy = 3

1211 = 5
1221 = 6

12221 = 8

-----------------conclusion
n = sqrt(d)
if(d==n*n){
    energy = 2n-1
}
else{
    if(d>n*n+n)     //1~nn~1==>n*n + n
        energy = 2n+1
    else
        energy = 2n
}

(test1)
d = 3
n = 1

*/
