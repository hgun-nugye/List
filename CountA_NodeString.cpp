#include<stdio.h>
#include<stdlib.h>
struct nut
{
	char giatri;
	struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n);
int DemA(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	
	NhapList(&head, n);
	int dem=DemA(head, n);

	printf("Day la list vua nhap:\n");
	XemDS(head);
	
	if(dem>=0) printf("\n\nSo ky tu 'A' xuat hien trong list: %d",dem);
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
    char x;
    printf("Nhap vao so node: ");
    scanf("%d", &n);
    printf("Nhap vao list:\n");
    for (int i = 0; i < n; i++) 
		{
			fflush(stdin);
      scanf("%c", &x);
      nlist = (Node*)malloc(sizeof(Node));
      nlist->giatri = x;
      nlist->next = *head;
      *head = nlist;
    }
  return *head;
}

int DemA(Node *head, int n)
{
	int dem=0;
	Node *temp=head;
	while(temp!=NULL)
	{		
		//duyet qua cac ky tu
		if((temp->giatri)=='A') dem+=1;
		temp=temp->next;
	} 
	return dem;
}

Node *XemDS(Node *head)
{
	
	while (head!=NULL)
	{
		printf("%c\t", head->giatri);
		head=head->next;
	}
	return head;
}