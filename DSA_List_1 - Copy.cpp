#include <stdio.h>
#include <stdlib.h>

struct nut {
    float giatri;
    struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n); 
int RealNumber(Node*head);
int Real(Node*head);
void XemDS(Node* head);

int main() 
{
    int n;
    Node *head = NULL;
    NhapList(&head,n);
    int min = RealNumber(head);
    int max =Real(head);

		printf("\nDay la danh sach vua nhap:\n");
		XemDS(head);
		printf("\n\nGia tri duong nho nhat: %d\n", min);
		printf("\n\nGia tri duong nho nhat: %d\n", max);
   
    //giai phong list
    while (head != NULL) 
		{
        Node* temp = head;
        head = head->next;
        free(temp);
    }
  return 0;
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
int RealNumber(Node *head)
{
	int dem=0;
	Node *temp;
	temp=head;
	while(temp!=NULL)
		{    
      if(temp->giatri<0)
      dem ++;
      temp=temp->next;
    }
    
  return dem; 
}
int Real(Node *head)
{
	int dem=0;
	Node *temp;
	temp=head;
	while(temp!=NULL)
		{    
      if(temp->giatri==0)
      dem ++;
      temp=temp->next;
    }
    
  return dem; 
}
void XemDS(Node* head)
{
  while (head!= NULL) 
	{
    printf("%.2f\t", head->giatri);
    head=head->next;
  }
}
