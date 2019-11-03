#include<iostream>

using namespace std;

class list
{
private:
	struct node{
		int data;
		node *link;
	}*p;
public:
	list();
	void addAtBeg(int num);
	void append(int num);
	void addAfter(int loc , int num);
	void display();
	int count();
	void del(int num);
	void delAlt();
	void sortList();
	void convert();
	~list();
};

list::list()
{
  p = NULL;
}

void list::append(int num)
{
	node *temp,*r;

	if(p == NULL)
	{
		temp = new node;
		temp->data = num;
		temp ->link = NULL;
		p=temp;
	}else{
		temp = p;
		while(temp->link!=NULL)temp = temp->link;

		r= new node;
		r->data = num;
		r->link = NULL;
		temp->link=r;
	}
}

void list::addAtBeg(int num)
{
	node *temp;
	temp = new node;
	temp->data = num;
    temp ->link = p;
    p = temp;
}

void list::addAfter(int loc , int num)
{
	node *temp,*r;
	temp = p;

	for(int i=0 ; i<loc ; i++)
	{
		temp = temp->link;

		if(temp == NULL)
		{
			cout<<"\n NO SUCH ELEMENTS "<<loc;
			return;
		}
        
    }

    r = new node;
	r->data  = num;
	r->link = temp->link;
	temp ->link = r;
}

void list::display()
{
	node *temp = p;
	cout<<endl;
	while(temp != NULL)
    {
    	cout<<temp->data<<" ";
    	temp = temp->link;
    }
}

int list::count()
{
	node *temp = p;
	int c = 0;
	while(temp != NULL)
	{
		temp= temp->link;
		c++;
	}return c;
}

void list::del(int num)
{
	node *old,*temp;
	temp = p;
	while(temp != NULL)
	{
		if(temp->data == num)
		{
			if(temp == p)
				p=temp->link;
			else
				old->link = temp->link;
			delete temp;
			return;
		}else
		{
			old=temp;
			temp=temp->link;
		}
	}cout<<"\n element "<<num<<" not found\n";
}

void list::delAlt(){
    if(p == NULL){
        cout<<"\nList does not exist";
        return;
    }
    int i = 0;
    for(node* cur = p; cur->link!=NULL; cur = cur->link,i++){
        if(i%2==0){
            node* temp = cur->link;
            cur->link = temp->link;
            delete temp;
        }
    }
}

void list::sortList(){
    if(p == NULL){
        cout<<"\nList does not exist";
        return;
    }
    for(node* temp1 = p;temp1!= NULL; temp1 = temp1->link){
        for(node* temp2 = p; temp2->link!= NULL; temp2 = temp2->link){
            if(temp2->data>temp2->link->data){
                int temp3 = temp2->data;
                temp2->data = temp2->link->data;
                temp2->link->data = temp3;
            }
        }
    }
}

void list::convert()
{
	node *r,*q,*prev;

	q = p;
	r = NULL;

	while(q != NULL)
	{
		prev = r;
		r = q;
        q=q->link;
        r->link = prev;
    }
	p = r;
}

list::~list()
{
	node *q;

	while(p != NULL)
	{
		q=p->link;
		delete p;
		p=q;
	}
}

int main()
{
	list l;

	l.append(14);
	l.append(30);
	l.append(25);
	l.append(42);
	l.append(17);

	cout<<"\n Elements in the list \n";
	l.display();

	l.addAtBeg(999);
	l.addAtBeg(888);
	l.addAtBeg(777);

	cout<<"\n Elements in list \n";
	l.display();

	l.addAfter(7,0);
	l.addAfter(2,1);
	l.addAfter(5,99);



	l.display();
    
    cout<<"\n Number of elements: \n"<<l.count();

	l.del(99);
	l.del(1);
	l.del(10);

	l.display();

	l.sortList();

	l.display();

	l.delAlt();

	l.display();

	cout<<"\n Number of elements: \n";

	cout<<l.count();

	l.convert();
	l.display();



	
}