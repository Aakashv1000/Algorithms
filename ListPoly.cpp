#include<iostream>

using namespace std;

class poly{
private:
	struct polynode{
		float coeff;
		int exp;
		polynode *link;
	}*p;
public:
poly();
void poly_append(float c,int e);
void display_poly();
void poly_add(poly &l1,poly &l2);
~poly();
};

poly::poly(){
	p = NULL;
}

void poly::poly_append(float c,int e){
	polynode *temp = p;

	if(temp == NULL)
	{
		temp = new polynode;
		p = temp;
	}else{
		while(temp->link == NULL)
			temp=temp->link;

		temp->link = new polynode;
		temp = temp->link;
	}

	temp->coeff = c;
	temp->exp = e;
	temp->link = NULL:
}

void display_poly()
{
	polynode *temp = p;
	int f = 0;
	cout<<endl;

	while(temp != NULL)
	{
		if(f!=0)
		{
			if(temp->coeff >0)
				cout<<"+";
			else
				cout<<"";
		}
		if(temp->exp !=0)
			cout<<temp->coeff<<"x^"<<temp->exp;
		else
			cout<<temp->coeff;
		temp = temp->link;
		f=1;
	}
}

void poly_add(poly &l1,poly &l2)
{
	polynode *z;

	if(l1.p == NULL && l2.p==NULL)
		return;

	polynode *temp1,*temp2;
	temp1=l1.p;
	temp2 = l2.p;

	while(temp1 != NULL && temp2 != NULL)

	{
		if(p == NULL)
		{
			p = new polynode;
			z = p;
		}else{
			z->link = new polynode;
			z=z->link;
		}

		if(temp1 ->exp <temp2->exp)
		{
			z->coeff = temp2->coeff;
			z->exp = temp2->exp;

			temp2 = temp2->link;
		}else
		{
			if(temp1->exp>temp2->exp)
			{
				z->coeff = temp1->coeff;
				z->exp = temp1 ->exp;

				temp1=temp1->link;
			}else{
				if(temp1->exp == temp2->exp)
				{
					z->coeff = temp1->coeff + temp2->coeff;
					x->exp = temp1->exp;

					temp1 = temp1->link;
					temp2 = temp2->link;
				}
			}
		}
	}

	while(temp1 != NULL)
	{
		if(p == NULL)
		{
			p = new polynode;
			z=p;
		}else
		{
			z->link = new polynode;
			z=z->link;
		}

		z->coeff = temp1->coeff;
		z->exp = temp1->exp;

		temp1=temp1->link;
	}

	while(temp2 != NULL)
	{
		if(p == NULL)
		{
			p = new polynode;
			z=p;
		}else{
			z->link = new polynode;
			z=z->link;
		}

		z->coeff = temp2->coeff;
		z->exp = temp2->exp;

		temp2=temp2->exp;
	}
	z->link = NULL;
}