#include<iostream>

using namespace std;


struct node{
	
	node *left,*right;
	char data;
	
}*root = NULL;

	

class stack{
public:
	node* arr[10];
	int top;

	stack(){
		top =-1;
	}

	void push(node *s)
	{
		if(top == 9)
			return;
		arr[++top] = s;
	}

	node* pop()
	{
		if(top == -1)
			return NULL;
		return arr[top--];
	}

	node* peek(){
		if(top == -1)
			return NULL;
		return arr[top];
	}
};

class queue{
public:
	node *arr[20];
    int f,r;
	queue()
	{
		f = -1;
		r=-1;
	}

	void addq(node *s)
	{
		if(r == 19)
			return;
		arr[++r] = s;
	}

	node* delq()
	{
		if(f == r)
			return NULL;
       return arr[++f];
	}
};




node* buildtree()
{
	node *temp = NULL;
    char x;

    cout<<"Enter data(press q for no data)";
    cin>>x;

    if (x == 'q')
    	return NULL;

    temp = new node;
    temp->data = x;

    cout<<"Enter left child of "<<x<<": ";
    temp ->left = buildtree();

    cout<<"Enter right child of "<<x<<": ";
    temp->right = buildtree();

    return temp;


}

void insert()
{
	root = buildtree();
}


void preorder(node *root)
{
	if(root == NULL)
		return;

	node *curr = root;
  stack s;

  s.push(curr);

  for( ; ; )
  {
  	curr = s.pop();
  	if(curr == NULL)
  		break;
  	cout<<curr->data<<" ";

  	if(curr->right)
  	s.push(curr->right);
  if(curr->left)
  	s.push(curr->left);
  }

  
}

void inorder(node *root)
{
	if(root == NULL)
	{
		return;
	}
	node *curr = root;

	stack s;
   
   for(; ; )
   {
   	for( ; curr ; curr=curr->left)
   	s.push(curr);

   	curr=s.pop();

   	if(curr == NULL)break;

   	cout<<curr->data<<" ";
   	curr=curr->right;
   }
	
}

void postorder(node *root)
{
	if(root == NULL)
		return;

	stack s;

	do{
		while(root)
		{
			if(root->right)
			    s.push(root->right);
			s.push(root);

			root = root->left;
		}

		root = s.pop();

		if(root->right && s.peek() == root->right)
		{
			s.pop();
			s.push(root);
			root = root->right;
		}else{
			cout<<root->data<<" ";
			root = NULL;
		}
	}while(s.top!= -1);
}

void Levelorder(node *root)
{
	if(root == NULL)
		return;
	queue q;

	q.addq(root);

	for( ; ; )
	{
		root = q.delq();
		if(root == NULL)break;
		cout<<root->data<<" ";

		if(root->left)
			q.addq(root->left);
		if(root->right)
			q.addq(root->right);
	}
}

void display()
{
	cout<<"\nPre-Order traversal: \n";
	preorder(root);
	cout<<"\n In-Order travesal: \n";
    inorder(root);
    cout<<"\n Post-Order traversal: \n";
    postorder(root);
    cout<<"\n Level order traversal \n";
    Levelorder(root);
}


int main(){
  
  insert();

  cout<<"\n*****************\n";
  
  display();
}

