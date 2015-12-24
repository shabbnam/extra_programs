// program2: circular linked list insert operations.
#include <stdio.h>
#include <stdlib.h>
struct node* insert_at_givenpos( struct node *head,int data,int pos,int *nodecount);//function prototype for inserting
void display(struct node* head);// function prototype for displaying
 struct node//node structure
{
    int data;
    struct node *next;

};
int main()
{

    struct node*head=NULL;
    int  nodecount=0,data,pos;
    printf("-1 to quit\n");
    while(1)
   {

    printf("enter the position \n");
    scanf("%d",&pos);
    if(pos==-1){break;}
    printf("enter the data \n");
    scanf("%d",&data);
    head=insert_at_givenpos(head, data,pos,&nodecount);
    printf(" number of nodes is %d \n",nodecount);
    display(head);


   }


}

 struct node* insert_at_givenpos( struct node *head,int data,int pos,int *nodecount)
 {
     struct node* temp=(struct node *)malloc(sizeof(struct node));
     temp->data=data;
     struct node* p=head;
     int count=1;

     if (head==NULL)//insert the first node.
     {
         head=temp;
         temp->next=temp;
     }
     else{
           if (pos==1||pos>*nodecount)//if position in which the node is to be inserted is at beginning or ending
           {

            while(p->next!=head)
             {
                 p=p->next;

             }
             p->next=temp;
             temp->next=head;
             if (pos==1){head=temp;}
           }

           else // node is to be inserted anywhere between existing nodes
           {
             while(count<pos-1)
             {
             p=p->next;count++;
             }
             temp->next=p->next;
             p->next=temp;

           }

         }
    *nodecount+=1;
     return head;
 }
 void display(struct node* head)//function to display the circular linked list.
 {
     struct node *temp=head;
     while(temp->next!=head)
     {

         printf("%d ---> ",temp->data);
         temp=temp->next;


     }
   printf(" %d \n",temp->data);



 }
