#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a;
    struct node *next;
    struct node *prev;
};
struct node *head;

void beginsert ();
void lastinsert ();
void betweeninsert();
void begin_delete();
void last_delete();
void betweendelete();
void display();
void search();
void main ()
{
    int choice =0;
    while(choice != 9)
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search\n8.Display\n9.Exit\n");
        printf("\nEnter choice\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            betweeninsert();
            break;
            case 4:
            begin_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            betweendelete();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Invalid..");
        }
        }
        }
void beginsert()
       {
    struct node *temp;
    int item;
    temp = (struct node *) malloc(sizeof(struct node *));

        printf("\nEnter value\n");
        scanf("%d",&item);
        temp->a=item;
        head=temp;
        temp->next=NULL;
        printf("node inserted\n");
       }
void lastinsert()
       {
    struct node *ptr,*temp,*prev;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

        printf("\nEnter the value\n");
        scanf("%d",&item);
        ptr->a = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
            ptr -> prev = NULL;
            head = ptr;
            printf("\nNode inserted");
        }
        else
        {
            temp = head;
            while (temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = ptr;
            ptr->prev = head;
            ptr->next = NULL;
            printf("\nNode inserted");

        }
        }
void betweeninsert()
{
    int i,loc,item;
    struct node *ptr, *temp, *prev;
    ptr = (struct node *) malloc (sizeof(struct node));

        printf("\nEnter element value");
        scanf("%d",&item);
        ptr->a = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d",&loc);
        temp=head;
        for(i=0;i<loc;i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }

        }
        ptr ->next = temp ->next;
        temp ->next = ptr;
        temp ->prev = ptr;
        printf("\nNode inserted");
    }
void begin_delete()
       {
    struct node *ptr;
    if(head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        ptr->prev = NULL;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
