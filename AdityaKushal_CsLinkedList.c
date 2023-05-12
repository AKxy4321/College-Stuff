#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int data;
}n;

n* insert_back(n* head, int val);
n* insert_after(n* head, int val, int key);
n* delete_after(n* head, int key);

void display(n* head);

int main()
{
    n *head = NULL;
    head = insert_back(head,10);
    while(1)
    {
        int c;
        printf("Enter 1 to insert after, 2 to delete after, 3 to display , 4 to exit\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                int val, key;
                printf("Enter val and key\n");
                scanf("%d %d", &val, &key);
                head = insert_after(head, val, key);
                break;
            }
            case 2:
            {
                int key;
                printf("Enter key\n");
                scanf("%d",&key);
                head = delete_after(head, key);
                break;
            }
            case 3:
            {
                display(head);
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("Wrong Input\n");
            }
        }
    }
    head = insert_after(head,30,10);
    head = insert_after(head,50,30);
    display(head);
}

n* insert_back(n* head, int val)
{
    n* n1 = (n*)malloc(sizeof(n));
    n1->data = val;
    if(head == NULL)
    {
         head = n1;
         n1->next = head;
    }
    else
    {
        n* curr = head;
        while(curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = n1;
        n1->next = head;
    }
    return head;
}

n* insert_after(n* head, int val, int key)
{
    n* n1 = (n*)malloc(sizeof(n));
    n1->data = val;
    n* curr = head;
    do
    {
        if(curr->data == key)
        {
            n1->next = curr->next;
            curr->next = n1;
            return head;
        }
        curr = curr->next;
    }while(curr != head);
    printf("%d was not found\n",key);
    return head;
}

n* delete_after(n* head, int key)
{
    n* curr = head;
    n *del = NULL;
    do
    {
        if(curr->data == key)
        {
            del = curr->next;
            if(curr->next == head)
            {
                head = del->next;
            }
            curr->next = del->next;
            free(del);
            return head;
        }
        curr = curr->next;
    }while(curr != head);
    printf("%d was not found\n",key);
    return head;
}

void display(n* head)
{
    n* curr = head;
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d ",curr->data);
        curr = curr->next;
    }while(curr != head);
    printf("\n");
}
