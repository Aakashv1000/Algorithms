#include<iostream>

using namespace std;

struct node
{
	int data;
	int balfact;
	node *left;
	node*right;
};

class avltree{
private:
	node *root;
public:
	avltree();
	node *insert(int data,int *h);
    static node* buildtree(node *root,int data,int *h);
    void display(node *root);
    node *deldata(node *root,int data,int *h);
    static node *balright(node* root,int *h);
    static node* balleft(node* root,int *h);
    static node* del(node* x,node* root,int *h);
    void setroot(node *avl);
    ~avltree();
    static void deltree(node *root);
};

avltree::avltree()
{
	root = NULL;
}

node *avltree::insert(int data,int *h)
{
	root = buildtree(root,data,h);
	return root;
}

node* avltree::buildtree(node *root,int data,int *h)
{
	node *node1,*node2;

	if(root == NULL)
	{
		root = new node;
		root->data = data;
		root->right = NULL;
        root->left = NULL;
        root->balfact = 0;
        *h = true;
        return(root);
	}

	if(data < root->data)
	{
		root->left = buildtree(root->left,data,h);

		if(*h){
			switch(root->balfact)
			{
				case 1: 
				node1 = root->left;
				if(node1->balfact == 1)
				{
					cout<<"\n Right rotation \n";
					root->left = node1 ->right;
					node1->right = root;
					root->balfact = 0;
					root = node1; 
				}else{
					cout<<"\nDouble rotation,left and right \n";
					node2 = node1->right;
					node1->right = node2->left;
					node2->left = node1;
					root->left = node2->right;
					node2->right = root;


					if(node2->balfact == 1)
						root->balfact = -1;
					if(node2->balfact == -1)
						node1->balfact = 1;
					else
						node1->balfact = 0;
					root = node2;

				}

				root->balfact = 0;

				*h = false;
				break;

				case 0:

				    root->balfact = 1;
				    break;
				case -1:

				     root->balfact = 0;
				     break;
			}
		}
	}


	if(data>root->data)
	{
		root->right = buildtree(root->right,data,h);

		if(*h)
		{
			switch(root->balfact)
			{
				case 1:
				root->balfact = 0;
				*h = false;
				break;

				case 0:
				  root->balfact = -1;
				  break;

				case -1:
                      node1 = root->right;
				if(node1->balfact == -1)
				{
					cout<<"\n left rotation \n";
					root->right = node1 ->left;
					node1->left = root;
					root->balfact = 0;
					root = node1; 
				}else{
					cout<<"\nDouble rotation,right and left \n";
					node2 = node1->left;
					node1->left = node2->right;
					node2->right = node1;
					root->right = node2->left;
					node2->left = root;


					if(node2->balfact == -1)
						root->balfact = 1;
					if(node2->balfact == 1)
						node1->balfact = -1;
					else
						node1->balfact = 0;
					root = node2;

				}

				root->balfact = 0;
				*h = false;

			}
		}
	}return (root);
}

void avltree::display(node *root)
{
	if(root != NULL)
	{
		display(root->left);
		cout<<root->data<<" ";
		display(root->right);
	}
}

void avltree::setroot(node *avl)
{
	root = avl;
}

avltree::~avltree()
{
	deltree(root);
}

void avltree::deltree(node *root)
{
	if(root != NULL)
	{
		deltree(root->left);
		deltree(root->right);
	}delete(root);
}

int main(){
	avltree at;
	node *avl = NULL;
	int h;

	avl = at.insert(20,&h);
	at.setroot(avl);
	avl = at.insert(24,&h);
	at.setroot(avl);
	avl = at.insert(26,&h);
	at.setroot(avl);
	avl = at.insert(28,&h);
	at.setroot(avl);
	avl = at.insert(29,&h);
	at.setroot(avl);

	at.display(avl);
}