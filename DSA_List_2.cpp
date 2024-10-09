#include<stdio.h>
#include<stdlib.h>
struct nut
{
	float giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *MaxNegavNumber(Node **head);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	Node *Max=MaxNegavNumber(&head);
	XemDS(head);
	
	if(Max!=NULL) printf("\n\nGia tri am lon nhat cua list la: %.2f",Max->giatri);
	else printf("\nList rong!");
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}
Node *MaxNegavNumber(Node **head)
{
	int n;
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	
	//thiet lap phan tu cho list
	float x;
	//khoi tao max
	Node* Max=NULL;
	Node* newList;
	printf("Nhap vao gia tri cac phan tu cua list:\n");
	fflush(stdin);
	for(int i=0; i<n; i++)
	{
		scanf("%f", &x);
		newList=(Node*)malloc(sizeof(Node));
		newList->giatri=x;
		newList->next=(*head);
		(*head)=newList;
		
		//Tim so am lon nhat
		if((Max==NULL||Max->giatri<(*head)->giatri)&& (*head)->giatri<0 )
		{
			Max=(*head);
		}
	}
	return Max;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("%.2f\t", head->giatri);
		head=head->next;
	}
	return head;
}