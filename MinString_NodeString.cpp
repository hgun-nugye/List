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

Node *NhapList(Node** head, int &n);
int ChuoiNganNhat(Node *head, int n);
Node *XemDS(Node *head);

int main()
{
	int n;
	Node *head=NULL;
	
	NhapList(&head, n);
	int dem=ChuoiNganNhat(head, n);

	printf("\nDay la list vua nhap:\n");
	XemDS(head);
	
	if(dem>0) printf("\n\nChuoi ngan nhat la chuoi so: %d",dem);
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
	do
	{
		printf("Nhap vao so luong phan tu cua danh sach: ");
		scanf("%d", &n);
	} while(n<0);
	fflush(stdin);	
	//thiet lap phan tu cho list
	char x[21];
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
	}
	return *head;
}
int ChuoiNganNhat(Node *head, int n)
{
	int idx=1, i=1;
	Node *temp=head;
	int d=strlen(temp->a);
	while(temp!=NULL)
	{
		int len=strlen(temp->a);
		if(len<d)
		{
			d=len;
			idx=i;
		}
		i++;
		temp=temp->next;
	}

	return idx;
}

Node *XemDS(Node *head)
{
	while (head!=NULL)
	{
		printf("%s\t\t", head->a);
		head=head->next;
		
	}
	return head;
}