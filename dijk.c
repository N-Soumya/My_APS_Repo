#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void dijkstras(int cost[100][100], int dist[100], int visit[100], int path[100], int source, int n)
{
    int i, u;
    u = source;

    int temp1 = 999;
    for(i=0; i<n; i++)
    {
        if(visit[i]==0)
        {
            if(dist[i] < temp1)
            {
                temp1 = dist[i];
                u = i;
                visit[u] = 1;
            }


        }
    }



    int j;
    for(j=0; j<n; j++)
    {
        int temp = dist[u];
        if(visit[j]==0)
        {
            int temp2 = dist[j];
            if((temp + cost[u][j])  < temp2)
            {
                visit[j] = 1;
                path[j] = u;
                dist[j] = (temp + cost[u][j]);
                u = j;
            }
            else if((temp + cost[u][j])  > temp2)
            {
                visit[j] = 1;
                path[j] = u;
                u = j;
            }


        }
    }

}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int cost[10][10];
    int n, e;
    int i,j,k;

    scanf("%d", &n);
    scanf("%d", &e);

    int dist[100];
    int visit[100];
    int path[100];
    int source;

    for(i=0; i<e; i++)
    {
        for(j=0; j<e; j++)
        {
            int x,y;

            cost[i][j]=999;
            scanf("%d", &x);
            scanf("%d", &y);
            scanf("%d", &cost[x][y]);
        }

    }
    source = cost[0][0];
    int q;
    scanf("%d", &q);
    int t[q];

    for(i=0; i<q; i++)
    {
        scanf("%d", &t[i]);
    }

    for(k=0; k<n; k++)
    {
        visit[k]=0;
        path[k] = source;
        dist[k] = cost[source][k];
    }
    visit[source] = 1;


    dijkstras(cost, dist, visit, path, source, n);

    int a;
    for(i=0; i<q; i++)
    {

        a = t[i];
        printf("%d\n", dist[a]);
    }

    return 0;
}
