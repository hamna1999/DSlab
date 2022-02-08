#include<stdio.h>
#include<stdlib.h>
struct node
{
    int a;
    struct node *next;
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

        printf("\n MENU DRIVEN \n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search\n8.Display\n9.Exit\n");
        printf("\nEnter choice\n");
        printf("\n**************************************************************\n");
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
        temp->a = item;
        temp->next = head;
        head = temp;
        printf("\n Inserted node");
        }


void lastinsert()
       {
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));

        printf("\n Invalid\n");
        scanf("%d",&item);
        ptr->a = item;
        if(head == NULL)
        {
            ptr -> next = NULL;
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
            ptr->next = NULL;
            printf("\nNode inserted");

        }
        }

void betweeninsert()
{
    int i,loc,item;
    struct node *ptr, *temp;
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
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted from the begining ...\n");
    }
}
void last_delete()
{
    struct node *ptr,*ptr1;
    if(head == NULL)
    {
        printf("\nlist is empty");
    }
    else if(head -> next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...\n");
    }

    else
    {
        ptr = head;
        while(ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr ->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from the last ...\n");
    }
}
void betweendelete()
{
    struct node *ptr,*ptr1;
    int loc,i;
    printf("\n Enter the location of the node after which want to perform deletion \n");
    scanf("%d",&loc);
    ptr=head;
    for(i=0;i<loc;i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if(ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
        }
    ptr1 ->next = ptr ->next;
    free(ptr);
    printf("\nDeleted node %d ",loc+1);
}
void search()
{
    struct node *ptr;
    int item,i=0,flag;
    ptr = head;
    if(ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search\n");
        scanf("%d",&item);
        while (ptr!=NULL)
            {
            if(ptr->a == item)
            {
                printf("item found at location %d ",i+1);
                flag=0;
            }
            else
            {
                flag=1;
            }
            i++;
            ptr = ptr -> next;
           }
        if(flag==1)
           {
            printf("Item not found\n");
           }
           }

          }

void display()
{
    struct node *ptr;
    ptr = head;
    if(ptr == NULL)
    {
        printf("empty");
    }
    else
    {
        printf("\n print values\n");
        while (ptr!=NULL)
        {
            printf("\n%d",ptr->a);
            ptr = ptr -> next;
        }
    }
}


