#include <stdio.h>
#include <stdlib.h>

struct Graph
{
    int u;
    int v;
    int w;
};
typedef struct Graph graph;

void bubble_sort(graph a[], int n)
{
    int i,j;
    for(i=0; i<=n-2; i++)
    {
        for(j=0; j<=n-2-i; j++)
        {
            if(a[j].w > a[j+1].w)
            {
                int temp = a[j+1];
                int temp1 = a[j+1].u;
                int temp2 = a[j+1].v;
                a[j+1].w = a[j].w;
                a[j+1].u = a[j].u;
                a[j+1].v = a[j].v;
                a[j].w = temp;
                a[j].u = temp1;
                a[j].v = temp2;
            }
        }
    }
}
void spanning(graph g[], int e, int n)
{
    int i,j;
    int a[n];
    int count=0;
    int d=0;
    for(i=0; i<n; i++)
    {
        a[i]= i;
    }
    for(i=0; i<e && d<(n-1); i++)
    {
        int m = a[g[i].u];
        int n = a[g[i].v];
        if(m!=n)
        {
            count = count + g[i].w;
            printf("%d %d\n", g[i].u ,g[i].v);
            for(j=0; j<n; j++)
            {
                if(a[j]==m)
                    a[j]=n;
            }
            d++;
        }

    }
    printf("Cost: %d\n", count);


}
int main()
{
    int n, e;
    printf("Enter number of vertices\n");
    scanf("%d", &n);
    printf("Enter number of edges\n");
    scanf("%d", &e);
    graph g[20];
    int i;
    printf("Enter u,v,w\n");
    for(i=0; i<e; i++)
    {

        scanf("%d%d%d", &g[i].u, &g[i].v, &g[i].w);
    }
    bubble_sort(g, e);
    printf("MST\n");
    spanning(g, e, n);
    return 0;
}
