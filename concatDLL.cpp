#include<iostream>

using namespace std;

class dlist{
private:
	struct node
	{
		int data;
		node *next;
		node *prev;
	}*head;
public:
	dlist();
	void append(int num);
	void concat(dlist &l1,dlist &l2);
	void disp();
	~dlist();
};

dlist::dlist()
{
	head = NULL;
}

void dlist::append(int num)
{
   node *temp,*r;

   r = new node;
   r->data = num;

   temp = head;


   if(head == NULL || head->data > num)
   {
        head = r;
        head->next=temp;
        head->prev = NULL;
        if(temp != NULL)
        temp->prev = head;
   }else{
   
   	while(temp ->data < num)
   	{
   		if(temp->next == NULL)
   		break;
   	    temp = temp->next;
   	  	
   	}
   	 
   		
      if(temp->next != NULL){
      	r->next=temp;
      	r->prev = temp->prev;
      	(temp->prev)->next = r;
      	temp->prev = r;
      }else
      {
          r->next = NULL;
          r->prev = temp;
          temp->next = r;
      }
   
}
}

void dlist::disp()
{
	node *temp = head;

	cout<<endl;

	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void dlist::concat(dlist &l1,dlist &l2)
{
   node *z,*temp;

   z= NULL;

   if(l1.head == NULL && l2.head == NULL)
   	return;

   while(l1.head != NULL && l2.head != NULL)
   {
   	if(head == NULL)
   	{
   		head = new node;
   		z = head;
   		z->prev = NULL;
   	}else{
   	
   		z->next = new node;
   		temp = z;
   		z=z->next;
   		z->prev = temp;
   	}

   	if(l1.head->data >l2.head->data)
   	{
   		z->data = l2.head->data;
   		l2.head=l2.head->next;
   	}else{
   		if(l2.head ->data > l1.head->data)
   		{
   			z->data = l1.head->data;
   			l1.head=l1.head->next;
   		}else
   		{
   			if(l1.head->data == l2.head->data)
   			{
   				z->data = l1.head->data;
   				l1.head = l1.head->next;
   				l2.head = l2.head -> next;
   			}
   		}
   	}

   }

   while(l1.head != NULL)
   {
   	z->next = new node;
   	temp = z;
   	z=z->next;
   	z->prev = temp;
   	z->data = l1.head->data;
   	l1.head = l1.head->next;
   }

   while(l2.head != NULL)
   {
   	z->next = new node;
   	temp = z;
   	z=z->next;
   	z->prev = temp;
   	z->data = l2.head->data;
   	l2.head = l2.head->next;
   }
   z->next = NULL;
}

dlist::~dlist()
{
	node *q;

	while (head != NULL)
	{
		q = head ->next;
		delete head;
		head = q;
	}
}

int main()
{
	int n;

	dlist l1,l2,l3;

	cout<<"Enter number of elements of list 1: \n";
	cin>>n;

	int m;
	cout<<"Enter number of elements of list 2: \n";
	cin>>m;

	cout<<"\nEnter elements of list 1\n";

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l1.append(x);
	}

	l1.disp();

	cout<<"\nEnter elements of list 2\n";

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		l2.append(x);
	}

	l2.disp();

	l3.concat(l1,l2);
	l3.disp();
}