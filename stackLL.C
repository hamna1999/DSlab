#include<stdio.h>
#include<stdlib.h>

    struct node
    {
        int data;
        struct node *next;
    };

  struct node *top,*newnode,*temp;

    void push();
    void display();
    void pop();

    int main()
    {
       int choice =0;
       while(choice != 3)
        {
           printf("\n MENU DRIVEN \n");
           printf("\n1.PUSH\n2.POP\n3.DISPLAY\n");
           printf("\nEnter choice\n");
           printf("\n*************************************\n");
           scanf("\n%d",&choice);

           switch(choice)
           {
            case 1: push();
                    break;

            case 2: pop();
                   break;


            case 3: display();
                   break;


            case 4: exit(0);
                    break;

            default:printf("invalid.....");

           }
        }
        return 0;
    }


    void push()
    {
         int choice=1;
         while(choice!=0)
         {
          newnode=(struct node*)malloc(sizeof(struct node));
          printf("Enter the item ");
          scanf("%d",&newnode->data);

            if(top==0)
            {
             newnode->next=0;
             top=newnode;
            }
            else
            {
                newnode->next=top;
                top=newnode;
            }
              printf("if you want to continue(1/0)");
            scanf("%d",&choice);
          }
    }

    void pop()
    {
        struct node *temp;
        if(top==0)
        {
            printf("Stack Underflow");
        }
        else
        {
            temp=top;
            top=temp->next;
            free(temp);
        }
    }

    void display()
    {

      temp=top;
    while(temp!=0)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
    }
