//program5:- add two numbers represented by two linked lists where each node is a digit
#include <stdio.h>
#include <stdlib.h>
struct node *insert_node(struct node *head,int  data); //insert node at last
void display(struct node * head);//display linked list
struct node* initialize_list(struct node *head,int *nodecount);//creating lists.
void find_sum(struct node *p,struct node *q,int *overflow);//add two numbers represented by 2 linked lists.
struct node *insert_at_begining(struct node *head,int data);//inserts node at beginning
struct node* handle_unequal_length(int count1 ,int count2,struct node *head);//handle unequal length
struct node  //node structure
{
 int data;
 struct node *next;

};

int main()
{
    int nodecount1=0,nodecount2=0,overflow_node,count=0,overflow=0;
   struct node *head1=NULL;
   struct node *head2=NULL;
   struct node *pointer=NULL;
   printf("enter the numbers for first linked list \n");
   head1=initialize_list(head1,&nodecount1);
   printf("enter the numbers for second linked list \n");
   head2=initialize_list(head2,&nodecount2);
   printf(" list 1:\t");
     display(head1);
     printf("\n");
     printf(" list 2:\t");
     display(head2);
     if(head1==NULL||head2==NULL){exit(0);}//empty list cannot add.
if(nodecount1!=nodecount2)// to handle unequal lengths
{
nodecount1>nodecount2?(head2=handle_unequal_length( nodecount1 , nodecount2,head2)):(head1=handle_unequal_length( nodecount2 , nodecount1,head1));
}

     overflow_node=(head1->data+head2->data)/10;
     find_sum(head1,head2,&overflow);//finds sum
     if(overflow_node||overflow){head1=insert_at_begining(head1,1);}//handle leftmost most carry
     printf("\n \n sum:");
     printf("          ");
     display(head1);//display final result.


    return 0;
}
struct node* handle_unequal_length(int count1 ,int count2,struct node *head)
{
    int i=0;
    while(i<count1-count2)
    {
      head=insert_at_begining(head,0);
      i++;
    }
    return head;
}

 struct node *insert_at_begining(struct node *head,int data)//insert at beginning
 {
     struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->next=head;
     temp->data=data;
     head=temp;
     return head;

 }
void find_sum(struct node *p,struct node *q,int *overflow)
{
   struct node *headnode=p, *pointer=NULL;
   int carry;

   while(p!=NULL&&q!=NULL)//traverse till end of both  the lists. .
   {
       carry=(p->data+q->data)/10;//check carry
       if(carry)// if carry==1 then increment the contents from pointer node to current node-1.
       {
           while(pointer!=p)
           {
             if(pointer==NULL)//initializing pointer for the first time.
             {
                if(p==headnode){break;} //(conditions checking.)
               else{
                    pointer=headnode;
                if(carry){*overflow=1;}
                    }

             }
             pointer->data=(pointer->data+1)%10;
             pointer=pointer->next;
           }

       }
       p->data=(p->data+q->data)%10;
       if(p->data<9){pointer=p;}//maintain a pointer when the content <9 so that whenever  carry occurs,to increment it.
       p=p->next;
       q=q->next;

   }




}
struct node* initialize_list(struct node *head,int *nodecount)//creating  linked list.
{
    int data=0;
  printf("enter -1 to stop\n ");
   while(data!=-1)
  {
      scanf("%d",&data);
      if(data==-1)break;
      head=insert_node(head,data);
      *nodecount+=1;

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

