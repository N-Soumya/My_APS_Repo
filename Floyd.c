#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void floyd(int a[4][4], int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j]>a[i][k]+a[k][j])
				{
					a[i][j]=a[i][k]+a[k][j];
				}
		    }
	    }
	}
}

int min_distance(int a[4][4],int n,int i)
{

    int j,min0 =0,min;
    min = a[1][1];

    for(j=0;j<n-1;j++)
    {
        if(a[i][j] > min0)
        {
            if(a[i][j] < min)
                min = a[i][j];

        }

    }
    return min;
}

void path (int a[4][4],int n)
{
    int i,j,k,visited[n],source,current, price=0;
    for(i=0;i<n;i++)
        visited[i] = 0;

    source = a[0][0];

    for(i=0;i<n ;i++)
    {

    current = min_distance(a,n,i);
        for(j=0; j<n; j++)
        {

            if (current == a[i][j])
            {
                printf("Current place - %d \tPath - a[%d][%d]\n",current,i,j);
                price = price+a[i][j];
                break;
            }
        }
    }
    float t;
    t = price/10;  //Assuming the average speed of travel  is 10Km/H


    printf("The total distance covered: %d Km\nTime taken: %f hours\n", price, t);
}

int main()
{
	int cost[4][4] = {{2, 1, 2, 1}, {1, 3, 999, 999}, {2, 999, 5, 999}, {1, 999, 999, 0}};
	int n = 4;

	floyd(cost,n);
	path(cost,n);
}
