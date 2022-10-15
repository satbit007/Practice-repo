// Source Code: https://www.codezclub.com/c-split-single-linked-list-two-halves/
// Spliting a single linked list into two halves

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int info;
        struct node *link;
};

struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start,int data);
int Split(struct node *start, struct node **start1);


int Split(struct node *start, struct node **start1)
{
        struct node *s, *f;
        if(start->link==NULL) /*only one element*/
                return 0;

        s=f=start;

        while(f->link!=NULL && f->link->link!=NULL)
        {
                s = s->link;
                f = f->link->link;
        }
        *start1 = s->link;
        s->link = NULL;
}

struct node *create_list(struct node *start)
{
        int i,n,data;
        printf("Enter the number of nodes : ");
        scanf("%d",&n);
        start=NULL;
        if(n==0)
                return start;

        printf("\nEnter the element to be inserted : ");
        scanf("%d",&data);
        start=addatbeg(start,data);

        for(i=2;i<=n;i++)
        {
                printf("\nEnter the element to be inserted : ");
                scanf("%d",&data);
                start=addatend(start,data);
        }
        return start;
}

void display(struct node *start)
{
        struct node *p;
        if(start==NULL)
        {
                printf("\nList is empty\n");
                return;
        }
        p=start;
        printf("\nList is :\n");
        while(p!=NULL)
        {
                printf("%d ",p->info);
                p=p->link;
        }
        printf("\n\n");
}

struct node *addatbeg(struct node *start,int data)
{
        struct node *tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        tmp->link=start;
        start=tmp;
        return start;
}

struct node *addatend(struct node *start,int data)
{
        struct node *p,*tmp;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->info=data;
        p=start;
        while(p->link!=NULL)
                p=p->link;
        p->link=tmp;
        tmp->link=NULL;
        return start;
}

int main()
{
        struct node *start=NULL,*start1=NULL;
        int value;

        start=create_list(start);
        display(start);

        if(start!=NULL)
    Split(start, &start1);
        display(start);

        return 0;

}