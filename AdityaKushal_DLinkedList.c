// 35 lines - Declarations
// 108 lines - Menu Driven Programming
// 225 lines - Code
//     9 lines - Spaces
//     7 lines - Create List
//     4 lines - Is Empty
//     4 lines - Only One
//    20 lines - Insert Front
//    20 lines - Insert Back
//    41 lines - Insert Pos
//    21 lines - Delete Front
//    21 lines - Delete Back
//    44 lines - Delete Pos
//    17 lines - Display Front
//    17 lines - Display Back
// 3 libraries, 2 structures, 10 functions

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    struct node *prev;
    int n;
    struct node *next;
}n;

typedef struct list
{
    n *start;
    int num;
    n *end;
}l;

l* create_list();

void insert_back(l *iback);
void insert_front(l *ifront);
void insert_position(l *ipos);

void delete_front(l *delfront);
void delete_back(l *delback);
void delete_position(l *delpos);

void display_front(l *dfront);
void display_back(l *dback);

bool is_empty(l *empt);
bool only_one(l *one);

int main()
{
    l *list;
    list = create_list();
    for(;;)
    {
        int choice;
        printf("Enter 1 to INSERT, 2 to DELETE, 3 to DISPLAY and 4 to EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter 1 to insert_front, 2 to insert_back and 3 to insert_position\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        insert_front(list);
                        break;
                    }
                    case 2:
                    {
                        insert_back(list);
                        break;
                    }
                    case 3:
                    {
                        insert_position(list);
                        break;
                    }
                    default:
                    {
                        printf("Invalid Input\n");
                        break;
                    }                    
                }
                list->num++;
                break;
            }
            case 2:
            {
                printf("Enter 1 to delete_front, 2 to delete_back, 3 to delete_position\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        delete_front(list);
                        break;
                    }
                    case 2:
                    {
                        delete_back(list);
                        break;
                    }
                    case 3:
                    {
                        delete_position(list);
                        break;
                    }
                    default:
                    {
                        printf("Invalid Input\n");
                        break;
                    }
                }
                list->num--;
                break;
            }
            case 3:
            {
                printf("Enter 1 to display_front and 2 to display_back\n");
                scanf("%d",&choice);
                switch(choice)
                {
                    case 1:
                    {
                        display_front(list);
                        break;
                    }
                    case 2:
                    {
                        display_back(list);
                        break;
                    }
                    default:
                    {
                        printf("Invalid Input\n");
                        break;
                    }
                }
                break;
            }
            case 4:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid Input\n");
                break;
            }
        }
    }
}

l* create_list()
{
    l *l1 = (l *)malloc(sizeof(l));
    l1->num = 0;
    l1->start = NULL, l1->end = NULL;
    return l1;
}

bool is_empty(l *empt)
{
    return empt->num == 0;
}

bool only_one(l *one)
{
    return one->num == 1;
}

void insert_front(l *ifront)
{
    int e;
    printf("Enter element\n");
    scanf("%d",&e);
    n *n1 = (n *)malloc(sizeof(n));
    n1->n = e;
    n1->prev = NULL;
    printf("%d is inserted\n",e);
    if(is_empty(ifront))
    {
        n1->next = NULL;
        ifront->start = n1;
        ifront->end = n1; 
        return;
    }
    ifront->start->prev = n1;
    n1->next = ifront->start;
    ifront->start = n1;
}

void insert_back(l *iback)
{
    int e;
    printf("Enter element\n");
    scanf("%d",&e);
    n *n1 = (n *)malloc(sizeof(n));
    n1->n = e;
    n1->next = NULL;
    printf("%d is inserted\n",e);
    if(is_empty(iback))
    {
        n1->prev = NULL;
        iback->start = n1;
        iback->end = n1;
        return;
    }
    iback->end->next = n1;
    n1->prev = iback->end;
    iback->end = n1;
}

void insert_position(l *ipos)
{
    int e, pos;
    printf("Enter element and position (with space)\n");
    scanf("%d %d", &e, &pos);
    if((is_empty(ipos) && pos != 0) || pos < 0 || pos > (ipos->num) - 1)
    {
        printf("Invalid Input, %d Position does not exist in the List\n",pos);
        ipos->num--;
        return;
    }
    printf("%d is inserted at %d position\n",e,pos);
    n *n1 = (n *)malloc(sizeof(n));
    n1->n = e;
    if(pos == 0)
    {
        n1->prev = NULL;
        ipos->start->prev = n1;
        n1->next = ipos->start;
        ipos->start = n1;
        return;
    }
    if(pos == (ipos->num - 1))
    {
        n1->next = NULL;
        ipos->end->next = n1;
        n1->prev = ipos->end;
        ipos->end = n1;
        return;
    }
    n *travel;
    travel = ipos->start;
    for(int i = 0 ; i < pos - 1 ; i++)
    {
        travel = travel->next;
    }
    n1->next = travel->next;
    travel->next->prev = n1;
    travel->next = n1;
    n1->prev = travel;
}

void delete_front(l *delfront)
{
    if(is_empty(delfront))
    {
        printf("List is empty, no node can be deleted\n");
        delfront->num++;
        return;
    }
    if(only_one(delfront))
    {
        free(delfront->end);
        delfront->start = NULL;
        delfront->end = NULL;
        return;
    }
    n *del;
    del = delfront->start;
    del->next->prev = NULL;
    delfront->start = del->next;
    free(del);
}

void delete_back(l *delback)
{
    if(is_empty(delback))
    {
        printf("List is empty, no node can be deleted\n");
        delback->num++;
        return;
    }
    if(only_one(delback))
    {
        free(delback->end);
        delback->end = NULL;
        delback->start = NULL;
        return;
    }
    n *del;
    del = delback->end;
    del->prev->next = NULL;
    delback->end = del->prev;
    free(del);
}

void delete_position(l *delpos)
{
    int pos;
    printf("Enter position to be deleted\n");
    scanf("%d",&pos);
    if(is_empty(delpos) || (only_one(delpos) && pos != 0) || pos < 0)
    {
        printf("Invalid Input, %d Position does not exist in the List\n",pos);
        delpos->num++;
        return;
    }
    if(pos == 0)
    {
        n *front;
        front = delpos->start;
        delpos->start = front->next;
        front->next->prev = NULL;
        free(front);
        return;
    }
    if(pos == (delpos->num - 1))
    {
        n *back;
        back = delpos->end;
        delpos->end = back->prev;
        back->prev->next = NULL;
        free(back);
        return;
    }
    n *node, *del;
    node = delpos->start;
    for(int i = 0 ; node != NULL ; i++)
    {
        if(i == pos - 1)
        {
            break;
        }
        node = node->next;
    }
    del = node->next;
    node->next = del->next;
    del->next->prev = node;
    free(del);
}

void display_front(l *dfront)
{
    if(is_empty(dfront))
    {
        printf("List is empty\n");
        return;
    }
    n *travel;
    travel = dfront->start;
    printf("Elements in the list from the start are: \n");
    for(;travel != NULL;)
    {
        printf(" %d",travel->n);
        travel = travel->next;
    }    
    printf("\n");
}

void display_back(l *dback)
{
    if(is_empty(dback))
    {
        printf("List is empty\n");
        return;
    }
    n *travel;
    travel = dback->end;
    printf("Elements in the list from the end are: \n");
    for(;travel != NULL;)
    {
        printf(" %d",travel->n);
        travel = travel->prev;
    }    
    printf("\n");
}