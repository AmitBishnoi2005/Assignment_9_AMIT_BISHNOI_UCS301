#include<stdio.h>
int g[10][10] = {
    {0,1,1,0,0,0},
    {1,0,0,1,1,0},
    {1,0,0,0,0,1},
    {0,1,0,0,0,0},
    {0,1,0,0,0,0},
    {0,0,1,0,0,0}
};
int visit[10] = {0};

void dfs(int v, int n)
{
    int i;
    visit[v] = 1;
    printf("%d ", v);

    for(i=0; i<n; i++)
    {
        if(g[v][i] == 1 && visit[i] == 0)
            dfs(i, n);
    }
}

int main()
{
    printf("DFS: ");
    dfs(0, 6);
    printf("\n");
    return 0;
}