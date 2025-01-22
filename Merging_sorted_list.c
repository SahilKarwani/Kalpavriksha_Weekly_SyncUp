#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int val;
};

void print(struct node *head)
{

    struct node *temp = head;

    while (temp)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

struct node *merge(struct node *head1, struct node *head2)
{

    struct node *temp = malloc(sizeof(struct node));
    struct node *diff = malloc(sizeof(struct node));

    if (head1->val > head2->val)
    {
        temp->val = head2->val;
        diff->prev = temp;
        temp->next = diff;
        temp->next = NULL;
        temp->prev = NULL;
        head2 = head2->next;
    }
    else
    {
        temp->val = head1->val;
        diff->prev = temp;
        temp->next = diff;
        temp->next = NULL;
        temp->prev = NULL;
        head1 = head1->next;
    }

    struct node *temp1 = temp;

    while (head1 && head2)
    {
        struct node *nn = malloc(sizeof(struct node));

        if (head1->val > head2->val)
        {
            nn->val = head2->val;
            temp1->next = nn;
            nn->prev = temp1;
            temp1 = temp1->next;
            head2 = head2->next;
        }
        else
        {
            nn->val = head1->val;
            temp1->next = nn;
            nn->prev = temp1;
            temp1 = temp1->next;
            head1 = head1->next;
        }
    }

    while (head1)
    {
        struct node *nn = malloc(sizeof(struct node));
        nn->val = head1->val;
        nn->prev = temp1;
        temp1->next = nn;
        temp1 = temp1->next;
        head1 = head1->next;
    }
    while (head2)
    {
        struct node *nn = malloc(sizeof(struct node));
        nn->val = head2->val;
        nn->prev = temp1;
        temp1->next = nn;
        temp1 = temp1->next;
        head2 = head2->next;
    }

    return temp;
}

int main()
{
    // Write C code here
    int l1 = 0, num1;
    printf("Enter the number of elements in the first list: ");
    scanf("%d", &num1);
    l1 = num1;
    struct node *head1 = malloc(sizeof(struct node));
    if (l1 > 0)
    {
        printf("Enter %d sorted elements:", l1);
        int data;
        scanf("%d", &data);
        l1--;
        head1->val = data;
        head1->next = NULL;
        head1->prev = NULL;
        struct node *temp = head1;
        while (l1--)
        {

            struct node *temp1 = malloc(sizeof(struct node));

            scanf("%d", &data);
            if (data == -1)
                break;
            temp1->val = data;
            temp1->prev = temp;
            temp1->next = NULL;
            temp->next = temp1;
            temp = temp->next;
        }
    }
    printf("\n");
    int l2 = 0, num2;
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &num2);
    l2 = num2;
    struct node *head2 = malloc(sizeof(struct node));
    if (l2 > 0)
    {
        printf("Enter %d sorted elements: ", l2);
        int data;
        scanf("%d", &data);
        head2->val = data;
        head2->next = NULL;
        head2->prev = NULL;
        struct node *temp2 = head2;
        l2--;
        while (l2--)
        {

            struct node *temp1 = malloc(sizeof(struct node));

            scanf("%d", &data);

            temp1->val = data;
            temp1->next = NULL;
            temp2->next = temp1;
            temp2 = temp2->next;
        }
    }
    printf("\n");

    printf("First Sorted List:");
    if (num1)
        print(head1);
    printf("\n");
    printf("Second Sorted List:");
    if (num2)
        print(head2);
    printf("\n");
    printf("Merged Sorted List:");
    if (num1 && num2)
    {
        struct node *t = merge(head1, head2);
        print(t);
    }
    else if (num1)
        print(head1);
    else if (num2)
        print(head2);

    return 0;
    
}
