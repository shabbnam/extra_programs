// program1 :- find median of a sorted linked list
#include <stdio.h>
#include <stdlib.h>

struct node  //node structure
{
 float data;
 struct node *next;

};
void find_order(struct node  *head, int *ascending)//function to check whether the list is in ascending order.
{
   struct node *p=head;
   if (p->next==NULL)return;

    while(p->next!=NULL&&p->data > p->next->data)
    {
      p=p->next;

    }
    if(p->next!=NULL){*ascending=1;}

}

 struct node *insert_node(struct node *head,float data) //node insertions(beginning)
{

    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    head==NULL ? (temp->next=NULL ):(temp->next=head);
    head=temp;


   return head;
}

float find_median(struct node * head)// finding median
{
     float median;
    struct node *fastptr=head,*slowptr=head;
    /* fastptr will jump two nodes as the  slowptr jumps one node..
    finally median will be the data in the node pointed by slow ptr in case of odd number of nodes
    and sum of slowptr's data and its adjacent node's data divided by 2 in case of even number of nodes*/
    while(1)
    {
        if(fastptr->next==NULL||fastptr->next->next==NULL)break;
          fastptr = fastptr->next->next;
          slowptr =slowptr->next;
    }
   fastptr->next==NULL?(median=slowptr->data):(median=(slowptr->data+slowptr->next->data)/2);
   return median;

}



void display(struct node * head)//display linked list
{
    struct node* temp=head;
    printf("linked list is  :");
    while(temp)
    {
        printf("%f-->",temp->data);
        temp=temp->next;
    }

  printf("null");
}

int main()
{
  struct node *head=NULL;
  float data=0;
  int ascending=0;
  while(data!=-1)
  {

      printf("enter the number in sorted order \n \n ");
      printf("enter -1 to stop \n \n ");
      scanf("%f",&data);
      if(data==-1)break;
      head=insert_node(head,data);

  }
 if (head==NULL)// to terminate the program if linked list is not created  (number of nodes=0)
 {
     printf("list not created..cannot find median");
     exit(0);
 }
 find_order(head,&ascending);// to check if list is in ascending order

  if(ascending==0)
  {

  display(head);
  printf(" \n the median is %f",find_median(head));
  }
  else{
    printf("list is not in ascending order");
  }


    return 0;
}
