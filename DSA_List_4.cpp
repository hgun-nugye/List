#include<stdio.h>
#include<stdlib.h>
struct nut
{
	float giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *SumNegavNumber(Node **head);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	Node *sum=SumNegavNumber(&head);
	XemDS(head);
	
	if(sum!=NULL) printf("\n\nTong cac gia tri duong cua list: %.2f",sum->giatri);
	else printf("\nList rong!");
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}
Node *SumNegavNumber(Node **head)
{
	int n;
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	
	//thiet lap phan tu cho list
	float x, S=0;
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
		
		//Tinh tong cac so duong
		if((*head)->giatri<0)
		{
			S+= (*head)->giatri;
		}
	} 
	
	//khoi tao sum
	Node* sum;
	sum=(Node*)malloc(sizeof(Node));
	sum->giatri=S;
	sum->next=NULL;
	return sum;
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