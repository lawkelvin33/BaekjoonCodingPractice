#include<stdio.h>
#include<string.h>
//():0 []:1 

int main(){
    int stack[105] = {-1,};
    int top = 0;
    char string[105];
    
    
    
    while(1){
        fgets(string,105,stdin);
        if(string[0]=='.'&&string[1]=='\n')
            return 0;
        for(int i=0;string[i]!='\0';i++){
            if(string[i]=='\n'){
                if(top==0)
                    printf("yes\n");
                else
                    printf("no\n");
                top=0;
                break;
            }
            else if(string[i]=='(')
                stack[top++] = 0;
            else if(string[i]=='[')
                stack[top++] = 1;
            else if(string[i]==')'){
                if(top>0){
                    if(stack[top-1]==0)
                        top--;
                    else{
                        printf("no\n");
                        top = 0;
                        break;
                    }
                }
                else{
                    printf("no\n");
                    top = 0;
                    break;
                }
            }
            else if(string[i]==']'){
                if(top>0){
                    if(stack[top-1]==1)
                        top--;
                    else{
                        printf("no\n");
                        top = 0;
                        break;
                    }
                }
                else{
                    printf("no\n");
                    top = 0;
                    break;
                }
            }
        }
    }
    return 0;
}
