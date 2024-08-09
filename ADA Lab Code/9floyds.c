#include<stdio.h>

void floyd(int n, int cam[20][20]);
void printmat(int dist[20][20], int n);
void readmat();

void main()
{
    readmat();
}

void readmat()
{
    int cam[20][20], n, j, i;

    printf("enter the number of vertices\n");
    scanf("%d", &n);

    printf("enter the cost adjacency matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cam[i][j]);
        }
    }
    floyd(n, cam);
}

void floyd(int n, int cam[20][20])
{
    int i, k, j, dist[20][20];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = cam[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printmat(dist, n);
}

void printmat(int dist[20][20], int n)
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == j)
            {
                dist[i][j] = 0;
            }
        }
    }

    printf("matrix containing shortest distance between two vertices is\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("%d\t", dist[i][j]);
        }
    }
}



#include<stdio.h>

void wrshl(int n, int a[20][20]);

void main()
{
    int i, j, k, n, a[20][20];

    printf("Enter the no of vertices\n");
    scanf("%d", &n);

    printf("Enter the AM\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("The transitive closure for the graph is\n");
    wrshl(n, a);
}

void wrshl(int n, int a[20][20])
{
    int i, j, k, m1[20][20], m2[20][20];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m1[i][j] = a[i][j];
        }
    }

    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m2[i][j] = (m1[i][j] || (m1[i][k] && m1[k][j]));
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m1[i][j] = m2[i][j];
            }
        }
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", m2[i][j]);
        }
        printf("\n");
    }
}
