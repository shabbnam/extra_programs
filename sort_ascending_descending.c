//sorts the list, initially all nodes are in ascending order and then in descending order.
//sample input: 20 70 100 90 80 5 2 1 ->null.
//sample output:1 2 5 20 70 80 90 100 ->null.
#include <stdio.h>
#include <stdlib.h>
struct node *insert_node(struct node *head,int  data); //insert node at last
void display(struct node * head);//display linked list
struct node *sort_list(struct node *head);//sort the list
struct node  //node structure
{
 int data;
 struct node *next;

};

int main()
{
    int data=0,nodecount=0;
   struct node *head=NULL;
   printf("enter -1 to stop \n \n ");
    while(1)
  {

      printf("enter the numbers first in ascending and then in descending  sequence\n \n ");

      scanf("%d",&data);
      if(data==-1)break;
      head=insert_node(head,data);
      nodecount++;


  }
  if(head==NULL)
  {
      printf("list empty");
      exit(0);
  }
  if(nodecount==1)// to handle the sample  input :2->null
  {
      display(head);

  }
  else if(nodecount==2)//to handle the  sample input :2 ->1->null
  {
      if(head->data>head->next->data)
      {
          data= head->data;
          head->data=head->next->data;
          head->next->data=data;
      }
       display(head);
  }
  else{
  display(head);
  head=sort_list(head);
  printf("\n");
  printf(" sorted :");
  display(head);
    return 0;
  }
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
struct node *sort_list(struct node *head)//sort list
{

    struct node *q,*breakptr,*p=head,*temp,*t;
    int flag=1;
    while(p->data<p->next->data){p=p->next;}
    breakptr=p->next;// points to the node from where descending order starts
    while(breakptr)// runs till it becomes null
    {
        q=breakptr;

        breakptr=breakptr->next;
        for(temp=head;q->data>temp->data;t=temp,flag=0,temp=temp->next);// finds the position where the data should be inserted.
        if(flag==0)//positions between existing nodes
        {
            q->next=t->next;// adjusting links.
            t->next=q;
        }

        else// at the beginning.
        {
            q->next=head;
            head=q;
        }
        flag=1;

    }

    p->next=NULL;
    return head;
}

void display(struct node * head)//display linked list
{
    struct node* temp=head;
    printf("linked list is  :");
    while(temp)
    {

        printf("%d-->",temp->data);
        temp=temp->next;
    }

  printf("null");
}


