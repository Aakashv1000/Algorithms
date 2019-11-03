#include<iostream>

using namespace std;

class btree{
private:
	struct node{
		node *left,*right;
		char data;
	}*root = NULL;
public:
	void insert();
	static node* buildtree();
    int countLeaf(node *s);
    void numberOfnodes();
    void callAncestor();
    bool ancestors(node *s,char x);
    bool parent(node *s,char x);
    void callParent();
    int depth(node *s);
    void calldepth();
    void callFull();
    bool fullTree(node *s);
};




void btree::insert(){
	root = buildtree();
}

btree::node* btree::buildtree()
{
   node* temp;

   char x;

   cout<<"\nEnter data(press q to quit): ";
   cin>>x;

   if(x=='q')
   	return NULL;

   temp = new node;

   temp->data = x;

   cout<<" Enter the left child of "<<x<<" : \n";
   temp->left = buildtree();

   cout<<"\n Enter the right child of "<<x<<" : \n";
   temp->right = buildtree();
}

int btree::countLeaf(node *s)
{
   if(s == NULL)
       return 0;

   if(s->right == NULL && s->left == NULL)
   	    return 1;

   	return countLeaf(s->left) + countLeaf(s->right);
}

void btree::numberOfnodes(){
	int x = countLeaf(root);

	cout<<"\nNumber of leaf nodes is: "<<x<<"\n";
}

bool btree::ancestors(node *s,char x)
{
	if(s == NULL)
		return false;

	if(s->data == x)
		return true;
    
    if(ancestors(s->left,x) || ancestors(s->right,x))
    {
    	cout<<s->data<<" ";
    	return true;
    }

    return false;

}

void btree::callAncestor()
{
	cout<<"\n Whose ancestors: \n";

	char x;
	cin>>x;
	ancestors(root,x);
}

bool btree::parent(node *s,char x)
{

	if(s == NULL)
		return false;

	if(s->right && s->right->data == x  )
	{
		cout<<s->data;
		return true;
	}else{
	    parent(s->right,x);	
	}

	if(s->left)
	{
		if(s->left->data == x)
		{
			cout<<s->data;
		    return true;
		}else{
			parent(s->left,x);
		}
	}
	
	return false;

    
}

void btree::callParent()
{
	cout<<"\n Whose parent: \n";

	char x;
	cin>>x;
	parent(root,x);
}

int btree::depth(node *s)
{
	if(s == NULL)
		return 0;

	int l =depth(s->left);
	int r = depth(s->right);

	if(l>r)
		return l+1;
	else
		return r+1;
}

void btree::calldepth(){
	int x = depth(root);

	cout<<"\nDepth of the tree is: "<<x<<"\n";
}

bool btree::fullTree(node *s)
{
  if(s == NULL)
  	return true;

  if(s->right == NULL && s->left == NULL)
  	    return true;

   if(s->left && s->right)
       return fullTree(s->left) && fullTree(s->right);
   
  return false;
}

void btree::callFull()
{

	if(fullTree(root))
		cout<<"\n This is a full tree \n";
	else
		cout<<"\n Not a full binary tree \n";
}




int main(){
	btree b;

	b.insert();

	cout<<"**********************";
	b.numberOfnodes();
	cout<<"\n***********************\n";
	b.callAncestor();
	cout<<"\n************************\n";
	b.callParent();
	b.calldepth();

	cout<<"\n************************\n";
	b.callFull();
}



