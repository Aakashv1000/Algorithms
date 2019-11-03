#include <algorithm>
#include<vector>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

int dfs(vector<int> tree[],bool visited[],int *result,int root)
{
	int temp, num = 0;

	visited[root] = true;

	for(vector<int>::iterator j=tree[root].begin() ; j!=tree[root].end() ; ++j)
	{
		if(visited[*j] == false)
		{
			temp = dfs(tree,visited, result,*j);

			(temp % 2) != 0? (num += temp) : ((*result)++);
		}
	}

	return num +1;
}

int minEdge(vector<int> tree[],int n)
{
	bool visited[n + 1];

	for(int i=1 ;i<= n;i++)
		visited[i] = false;

	int result = 0;

	dfs(tree, visited, &result, 1); 
  
    return result;

}


int main()
{
	int t_nodes,t_edges;

	cin>>t_nodes>>t_edges;

	vector<int> tree[t_nodes+1];

	for(int i=1; i<=t_edges;i++)
	{
		int x,y;
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}

	int result = minEdge(tree,t_nodes);

	cout<<result<<endl;
}