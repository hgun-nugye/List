#include<stdio.h>
#include<stdlib.h>
struct nut
{
	int giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n);
Node *ChenPosition(Node *head,int p, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	int p;
	NhapList(&head, n);
	printf("Day la list vua nhap:\n");
	XemDS(head);
	
	do
	{
		printf("\nNhap vao gia tri phan tu Position: ");
		scanf("%d", &p);
	}while(p<0 || p>n-1);
	
	head=ChenPosition(head,p,n);	
	printf("Day la list vua chen phan tu:\n");
	XemDS(head);
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}

Node *NhapList(Node **head, int &n)
{
		int x;
  	Node* nlist;
    printf("Nhap vao so node: ");
    scanf("%d", &n);
    printf("Nhap vao list:\n");
    for (int i = 0; i < n; i++) 
		{
      scanf("%d", &x);
      nlist = (Node*)malloc(sizeof(Node));
      nlist->giatri = x;
      nlist->next = *head;
      *head = nlist;
    }
  return *head;
}
Node *ChenPosition(Node *head,int p, int n)
{
	int x;
	Node *newValue;
	printf("\nNhap vao gia tri phan tu can chen: ");
	scanf("%d", &x);
	
	newValue=(Node*)malloc(sizeof(Node));
	newValue->giatri=x;
	Node *temp1=head;
	Node *temp2=temp1->next;	
	if(p==0) 
	{
		newValue->next=head;
		head=newValue;
		return head;
	}
	for(int i=1; i<p && temp1->next!=NULL; i++)
	{
		temp1=temp1->next;
		temp2=temp2->next;
	}
	
	temp1->next=newValue;
	newValue->next=temp2;
	return head;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("%d\t", head->giatri);
		head=head->next;
	}
	return head;
}