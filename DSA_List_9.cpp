#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nut
{
	char a[21];
	int vitri;
	struct nut *next;
};

typedef struct nut Node;

Node *ChuoiNganNhat(Node **head);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	Node *dem=ChuoiNganNhat(&head);

	printf("\nDay la list vua nhap:\n");
	XemDS(head);
	
	if(dem!=NULL) printf("\n\nChuoi ngan nhat la chuoi so: %d",dem->vitri);
	else printf("\nList rong!");
	
	//giai phong list
	while(head!=NULL)
	{
		Node* temp=head;
		head=head->next;
		free(temp);
	}
}
Node *ChuoiNganNhat(Node **head)
{
	int n;
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	fflush(stdin);	
	//thiet lap phan tu cho list
	char x[21];
	int d=20, idx=0;
	Node* newList;
	printf("Nhap vao cac chuoi (Enter khi het 1 chuoi):\n");
	fflush(stdin);
	
	//nhap list
	for(int i=0; i<n; i++)
	{
		gets(x);
		newList=(Node*)malloc(sizeof(Node));
		strcpy(newList->a,x);
		newList->next=(*head);
		(*head)=newList;
	int len=strlen((*head)->a);
		if(len<d )
		{
			d=len;
			idx=i;
		}
	}

	Node* dem;
	dem=(Node*)malloc(sizeof(Node));
	dem->vitri=n-idx;
	dem->next=NULL;
	return dem;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("%s\t", head->a);
		head=head->next;
		
	}
	return head;
}