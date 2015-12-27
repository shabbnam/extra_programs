
//program 7:write a program to merge two linked lists  of sorted order.
//ex1: list1: 2 4 6 8 10 , list2: 1 3 5 17  29 63
//     merged list: 1 2 3 5 6 8 10 17 29 63
//ex2: list1: 10 8 6 4 2 , list2: 63 29 17 5 3 1
//      merged list: 63 29 17 10 8 6 5 4 2 1
#include <stdio.h>
#include <stdlib.h>
struct node* initialize_list(struct node *head);//creating  linked list.
struct node *insert_node(struct node *head,int  data); //insert node at last
void display(struct node * head);//display linked list
struct node *merge(struct node*head1,struct node*head2,int flag);//merge either in ascending or descending
int compare(int a,int b,int flag);                                                             //depending on input.

struct node
{
    int data;
    struct node*next;
};

int main()
{

  struct node *head1=NULL,*head2=NULL,*result=NULL;
  int flag;
  printf("enter the numbers in sorted order for linked list1\n \n ");
  head1=initialize_list(head1);//initialize list1
  printf("enter the numbers in sorted order for linked list2\n \n ");
  head2=initialize_list(head2);//initialize list2
  if(head1!=NULL&&head2!=NULL)
 {
  printf("list1 before merging:  ");
  display(head1);
  printf("\n");
  printf("list2 before merging:  ");
  display(head2);
  flag=check_order(head1,head2);
  result=merge(head1,head2,flag);
   printf("\n");
   printf(" final list after merging:  ");
  display(result);
 }
 else if (head1==NULL){display(head2);}
 else if(head2==NULL){display(head1);}
 else
 {
    printf("lists empty");
 }
    return 0;
}


struct node *merge(struct node*head1,struct node*head2,int flag)
//merges the list either in ascending or descending order based on flag value
{
	struct node *temp,*head;
	       /* flag value determines whether the lists are in ascending or descending order.
     ex: if flag=0, both lists are in descending order
    now it checks whether head1->data > head2->data and proceeds.

    ex: if flag=1 then both lists are   in ascending order
     now it checks whether head1->data < head2->data and proceeds.
        */

	if(compare(head1->data,head2->data,flag)){

        temp=head1;
		head1=head1-> next;
	}
	else{
		temp=head2;
		head2=head2-> next;
	}

	head=temp;  //head  is the  merged node which points to beginning of final merged list

while(head1&&head2){
		if(compare(head1->data,head2->data,flag)){
			temp -> next = head1;
			temp = head1;              //update temp
			head1 = head1->next;       //move head1 to next node
		}
		else{
			temp -> next = head2;
			temp= head2;         //update temp
			head2 = head2->next; //move  head2 to next node
		}
	}
	if(!head1){
		temp-> next= head2; //attach leftover nodes of head2 if any
	}
	else if(!head2){
		temp-> next= head1;  //attach leftover nodes of head1 if any
	}
	return head;
}

int check_order(struct node*head1,struct node *head2)

{
    int flag;
    for(;head1->next!=NULL&&head1->data<head1->next->data;head1=head1->next);//check if list1 is in ascending
    for(;head2->next!=NULL&&head2->data<head2->next->data;head2=head2->next);//check if list2 is in ascending
   ( (head1->next)==NULL&&(head2->next)==NULL)?(flag=1):(flag=0);
    return flag;

}
int compare(int a,int b,int flag)
{
    if(flag==0) {return a>b?1:0;}
    else { return a<b?1:0;}


}
struct node* initialize_list(struct node *head)//creating  linked list.
{
    int data;
  printf("enter -1 to stop\n ");
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

