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
int q[100], f = 0, r = -1;

void bfs(int v, int n)
{
    int i;
    visit[v] = 1;
    q[++r] = v;

    while(f <= r)
    {
        v = q[f++];
        printf("%d ", v);

        for(i=0; i<n; i++)
        {
            if(g[v][i] == 1 && visit[i] == 0)
            {
                visit[i] = 1;
                q[++r] = i;
            }
        }
    }
}

int main()
{
    printf("BFS: ");
    bfs(0, 6);
    printf("\n");
    return 0;
}