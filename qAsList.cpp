#include<iostream>

using namespace std;

class qlist
{
private:
	struct node{
		int data;
		node *link;
	}*front,*rear;
public:
	qlist();
	void addQ(int num);
	int delQ();
	~qlist();
};

qlist::qlist()
{
  front = rear = NULL;
}

void qlist::addQ(int num)
{
	node *temp;
	temp = new node;
	if(temp == NULL)
		cout<<"\n Queue is full \n";
   
    temp->data = num;
    temp->link = NULL;

    if(front == NULL)
    {
    	front =rear = temp;
    	return;
    }
    rear->link = temp;
    rear = rear->link;
}

int qlist::delQ(){

	if(front == NULL)
		cout<<"\n Queue is empty \n";
    
     node *temp;
     int item;

     item=front->data;
     temp = front;
     front = front->link;

     delete temp;
     return item;

}

qlist::~qlist()
{
	node *temp;

	while(front != NULL)
	{
		temp = front;
		front=front->link;
		delete temp;
	}
}

int main(){

	qlist q;

	q.addQ(12);
	q.addQ(13);
	q.addQ(15);
	q.addQ(16);
	q.addQ(156);

	int i=q.delQ();
	cout<<i<<" ";
	i=q.delQ();
	cout<<i<<" ";
	i =q.delQ();
	cout<<i<<" ";

}