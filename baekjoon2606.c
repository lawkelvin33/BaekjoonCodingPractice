//graph traversal, probably using dfs
//node 방문시에 방문했다고 표시함.
//node i의 방문 여부는 node[i][0]을 통해 저장함.
#include<stdio.h>
int node[101][101] = {0,};//default value as 0;
int worms=0;
void dfs(int nod){
    node[nod][0] = 0;
    for(int i=1;i<=100;i++){
        if(node[nod][i]==1){
            if(node[i][0]==1){//연결되어있고, 미방문시
                dfs(i);
                worms++;
            }
        }
    }
}

int main(){
    int com;//#of nodes
    int v;//#of vertices
    int a,b;//#two nodes connected by a vertex
    scanf("%d %d", &com, &v);
    for(int i=0;i<v;i++){
        scanf("%d %d", &a, &b);
        node[a][b] = 1;//다른 노드와의 연결이 하나라도 되어있으면 1
        node[b][a] = 1;
        node[a][0] = 1;//아직 미방문
        node[b][0] = 1;
    }
    dfs(1);
    
    printf("%d", worms);
    
    return 0;
}
