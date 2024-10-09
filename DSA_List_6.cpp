#include<stdio.h>
#include<stdlib.h>
struct nut
{
	int giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *LastEvenNumber(Node **head);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	Node *index=LastEvenNumber(&head);

	printf("Day la list vua nhap:");
	XemDS(head);
	
	if(index!=NULL) printf("\n\nSo chan cuoi cung cua list: %d",index->giatri);
	else printf("\nList rong!");
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}
Node *LastEvenNumber(Node **head)
{
	int n;
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	fflush(stdin);	
	//thiet lap phan tu cho list
	int x, in=0;
	Node* newList;
	printf("Nhap vao gia tri cac phan tu cua list:\n");
	fflush(stdin);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &x);
		newList=(Node*)malloc(sizeof(Node));
		newList->giatri=x;
		newList->next=(*head);
		(*head)=newList;
	} 
	
	for(int i=0; i<n; i++)
	{
		while(newList!=NULL)
		{
			if((newList->giatri)%2==0)
			{
			in=(newList)->giatri;
			}
		newList=newList->next;
		}
	} 
	
	//khoi tao index
	Node* index;
	index=(Node*)malloc(sizeof(Node));
	index->giatri=in;
	index->next=NULL;
	return index;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("\t%d", head->giatri);
		head=head->next;
	}
	return head;
}