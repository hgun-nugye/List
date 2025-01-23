#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct nut
{
	char a[21];
	struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n);
char ChuoiDaiNhat(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	
	NhapList(&head, n);
	
	printf("\nDay la list vua nhap:\n");
	XemDS(head);
	
	ChuoiDaiNhat(head,n);

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
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);	
	//thiet lap phan tu cho list
	char x[21];
	Node* newList;
	printf("Nhap vao cac chuoi (Enter khi het 1 chuoi):\n");
	
	//nhap list
	for(int i=0; i<n; i++)
	{
		fflush(stdin);
		gets(x);
		newList=(Node*)malloc(sizeof(Node));
		strcpy(newList->a,x);
		newList->next=(*head);
		(*head)=newList;
	}
	return *head;
}
char ChuoiDaiNhat(Node *head, int n)
{
	Node *temp=head;
	char copy[21];
	strcpy(copy,(temp)->a);
	int d=strlen(temp->a);
	while(temp!=NULL)
	{
		int len=strlen(temp->a);
		if(len>d )
		{
			d=len;
			strcpy(copy,(temp)->a);
		}
		temp=temp->next;
	}	
	printf("\n\n\nChuoi dai nhat la:");
	puts(copy);
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