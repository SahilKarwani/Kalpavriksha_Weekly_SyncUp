#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *head)
{
    struct node *temp = head;
    while (temp->next)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

struct node *createLinkedList(struct node *head)
{
    printf("Enter element: ");
    int data;
    scanf("%d", &data);
    struct node *nwnode = malloc(sizeof(struct node)), *temp;
    nwnode->data = data;
    nwnode->next = NULL;

    if (head == NULL)
    {
        head = temp = nwnode;
    }
    else
    {
        temp->next = nwnode;
        temp = nwnode;
    }
    return head;
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
    ;
}

void bubbleSort(struct node *head)
{

    struct node *temp1 = head;
    int flag = 1, cnt = 0, isSwapped;
    while (temp1->next)
    {

        struct node *temp2 = head, *temp = head;
        isSwapped = 0;
        while (flag && temp->next)
        {
            if (temp->data > temp->next->data)
            {
                swap(&temp->data, &temp->next->data);
                isSwapped = 1;
            }
            temp = temp->next;
            cnt++;
        }
        flag = 0;

        for (int i = 0; i < cnt - 1; i++)
        {
            if (temp2->data > temp2->next->data)
            {
                swap(&temp2->data, &temp2->next->data);
                isSwapped = 1;
            }
            temp2 = temp2->next;
        }

        if (!isSwapped)
            break;
        cnt--;
        temp1 = temp1->next;
    }
}

int main()
{

    struct node *head = NULL;
    int num;
    printf("Enter number of elements:\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        head = createLinkedList(head);
    }

    printf("Before sorting linked list:\n");
    print(head);

    bubbleSort(head);

    printf("After sorting linked list:\n");
    print(head);

    return 0;

}
