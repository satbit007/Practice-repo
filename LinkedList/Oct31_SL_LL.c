#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* newNode(int val)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    return temp;
}
struct Node* selectionsort(struct Node* head)
{
    struct Node *x, *y, *z, *w, *s;
    x = y = head;
    while (y->next) {
        z = w = y->next;
        while (w) {
            if (y->data > w->data) {
                if (y->next == w) {
                    if (y == head) {
                        y->next = w->next;
                        w->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        head = y;
                        w = w->next;
                    }
                    else {
                        y->next = w->next;
                        w->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
                else {
                    if (y == head) {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                        head = y;
                    }
                    else {
                        s = y->next;
                        y->next = w->next;
                        w->next = s;
                        z->next = y;
                        x->next = w;
                        s = y;
                        y = w;
                        w = s;
                        z = w;
                        w = w->next;
                    }
                }
            }
            else {
                z = w;
                w = w->next;
            }
        }
        x = y;
        y = y->next;
    }
    
    return head;
}
void display(struct Node* head)
{
    while (head) {
        printf("%d->",head->data);
        head = head->next;
    }
}
int main()
{
   struct Node* head = newNode(13);
    head->next = newNode(4);
    head->next->next = newNode(3);
    head->next->next->next = newNode(6);
    head->next->next->next->next = newNode(15);
    head = selectionsort(head);
    display(head);
    return 0;
}
