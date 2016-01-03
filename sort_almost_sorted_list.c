/*8.given a sorted linked list which is in ascending order but two numbers are changed,
ex:1->2->3->15->10->4->20
o/p:1->2->3->4->10->15->20
*/
#include <stdio.h>
#include <stdlib.h>
struct node *insert_node(struct node *head,int  data); //insert node at last
void display(struct node * head);//display linked list
struct node* initialize_list(struct node *head);//creating list.
void  fix_number1(struct node *p ,struct node**pointer,int *flag);
void swap(struct node *p,struct node *q);
struct node  //node structure
{
 int data;
 struct node *next;

};

int main()
{
    int flag=0;
    struct node *head=NULL,*q=NULL,*p;
    head=initialize_list(head);
    printf("\n  initial list: \n");
    display(head);//display the initial list.
    fix_number1(head,&q,&flag);//finds the first number to be swapped.(searches from the end)
    for( p=head;p->next!=q&&p->data<p->next->data;p=p->next);// finds the second number to be swapped.(searches from the beginning)
    swap(p,q);// swaps the two numbers to form a sorted ascending order list.
    printf("\n  \n final sorted list:");
    display(head);//display the final  sorted list .
    return 0;
}


void  fix_number1(struct node *p ,struct node**pointer,int *flag)//find the first number to be swapped.
{

 if(p->next==NULL)// base condition
   {
    return ;
   }
   else {fix_number1(p->next,pointer,flag);}//recursive  call
   /* goes till the end of the list and then returns back, finds the first number to be swapped*/

    struct node*q=p->next;
    if(q->data<p->data&&*flag==0)
    {
     *pointer=q; (*flag)++;
    }

}
void swap(struct node * p,struct node *q)
{
    int temp=p->data;
    p->data=q->data;
    q->data=temp;

}


struct node* initialize_list(struct node *head)//creating  linked list.
{
    int data=0;
  printf("enter -1 to stop\n ");
    printf("enter numbers :\n ");
   while(data!=-1)
  {
      scanf("%d",&data);
      if(data==-1)break;
      head=insert_node(head,data);


  }
  printf("\n");


return head;
}


struct node *insert_node(struct node *head,int  data) //insert node at last
{

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    struct node  *p=head;
    if(head==NULL)
    {
        temp->next=NULL;
        head=temp;
    }
    else
    {

    while(p->next!=NULL){p=p->next;}
    p->next=temp;
    temp->next=NULL;

    }

   return head;
}

void display(struct node * head)//display linked list
{
    struct node* temp=head;
    while(temp)
    {

        printf("%d ",temp->data);
        temp=temp->next;
    }


}


