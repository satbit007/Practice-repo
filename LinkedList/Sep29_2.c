//Source: https://www.geeksforgeeks.org/reverse-a-linked-list/
#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data; //Data part
    struct node *next; //Address part
}*head;


/* Functions used in the program */
void createList(int n);
void reverseList();
void displayList();


int main()
{
    int n, choice;

    /*
     * Create a singly linked list of n nodes
     */
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);

    printf("\nData in the list \n");
    displayList();

    /*
     * Reverse the list
     */
    printf("\nPress 1 to reverse the order of singly linked list\n");
    scanf("%d", &choice);
    if(choice == 1)
    {
        reverseList();
    }

    printf("\nData in the list\n");
    displayList();

    return 0;
}


/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; 
        head->next = NULL; 

        temp = head;

        
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; 
                newNode->next = NULL; 

                temp->next = newNode; 
                temp = temp->next;
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL; // Make first node as last node

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode; // Make last node as head

        printf("Reversing list successfull\n");
    }
}
void displayList()
{
    struct node *temp;


    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); 
            temp = temp->next;                
        }
    }
}