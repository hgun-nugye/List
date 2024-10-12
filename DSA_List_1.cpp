#include <stdio.h>
#include <stdlib.h>

struct nut {
    float giatri;
    struct nut *next;
};

typedef struct nut Node;

Node *NhapList(Node** head, int &n); 
Node* RealNumber(Node*head, int n);
void XemDS(Node* head);

int main() 
{
    int n;
    Node *head = NULL;
    NhapList(&head,n);
    Node* min = RealNumber(head,n);

		printf("\nDay la danh sach vua nhap:\n");
		XemDS(head);
	
    if (min != NULL) printf("\n\nGia tri duong nho nhat: %.2f\n", min->giatri);
    else printf("Danh sach rong.\n");
    
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
Node* RealNumber(Node*head, int n)
{
	Node *min = NULL; // khoi tao min=NULL
	Node *temp;
	temp=head;
	while(temp!=NULL)
		{    
      // cap nhat gia tri min neu gia tri moi them vao list nho hon min
        if ((min == NULL || (temp)->giatri < min->giatri) && (temp)->giatri>0) 
				{
          min = temp;
        }
        temp=temp->next;
    }
  return min; 
}
void XemDS(Node* head)
{
  while (head!= NULL) 
	{
    printf("%.2f\t", head->giatri);
    head=head->next;
  }
}
