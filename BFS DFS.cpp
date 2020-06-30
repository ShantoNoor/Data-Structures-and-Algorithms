#include <iostream>
#include <queue>
using namespace std;

void BFS(int arr[][7], int node, int n)
{
	int visited[n] = {0};
	queue<int> q;
	int v = node;

	printf("%d ", v);
	visited[v] = 1;
	q.push(v);

	while(!q.empty())
	{
		v = q.front();
		q.pop();
		for (int j = 1; j < n; j++)
		{
			if(arr[v][j] == 1 && visited[j] == 0)
			{
				printf("%d ", j);
				visited[j] = 1;
				q.push(j);
			}
		}
	}
	printf("\n");
}

void DFS(int arr[][7], int node, int n)
{
	static int visited[7] = {0};

	if(visited[node] == 0)
	{
		printf("%d ", node);
		visited[node] = 1;

		for (int i = 1; i < n; i++)
			if(arr[node][i] == 1 && visited[i] == 0)
				DFS(arr, i, n);
	}
}

int main()
{
	int g[7][7] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 1, 0, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 1, 0, 0, 1, 0, 0},
		{0, 0, 1, 1, 0, 1, 1},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
	};

	BFS(g, 4, 7);
	DFS(g, 4, 7); printf("\n");

	return 0;
}