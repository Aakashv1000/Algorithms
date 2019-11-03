#include <algorithm>
#include<vector>
#include<iostream>

using namespace std;

const int MAX = 8;

struct node
{
	int data;
	node *next;
};

class graph{
private:
	bool visited[MAX];
	int q[8];
	int front,rear;

public:
	graph();
	void bfs(int v,node **p);
	node *getnode_write(int val);
	static void addqueue(int *a,int vertex,int *f,int *r);
	static int deletequeue(int *q,int *f,int *r);
	static bool isempty(int *f);
	void del(node *n);
};

graph::graph()
{
	for (int i = 0; i < MAX; i++)
	{
		visited[i]=false;
	}

	front=rear=-1;
}

node* graph::getnode_write(int val){
	node *newnode = new node;
	newnode->data = val;
	return newnode;
}

bool graph::isempty(int *f){
	if(*f == -1)
		return true;
	return false;
}

void graph::bfs(int v,node **p){
node *u;

visited[v-1] = true;

cout<<v<<"\t";

addqueue(q,v,&front,&rear);


while(isempty(&front) == false){
	v=deletequeue(q,&front,&rear);
	u = *(p + v-1);

	while(u != NULL){
		if(visited[u->data - 1] == false)
		{
			addqueue(q,u->data,&front,&rear);
			visited[u->data - 1] = true;
			cout<<u->data<<"\t";
		}

		u=u->next;
	}
}

}

void graph::addqueue(int *a,int vertex,int *f,int *r){
	if(*r == MAX - 1)
	{
		cout<<"Queue Overflow";
		exit(0);
	}

	(*r)++;
	a[*r]=vertex;

	if(*f==-1)
		*f=0;
}

int graph::deletequeue(int *a,int *f,int *r)
{
	int data;

	if(*f == -1){
		cout<<"Queue underflow";
		exit(0);
	}

	data = a[*f];
	if(*f==*r)
		*f=*r=-1;
	else
		(*f)++;

	return data;
}

void graph::del(node *n)
{
	node *temp;

	while(n != NULL)
	{
		temp=n->next;
		delete n;
		n = temp;
	}
}

int main(){
	node *arr[MAX];
	node *v1,*v2,*v3,*v4;

	graph g;

	v1 = g.getnode_write(2);
	arr[0]=v1;
	v1->next = v2 = g.getnode_write(3);
	v2->next = NULL;

	v1 = g.getnode_write(1);
	arr[1]=v1;
	v1->next = v2 = g.getnode_write(4);
	v2->next = v3 = g.getnode_write(5);
	v3->next = NULL;

	v1 = g.getnode_write(1);
	arr[2]=v1;
	v1->next = v2 = g.getnode_write(6);
	v2->next = v3 = g.getnode_write(7);
	v3->next = NULL;

	v1 = g.getnode_write(2);
	arr[3]=v1;
	v1->next = v2 = g.getnode_write(8);
	v2->next = NULL;

	v1 = g.getnode_write(2);
	arr[4]=v1;
	v1->next = v2 = g.getnode_write(8);
	v2->next = NULL;

	v1 = g.getnode_write(3);
	arr[5]=v1;
	v1->next = v2 = g.getnode_write(8);
	v2->next = NULL;

	v1 = g.getnode_write(3);
	arr[6]=v1;
	v1->next = v2 = g.getnode_write(8);
	v2->next = NULL;

	v1 = g.getnode_write(4);
	arr[7]=v1;
	v1->next = v2 = g.getnode_write(5);
	v2->next = v3 = g.getnode_write(6);
	v3->next = v4 = g.getnode_write(7);
	v4->next = NULL;

	cout<<endl;
	g.bfs(1,arr);

	for (int i = 0; i < MAX; i++)
	{
		g.del(arr[i]);
	}


}