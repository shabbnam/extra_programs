// program3 :- reversal of linked list using recursion
#include <stdio.h>
#include <stdlib.h>
struct node *insert_node(struct node *head,short data); //node creations
void display(struct node * head);//display linked list
void reverse_linked_list(struct node *p, struct node **head);//reverse the linked list

struct node  //node structure
{
 short  data;
 struct node *next;

};
int main()
{
  struct node *head=NULL;
  short  data;
  printf("enter -1 to stop \n \n ");
  while(1)
  {

      printf("enter  number  \n \n ");

      scanf("%hd",&data);
      if(data==-1)break;
      head=insert_node(head,data);
      display(head);
      printf("\n");

  }
   reverse_linked_list(head,&head);
   printf("reversed ");
   display(head);
  return 0;
}


void  reverse_linked_list(struct node *p, struct node **head)//reverse linked list
{


   if(p->next==NULL)// base condition
   {
       *head=p;

       return ;
   }
    reverse_linked_list(p->next,head);//recursive call
    struct node*q=p->next;
    q->next=p;
    p->next=NULL;


}
 struct node *insert_node(struct node *head,short data) //node creations
{

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    head==NULL ? (temp->next=NULL ):(temp->next=head);
    head=temp;


   return head;
}

void display(struct node * head)//display linked list
{
    struct node* temp=head;
    printf("linked list is  :");
    while(temp)
    {
        printf("%hd-->",temp->data);
        temp=temp->next;
    }

  printf("null");
}
