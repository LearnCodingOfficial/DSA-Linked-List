#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 9)
    {
        printf("\n...Choose One Option from the following List...\n");
        printf("\nl.Insert in begining\n2.Insert at last\n3.Insert item at any location\n4.Delete from Beginning\n5.Delete from last\n6.Delete item from any location\n7.Search\n8.Show\n9.Exit\n");

        printf("\nEnter your choice: ");
        scanf("\n%d", &choice); // choice=1

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            random_insert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
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
            printf("Invalid Choice..");
        }
    }
    return 0;
}
void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("Item inserted");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            printf("Item inserted");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = NULL;
            printf("Item inserted");
        }
    }
}
void random_insert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("Enter Value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location: ");
        scanf("%d", &loc);
        temp = head;
        for (i = 1; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("Item inserted");
    }
}
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("Item deleted from the begining ...\n");
    }
}
void last_delete()
{
    struct node *ptr, *ptrl;
    if (head == NULL)
    {
        printf("\nList is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ..\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptrl = ptr;
            ptr = ptr->next;
        }
        ptrl->next = NULL;
        free(ptr);
        printf("Item deleted\n");
    }
}
void random_delete()
{
    struct node *ptr, *ptrl;
    int loc, i;

    printf("\n Enter the location: ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptrl = ptr;
        ptr = ptr->next;
        if (ptr == NULL)
        {
            printf("\nCan't delete");
            return;
        }
    }
    ptrl->next = ptr->next;
    free(ptr);
    printf("Item deleted at loc %d", loc);
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter searching item: ");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("Item found at location %d ", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nPrinting values while (ptr!=NULL).\n");
        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}