#include<stdio.h>
int parent[10];

int find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}

void union_sets(int x, int y)
{
    parent[x] = parent[y];
}

int main()
{
    int edges[20][3] = {
        {0,1,10},{0,2,6},{0,3,5},
        {1,3,15},{2,3,4}
    };
    int n = 4, e = 5;
    int i, j, a, b, cost = 0;

    for(i=0; i<n; i++) parent[i] = i;

    for(i=0; i<e; i++)
    {
        for(j=i+1; j<e; j++)
        {
            if(edges[i][2] > edges[j][2])
            {
                int temp[3];
                temp[0] = edges[i][0];
                temp[1] = edges[i][1];
                temp[2] = edges[i][2];
                edges[i][0] = edges[j][0];
                edges[i][1] = edges[j][1];
                edges[i][2] = edges[j][2];
                edges[j][0] = temp[0];
                edges[j][1] = temp[1];
                edges[j][2] = temp[2];
            }
        }
    }

    printf("MST Edges:\n");
    for(i=0; i<e; i++)
    {
        a = find(edges[i][0]);
        b = find(edges[i][1]);

        if(a != b)
        {
            union_sets(a, b);
            printf("%d -- %d : %d\n", edges[i][0], edges[i][1], edges[i][2]);
            cost += edges[i][2];
        }
    }
    printf("Total Cost: %d\n", cost);
    return 0;
}