 #include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp->next)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> NULL\n", temp->data);
}

struct Node *createLinkedList(struct Node *head)
{
    printf("Enter element: ");
    int data;
    scanf("%d", &data);
    struct Node *nwnode = malloc(sizeof(struct Node)), *temp;
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

struct Node *findMid(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node *merge(struct Node *left, struct Node *right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    struct Node *mergedHead = NULL;
    if (left->data < right->data) {
        mergedHead = left;
        left = left->next;
    } else {
        mergedHead = right;
        right = right->next;
    }

    struct Node *current = mergedHead;
    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            current->next = left;
            left = left->next;
        } else {
            current->next = right;
            right = right->next;
        }
        current = current->next;
    }

    while (left != NULL) {
        current->next = left;
        left = left->next;
        current = current->next;
    }
    while (right != NULL) {
        current->next = right;
        right = right->next;
        current = current->next;
    }
    return mergedHead;
}

struct Node *MergeSort(struct Node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node *mid = findMid(head);
    struct Node *left = head;
    struct Node *right = mid->next;
    mid->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);
    struct Node *result = merge(left, right);
    return result;
}

int main()
{

    struct Node *head = NULL;
    int num;
    printf("Enter number of elements:\n");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        head = createLinkedList(head);
    }

    printf("Before sorting linked list:\n");
    print(head);

    head = MergeSort(head);

    printf("After sorting linked list:\n");
    print(head);

    return 0;

}

