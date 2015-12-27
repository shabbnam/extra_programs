//program6: given three numbers n1,n2,r . merge the table of n1 and n2 and find the r-th number.
// in merging it should eliminate duplicate values(table consists of the multiples of those numbers) .
// sample input: n1=5 , n2=3 ,r=5
//output list:3 5 6 9 10
//output :10


#include <stdio.h>
#include <stdlib.h>
struct node  //node structure
{
 int data;
 struct node *next;

};
void display_reverse(struct node *head);//display linked list
struct node *insert_at_begining(struct node *head,int data);//inserts node at beginning.
struct node * case_1(int big,int small,int count,struct node *head);// handles factor ,number input
struct node * case_2(int number1,int number2,int count,struct node *head);// handles any input. except case1

int main()
{
    struct node *head=NULL;
    int number1,number2,count;
    printf("enter the first number\n");
    scanf("%d",&number1);
    printf("enter the second number\n");
    scanf("%d",&number2);
    printf("enter the count of nodes\n");
    scanf("%d",&count);
    //case1 :when any one of the number is a factor of another number.
    //case2: when no number is factor of other.
    if(number1!=number2&&count!=0)//if numbers are not equal
    {
    number1%number2==0? head=case_1(number1,number2,count,head):(number2%number1==0)?(head=case_1(number2,number1,count,head)):(head=case_2(number1,number2,count,head));
    printf(" linked list:  \n");
    display_reverse(head);
    printf(" \n \n output is  %d  ",head->data);
    }
    else{
        printf(" no merge table \n");
    }



    return 0;
}

struct node * case_1(int big,int small,int count,struct node *head)//handles factor,number input
{
    short int i=0;
    short int inc=small;
    head=insert_at_begining(head,small);i++;
    while(i<count)
    {
        small+=inc;
        if(small%big!=0)
        {head=insert_at_begining(head,small);i++;}

    }
    return head;

}
void display_reverse(struct node * head)//display linked list
{
    struct node* temp=head;
    if(temp==NULL)
    {
    return;
    }

    else{
        display_reverse(temp->next);
        printf("%d  ",temp->data);
    }


}
 struct node *insert_at_begining(struct node *head,int data)//insert at beginning
 {
     struct node *temp=(struct node *)malloc(sizeof(struct node));
     temp->next=head;
     temp->data=data;
     head=temp;
     return head;

 }
 struct node * case_2(int number1,int number2,int count,struct node *head)//handles any input except case1 i/p
 {
    int nodes=0,i=number1,j=number2;
    while(nodes<count)
    {
        if(i%number2!=0 && j%number1!=0)//checks , compares,adds nodes to linked list
        {
            i<j?(head=insert_at_begining(head,i),i+=number1):(head=insert_at_begining(head,j),j+=number2);
            nodes++;
        }
        else if (j%number1==0){j+=number2;}// if duplicate, skips.
        else {i+=number1;}

    }


  return head;
 }
