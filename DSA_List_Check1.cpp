#include<iostream>
#include<stdlib.h>
using namespace std;
struct nut 
{
	float giatri;
	struct nut *next;
};
typedef struct nut Node;

//prototype
Node *Nhap(Node **head, int &n);
int Dem0(Node *head);
Node *Xem(Node *head);

int main()
{
	Node *head=NULL;
	int n;
	Nhap(&head,n);
	int dem=Dem0(head);
	cout<<"Danh sach vua nhap:\n";
	Xem(head);
	cout<<"\nSo luong so 0 la: "<<dem<<endl;
	
	Node*temp=new Node();
	temp=head;
	while(temp!=NULL)
	{
		free(temp);
		temp=temp->next;
	}
	free(head);
}
Node *Nhap(Node **head, int &n)
{
	float x;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>x;
		Node *newNode=new Node();
		newNode->giatri=x;
		newNode->next=*head;
		(*head)=newNode;
	}
	return *head;
}
int Dem0(Node *head)
{
	int dem=0;
	Node *temp=NULL;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->giatri==0) dem++;
		temp=temp->next;
	}
	return dem;
}
Node *Xem(Node *head)
{
	Node *temp;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->giatri<<"\t";
		temp=temp->next;
	}
}