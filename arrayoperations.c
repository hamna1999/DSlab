#include<stdio.h>
void main()
{
int array[100],val,choice=1,i,n,ch,pos,flag=0;
printf("Enter the number of elements in array");
scanf("%d",&n);
printf("Enter %d elements \n",n);
for(i=0;i<n;i++)
scanf("%d",&array[i]);
while(choice>0 && choice<6)
{
printf("\n 1.Insertion \n 2.Traversal \n 3.DEletion \n 4.Searching \n 5.Exit \n");
printf("Enter your choice");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the location \n");
scanf("%d",&pos);
printf("Enter the value to insert \n");
scanf("%d",&val);
for(i=n-1;i>=pos-1;i--)
{
array[i+1]=array[i];
}
array[pos-1]=val;
printf("After insertion:\n");
for(i=0;i<n+1;i++)
{
printf("%d",array[i]);
}
break;
case 2:
printf("Resultant array is:\n");
for(i=0;i<n;i++)
{
printf("%d",array[i]);
}
break;
case 3:
printf("Enter the location to delete elemnts\n");
scanf("%d",&pos);
for(i=pos-1;i<n;i++)
{
array[i]=array[i+1];
}
printf("Resultant array\n");
for(i=0;i<n-1;i++)
{
printf("%d\n",array[i]);
}
break;
case 4:
printf("Enter the elemnts to search\n");
scanf("%d",&ch);
for(i=0;i<n;i++)
{
    if(array[i]==ch)
        {
        flag=i;
        if(flag!=0)
{
printf("%d found at %d position\n",ch,i+1);
}
else
printf("not found");
}
}
break;
case 5:
exit(0);
break;
default:
printf("ERROR!!");
}
}
}



