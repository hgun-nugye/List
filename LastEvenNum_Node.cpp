#include<stdio.h>
#include<stdlib.h>
struct nut
{
	int giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n);
int LastEvenNumber(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	
	NhapList(&head, n);
	int num=LastEvenNumber(head,n);

	printf("Day la list vua nhap:");
	XemDS(head);
	
	if(num%2==0) printf("\n\nSo chan cuoi cung cua list: %d",num);
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
    int x;
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
int LastEvenNumber(Node *head, int n)
{
	int num=-1;
	Node *temp=head;
	while(temp!=NULL)
	{
			if((temp->giatri)%2==0)
			{
			num=(temp)->giatri;
			}
		temp=temp->next;
	}	
	return num;
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