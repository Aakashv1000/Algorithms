#include<iostream>

using namespace std;

class ttree{
private:
	struct node
	{
		bool left;
		bool right;
		node *lc;
		node *rc;
		int data;
	}*root;
public:
	ttree();
	void insert(int num);
    void inorder();
	void remove(int num);
	static void search(node **sr,int num,node **par,node **x,bool *found);
	~ttree();
};

ttree::ttree(){
	root = NULL;
}

void ttree::insert(int num)
{
	node *head = root,*p,*z;

	z = new node;
	z->left = true;
	z->right = true;
	z->data = num;

	if(root == NULL)
	{
      head = new node;
      head ->left =false;
      head->lc=z;
      head->data = -99999;
      head->rc = head;
      head->right = false;
      root = head;
      z->lc=head;
      z->rc=head;
	}else{
		p = head->lc;
		while(p!= head)
		{
			if(p->data>num)
			{
				if(p->left != true)
				{
					p=p->left;
				}else{
					z->lc=p->lc;
					p->lc=z;
					p->left = false;
					z->right = true;
					z->rc=p;
					return;
				}
			}else{
				 
			}
		}
	}
}