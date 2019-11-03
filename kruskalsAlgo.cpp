#include <algorithm>
#include<vector>
#include<iostream>
#include<list>
#include<queue>

using namespace std;

struct g_weight
{
	int g_from,g_to,g_wt;
};

struct subset
{
	int parent,rank;
};

bool cmp_wt(g_weight a,g_weight b)
{
	if(a.g_wt != b.g_wt)
		return a.g_wt < b.g_wt;
}

int find(subset subsets[], int i)
{
		if(subsets[i].parent != i)
			subsets[i].parent = find(subsets,subsets[i].parent);
		return subsets[i].parent;
}

void Union(subset subsets[],int x,int y)
{
	int xroot = find(subsets,x);
	int yroot = find(subsets,y);

	if(subsets[xroot].rank <subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if(subsets[xroot].rank >subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

void kruskals(g_weight *x,int g_edges)
{
	g_weight result[g_edges];

	sort(x+1, x+g_edges+1,cmp_wt);

	int k=1;

	subset* subsets = new subset[g_edges+1];

	for (int i = 1; i <= g_edges; i++)
	{
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}

	for(int i=1;i<=g_edges;i++)
	{
		g_weight minEdge = x[i];

		int x = find(subsets,minEdge.g_from );
		int y = find(subsets,minEdge.g_to );

		if(x != y)
		{
			result[k++] = minEdge;
			Union(subsets,x,y);

			
		}

		if(k == g_edges)
			break;
	}

	int tot = 0;

	for (int i = 1; i <k ; i++)
	{
		tot += result[i].g_wt;
	}
		cout<<tot<<endl;

}

int main()
{
	int g_nodes,g_edges;

	cin>>g_nodes>>g_edges;

	g_weight* x = new g_weight[g_edges+1]; 

	for(int i=1;i<=g_edges;i++)
	{
		int s,d,w;
		cin>>s>>d>>w;
		x[i].g_from = s;
		x[i].g_to = d;
		x[i].g_wt = w;
	}

	kruskals(x,g_edges);
}