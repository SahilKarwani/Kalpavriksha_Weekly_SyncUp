// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node* removemiddle(struct node *head,int len)
{
    
    if(!head || !head->next ) return NULL ;
    if(!head->next->next) return head->next;
    struct node* slow = head,*fast = head,*prev = NULL,
    *prev1 = NULL;
    
    while(fast && fast->next){
        prev1 = prev;
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast){
        prev->next = slow->next;
    }
    else{
         
        prev1->next = slow;
    }
    
    return head;
}

void print(struct node* head){
    if(!head) return ;
    struct node* temp = head;
    while(temp){
        printf("%c ",temp->data);
        temp = temp->next;
    }
}

int main() {
    
     printf("enter number of elements\n");
    int num;
    int len = num;
    scanf("%d",&num);
    getchar();
    if(num == 0) return 0;
    
    struct node* head = (struct node*)malloc(sizeof(struct node));
    char data;
    scanf("%c",&data);
    getchar();
    head->data = data;
    head->next = NULL;
    num--;
    
    struct node* temp = head;
    while(num--)
    {
        char data;
        struct node* newnode = malloc(sizeof(struct node));
        scanf("%c",&data);
        getchar();
        newnode->data = data;
        newnode->next = NULL;
        temp->next  = newnode;
        temp = temp->next;
        
    }
    head = removemiddle(head,len);
    printf("\nAfter removing middle\n");
    print(head);
    return 0;
}
