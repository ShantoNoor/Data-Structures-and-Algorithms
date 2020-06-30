#include <stdio.h>

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

int find(int set[], int u)
{
	int x = u, v = 0;
	while(set[x] > 0) x = set[x];
	while(u != x)
	{
		v = set[u];
		set[u] = x;
		u = v;
	}
	return x;
}

int main()
{
	int set[11];
	for (int i = 0; i < 11; i++)
		set[i] = -1;

	// set[3] = -3;
	// set[5] = 3;
	// set[9] = 3;

	// set[4] = -4;
	// set[7] = 4;
	// set[8] = 4;
	// set[10] = 4;

	// Union(set, 3, 4);

	Union(set, 5, 6);
	Union(set, 5, 8);

	for (int i = 1; i < 11; i++)
		printf("%d ", set[i]);
	printf("\n");

	// printf("\n%d\n", find(set, 5));
	for (int i = 1; i < 11; i++)
		printf("%d ", set[i]);
	printf("\n");

	return 0;
}