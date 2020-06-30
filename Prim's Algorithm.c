#include <stdio.h>
#define I 1e+9
#define N 7+1
/*--------^Number of Nodes--------*/

int main()
{
	int G[N][N] = {
		{ I,  I,  I,  I,  I,  I,  I,  I},
		{ I,  I, 25,  I,  I,  I,  5,  I},
		{ I, 25,  I, 12,  I,  I,  I, 10},
		{ I,  I, 12,  I,  8,  I,  I,  I},
		{ I,  I,  I,  8,  I, 16,  I, 14},
		{ I,  I,  I,  I, 16,  I, 20, 18},
		{ I,  5,  I,  I,  I, 20,  I,  I},
		{ I,  I, 10,  I, 14, 18,  I,  I},
	};

	int near[N];
	for (int i = 0; i < N; i++)
		near[i] =  I;

	int edge[N-2][2] = {{0},{0}};

	int min = I, u, v;

	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if(G[i][j] < min)
			{
				min = G[i][j];
				u = i; 
				v = j;
			}
		}
	}

	edge[0][0] = u;
	edge[0][1] = v;

	near[u] = 0;
	near[v] = 0;

	for (int i = 1; i < N; i++)
	{
		if(near[i] != 0)
		{
			if(G[i][u] < G[i][v])
				near[i] = u;
			else
				near[i] = v;
		}
	}

	int n = 1;
	while(n < N-2)
	{
		min = I;
		for (int i = 1; i < N; i++)
		{
			if(near[i] != 0)
			{
				if(min > G[i][near[i]])
				{
					min = G[i][near[i]];
					u = i;
				}
			}
		}

		edge[n][0] = u;
		edge[n][1] = near[u];
		
		n++;
		near[u] = 0;

		for (int i = 1; i < N; i++)
		{
			if(near[i] != 0)
			{
				if(G[i][u] < G[i][near[i]])
					near[i] = u;
			}
		}
	}

	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			printf("%d ", edge[i][j]);
		}
		printf("\n");
	}

	return 0;
}