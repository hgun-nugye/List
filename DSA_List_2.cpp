#include<stdio.h>
#include<stdlib.h>
struct nut
{
	float giatri;
	struct nut *next;
};

typedef struct nut Node;

//prototype
Node *NhapList(Node** head, int &n);
Node *MaxNegavNumber(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	NhapList(&head, n);
	
	Node *Max=MaxNegavNumber(head, n);
	
	printf("\nDay la danh sach vua nhap:\n");
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

Node *NhapList(Node** head, int &n)
{
  	Node* nlist;
    float x;
    printf("Nhap vao so luong so thuc can luu tru: ");
    scanf("%d", &n);
    printf("Nhap vao list:\n");
    for (int i = 0; i < n; i++) 
		{
      scanf("%f", &x);
      nlist = (Node*)malloc(sizeof(Node));
      nlist->giatri = x;
      nlist->next = *head;
      *head = nlist;
    }
  return *head;
}
Node *MaxNegavNumber(Node *head, int n)
{
	
	//khoi tao max
	Node* Max=NULL;
	Node *temp=head;
	while(temp!=NULL)
	{
		//Tim so am lon nhat
		if((Max==NULL||Max->giatri<(temp)->giatri)&& (temp)->giatri<0 )
		{
			Max=(temp);
		}
		temp=temp->next;
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