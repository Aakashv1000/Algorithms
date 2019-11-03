#include<iostream>

using namespace std;

class btree{
private:
	struct node
	{
		node *left;
		node *right;
		int data;
	}*root;
public:
	btree();
	void buildtree(int num);
	void insert(node **sr,int num);
	void traverse();
	static void inorder(node *sr);
	static void preorder(node *sr);
	static void postorder(node *sr);
	void remove(int num);
	static void rem(node **sr,int num);
	static void search(node **sr,int num,node **par,node **x,bool *found);
	~btree();
	static void del(node *sr);
};

btree::btree(){
	root = NULL;
}

void btree::buildtree(int num)
{
	insert(&root,num);
}

void btree::insert(node **sr,int num)
{
	if(*sr == NULL)
	{
		*sr = new node;
		(*sr)->right = NULL;
		(*sr)->left = NULL;
		(*sr)->data = num;
	}else{
		if(num<(*sr)->data)
			insert(&((*sr)->left),num);
		else
			insert(&((*sr)->right),num);
	}
}

void btree::traverse()
{
	cout<<"\nIn-order: \n";
	inorder(root);
	cout<<"\nPost-order: \n";
	postorder(root);
	cout<<"\nPre-order: \n";
	preorder(root);
}

void btree::inorder(node *sr)
{
  if(sr != NULL)
  {
  	inorder(sr->left);
  	cout<<sr->data<<"\t";
  	inorder(sr->right);
  }
}

void btree::preorder(node *sr)
{
  if(sr != NULL)
  {
  	cout<<sr->data<<"\t";
  	preorder(sr->left);
  	preorder(sr->right);
  }
}

void btree::postorder(node *sr)
{
  if(sr != NULL)
  {
  	postorder(sr->left);
  	postorder(sr->right);
  	cout<<sr->data<<"\t";
  }
}

void btree::remove(int num)
{
	rem(&root,num);
}

void btree::rem(node **sr,int num)
{
	bool found;
	node *parent,*x,*xsucc;

	if(*sr == NULL)
	{
		cout<<"\n Tree is empty";
		return;
	}

	parent = x = NULL;

	search(sr,num,&parent,&x,&found);

	if(found == false)
	{
		cout<<"Data to be deleted,not found";
		return;
	}

	if(x->right != NULL && x->left != NULL)
	{
		parent = x;
		xsucc = x->right;

		while(xsucc->left != NULL)
		{
           parent = xsucc;
           xsucc = xsucc->left;
		}

		x->data = xsucc ->data;
		x=xsucc;
	}

	if(x->right == NULL && x->left == NULL)
	{
		if(parent->right == x)
			parent->right = NULL;
		else
			parent->left = NULL;
		delete x;
		return;
	}

	if(x->right == NULL && x->left != NULL)
	{
		if(parent->left == x)
			parent->left = NULL;
		else
			parent->right = x->left;
		delete x;
		return;
	}

	if(x->right != NULL && x->left == NULL)
	{
		if(parent->left == x)
			parent->left = x->right;
		else
			parent->right = x->right;
		delete x;
		return;
	}
}

void btree::search(node **sr,int num,node **par,node **x,bool *found)
{
	node *q;

	q=*sr;
	*found = false;
	*par = NULL;

	while(q != NULL)
	{
		if(q->data == num)
		{
			*found = true;
			*x = q;
			return;
		}

		*par = q;
		if(q->data >num)
			q=q->left;
		else 
			q=q->right;
	}

}

btree::~btree()
{
	del(root);
}

void btree::del(node *sr)
{
	if(sr != NULL)
	{
		del(sr->left);
		del(sr->right);
	}

	delete sr;
}

int main()
{
	btree bt;

	int n,l;

	cout<<"\n How many nodes? \n";
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		bt.buildtree(a[i]);
	}
    cout<<"\nBefore deletion: \n";
	bt.traverse();
    
    cout<<"\nhow many to remove? \n";
    cin>>l;
    cout<<"\n Enter the values: \n";
    for(int i=0;i<l;i++)
    {
    	int c;
    	cin>>c;
    	bt.remove(c);
    }
    
    cout<<"\n After deletion \n";
    bt.traverse();
}

