#include<stdio.h>
int g[10][10] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};
int visit[10] = {0};
int n = 5;

int main()
{
    int i, j, min, a, b, cost = 0;
    visit[0] = 1;

    printf("MST Edges:\n");
    for(i=1; i<n; i++)
    {
        min = 999;
        a = 0; b = 0;

        for(j=0; j<n; j++)
        {
            if(visit[j])
            {
                for(int k=0; k<n; k++)
                {
                    if(!visit[k] && g[j][k] && g[j][k] < min)
                    {
                        min = g[j][k];
                        a = j;
                        b = k;
                    }
                }
            }
        }
        printf("%d -- %d : %d\n", a, b, min);
        cost += min;
        visit[b] = 1;
    }
    printf("Total Cost: %d\n", cost);
    return 0;
}