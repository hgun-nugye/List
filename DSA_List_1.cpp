#include <stdio.h>
#include <stdlib.h>

struct nut {
    float giatri;
    struct nut *next;
};

typedef struct nut Node;

Node* RealNumber(Node** head) 
{
    Node* min = NULL; // khoi tao min=NULL
    Node* nlist, *temp;
    float x;
    int n;

    printf("Nhap vao so luong so thuc can luu tru: ");
    scanf("%d", &n);
    printf("Nhap vao list:\n");
    fflush(stdin);
    for (int i = 0; i < n; i++) 
		{
      scanf("%f", &x);
      nlist = (Node*)malloc(sizeof(Node));
      nlist->giatri = x;
      nlist->next = *head;
      *head = nlist;
      
      // cap nhat gia tri min neu gia tri moi them vao list nho hon min
        if (min == NULL || (*head)->giatri < min->giatri) {
            min = *head;
        }
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

int main() 
{
    int n;
    Node* head = NULL;
    Node* min = RealNumber(&head);

    if (min != NULL) printf("\nGia tri nho nhat: %.2f\n", min->giatri);
    else printf("Danh sach rong.\n");
    
    printf("\n");
		XemDS(head);

    // giai phong list
    while (head != NULL) 
		{
        Node* temp = head;
        head = head->next;
        free(temp);
    }
  return 0;
}