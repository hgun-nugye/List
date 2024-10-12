#include<stdio.h>
#include<stdlib.h>
struct nut
{
	float giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n); 
float SumPosNumber(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	NhapList(&head, n);
	float sum=SumPosNumber(head,n);
	
	printf("\nDay la danh sach vua nhap:\n");
	XemDS(head);
	
	if(sum!=0) printf("\n\nTong cac gia tri duong cua list: %.2f",sum);
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
float SumPosNumber(Node *head, int n)
{
	float S=0;
	Node *temp=head;
	while(temp!=NULL)
	{
		//Tinh tong cac so duong
		if(temp->giatri>0)
		{
			S+= temp->giatri;
		}
		temp=temp->next;
	} 
	return S;
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