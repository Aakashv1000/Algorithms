#include<iostream>

using namespace std;

class btree{
private:
	struct node
	{
		node *left;
		node *right;
		char data;
	}*root;

	char *arr;

	int *lc,*rc;

public:
btree(char *a,int *l,int *r,int size);
void insert(int index);
static node* buildtree(char *a,int *l,int *r,int index);
void display();
static void inorder(node *s);
static void postorder(node *s);
static void preorder(node *s);
~btree();
static void del(node *s);
};

btree::btree(char *a,int *l,int *r,int size)
{
  root = NULL;

  arr = new char[size];
  lc  = new int[size];
  rc = new int [size];

  for(int i=0;i<size;i++)
  {
  	*(arr + i) = *(a + i);
  	*(lc + i) = *(l + i);
  	*(rc + i) = *(r+i);
  }
}

void btree::insert(int index)
{
	root = buildtree(arr,lc,rc,index);
}

btree::node* btree::buildtree(char *a,int *l,int *r,int index)
{
	node *temp=NULL;
	if(index != -1)
	{
		temp = new node;
		temp->left = buildtree(a,l,r,*(l + index));
		temp->data = *(a+index);
		temp->right = buildtree(a,l,r,*(r+index));
	}

	return temp;
}

void btree::display()
{
	cout<<"inorder traversal: ";
	inorder(root);
	cout<<"\npreorder traversal: \n";
	preorder(root);
	cout<<"\npostorder traversal: \n";
	postorder(root);
}

void btree::postorder(node *s)
{
	if(s != NULL)
	{
       postorder(s->left);
       postorder(s->right);
       cout<<s->data<<"\t";
	}
}

void btree::preorder(node *s)
{
	if(s!= NULL)
	{
		cout<<s->data<<"\t";
		preorder(s->left);
		preorder(s->right);
	}
}

void btree::inorder(node *s)
{
	if(s!= NULL)
	{
		inorder(s->left);
		cout<<s->data<<"\t";
		inorder(s->right);
	}
}

btree::~btree()
{
	delete arr;
	delete rc;
	delete lc;
	del(root);
}

void btree::del(node *s)
{
	if(s!=NULL)
	{
		del(s->left);
		del(s->right);
	}

	delete s;
}

int main()
{
	char a[]={'A','B','C','D','E','F','G','\0','\0','H'};
	int l[] = {1,3,5,-1,9,-1,-1,-1,-1,-1};
	int r[] = {2,4,6,-1,-1,-1,-1,-1,-1,-1};

	int sz = sizeof(a);

	btree bt(a,l,r,sz);
	bt.insert(0);

	
	bt.display();
}