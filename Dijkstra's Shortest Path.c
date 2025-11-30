#include<stdio.h>
int g[10][10] = {
    {0, 4, 0, 8, 0},
    {4, 0, 8, 0, 0},
    {0, 8, 0, 7, 0},
    {8, 0, 7, 0, 9},
    {0, 0, 0, 9, 0}
};
int dist[10];
int visit[10] = {0};
int n = 5;

int main()
{
    int i, j, min, u;

    for(i=0; i<n; i++)
        dist[i] = 999;
    dist[0] = 0;

    for(i=0; i<n; i++)
    {
        min = 999;
        for(j=0; j<n; j++)
        {
            if(!visit[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }
        visit[u] = 1;

        for(j=0; j<n; j++)
        {
            if(g[u][j] && !visit[j])
            {
                if(dist[u] + g[u][j] < dist[j])
                    dist[j] = dist[u] + g[u][j];
            }
        }
    }

    printf("Shortest distances from 0:\n");
    for(i=0; i<n; i++)
        printf("Node %d : %d\n", i, dist[i]);

    return 0;
}