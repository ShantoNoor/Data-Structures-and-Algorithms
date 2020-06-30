#include <stdio.h>
#define I -1
#define N 7+1
/*--------^Number of Nodes--------*/

void Union(int set[], int u, int v)
{
	if(set[u] < set[v])
	{
		set[u] += set[v];
		set[v] = u;
	}
	else
	{
		set[v] += set[u];
		set[u] = v;
	}
}

int find(int set[], int x)
{
	while(set[x] > 0) x = set[x];
	return x;
}

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

	int edges[9][3], e = 0, en = 9;
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j++)
		{
			if(G[i][j] != -1)
			{
				edges[e][0] = i;
				edges[e][1] = j;
				edges[e][2] = G[i][j];
				e++;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < en; j++)
		{
			printf("%2d ", edges[j][i]);
		}
		printf("\n");
	}

	int set[N];
	for (int i = 0; i < N; i++)
		set[i] = -1;

	int included[9] = {0};
	int res[N-2][2];
	int min, k = 0;
	int u, v, w;
	while(k < N-2)
	{
		min = 1e+9;
		for (int i = 0; i < en; i++)
		{
			if(included[i] == 0 && edges[i][2] < min)
			{
				min = edges[i][2];
				u = edges[i][0];
				v = edges[i][1];
				w = i;
			}
		}
		included[w] = 1;

		if(find(set, u) != find(set, v))
		{
			res[k][0] = u;
			res[k][1] = v;
			k++;

			Union(set, find(set, u), find(set, v));
		}
	}

	for (int i = 0; i < N-2; i++)
	{
		printf("%d %d\n", res[i][0], res[i][1]);
	}

	return 0;
}