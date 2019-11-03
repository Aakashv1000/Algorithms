#include <algorithm>
#include<vector>
#include<iostream>
#include<list>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;


int minKey(int key[],bool visited[],int n)
{
	int min = 9999, min_idx;

	for(int i=1;i<=n; i++)
	{
		if(visited[i] == false && key[i]<min)
			min = key[i],min_idx = i;
	}

	return min_idx;
}

void prims(int n,int **graph, int m, int s)
{
	int key[n+1];
	bool visited[n+1];
	int result = 0;

	for(int i=1;i<=n;i++)
		key[i] = 9999, visited[i] = false;

	key[s] = 0;

	for(int i =0; i<n;i++)
	{
		int u = minKey(key,visited,n);

		visited[u] = true;

		result += key[u];

		for(int j=1; j<=n;j++)
		{
			if(visited[j] == false && graph[u][j]>=0 && graph[u][j]<key[j])
			{
				key[j] = graph[u][j];
			}
		}
	}

	cout<<result<<endl;

}

int main()
{
	int n,m,s;
	cin>>n>>m;

	int **graph = new int*[n+1];
	for (int i = 1; i < n+1; ++i)
	{
		graph[i] = new int[n+1];
	}

	for (int i = 0; i < n+1; ++i)
	{
		for(int j=0;j<n+1;j++)
		{
			graph[i][j] = -1;
		}
	}

	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		
		graph[x][y] = w;
		graph[y][x] = w;
	}

	cin>>s;

	prims(n,graph,m,s);
	
	return 0;
}