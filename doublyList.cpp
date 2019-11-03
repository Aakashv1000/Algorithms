#include<iostream>

using naemspace std;

class dlist{
private:
	struct node
	{
		int data;
		node *prev;
		node *next;
	}*head;
public:

   dlist();
   void d_append(int num);
   void addAtBeg(int num);
   void addAfter(int pos,int num);
   void display();
   void del(int i);
   ~dlist();
};

dlist::dlist(){
	head = NULL;
}

dlist::d_append(int num)
{
	if(head == NULL)
	{
		head->data = num;
		head->prev = NULL;
		head->next=NULL;
	}else{
		node *temp = head;
        
        while(temp->next != NULL)
        	temp = temp->next;

         node *r;

         r = new node;
         r->data = num;
         r->prev = temp;
         r->next = NULL;
	}

}

dlist::addAtBeg(int num)
{
	node *temp;

	temp = new node;
	temp->prev = NULL;
	temp->data = num;
	temp->next = head;
	head = temp;
}

dlist::addAfter(int pos,int num)
{
	node *temp;

	temp = head;

	for(int i =0 ; i<pos;i++)
	{
		temp = temp->link;
	}
    temp = temp->prev;
	node *r = new node;

	r->data = num;
	r->next = NULL;
	r->prev = NULL;	
}

dlist::display(){
	node *temp= head;
    while(temp != NULL)
    {
    	cout<<temp->data<<" ";
    	temp=temp->next;
    }
}

void list::del(int num)
{
	node *temp = head;

	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp==head)
			{
                  head = head -> next;
                  head->prev = NULL;
			}else{
				if(temp->next == NULL)
				{
                   temp->prev->next = NULL;
				}else{
					temp->prev->next = temp->next;
					temp->next->prev = q->prev;
				}delete q;
			}return;

		}temp=temp->next;
	}
}

dlist::~dlist()
{
	dnode *q;

	while(q->next != NULL)
	{
		q=head->next;
		delete head;
		head = q;
	}
}

int main()
{
	
}