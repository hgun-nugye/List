#include<stdio.h>
#include<stdlib.h>
struct nut
{
	char giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *DemA(Node **head);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	Node *dem=DemA(&head);

	printf("Day la list vua nhap:");
	XemDS(head);
	
	if(dem!=NULL) printf("\n\nSo ky tu xuat hien trong list: %d",dem->giatri);
	else printf("\nList rong!");
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}
Node *DemA(Node **head)
{
	int n;
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	fflush(stdin);	
	//thiet lap phan tu cho list
	char x;
	int d=0;
	Node* newList;
	printf("Nhap vao gia tri cac phan tu cua list:\n");
	fflush(stdin);
	for(int i=0; i<n; i++)
	{
		scanf("%c", &x);
		newList=(Node*)malloc(sizeof(Node));
		newList->giatri=x;
		newList->next=(*head);
		(*head)=newList;
		
		//duyet qua cac ky tu
		if(((*head)->giatri)=='A') d++;
	} 

	//khoi tao index
	Node* dem;
	dem=(Node*)malloc(sizeof(Node));
	dem->giatri=d;
	dem->next=NULL;
	return dem;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("\t%c", head->giatri);
		head=head->next;
	}
	return head;
}