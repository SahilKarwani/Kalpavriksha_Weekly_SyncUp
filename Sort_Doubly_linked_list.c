// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

struct node  
{  
    struct node *prev;
    struct node *next; 
    int val;  
};

void assign(struct node *head){
     struct node * temp = head;
     
     while(temp)
     {
         printf("%d ",temp->val);
         temp = temp->next;
     }
     printf("\n");
     
}

struct node * sorting(struct node *head1, struct node *head2){
struct node * temp = malloc(sizeof (struct node));
    // struct node * diff = malloc(sizeof (struct node));
    if(head1->val > head2->val){
        temp->val = head2->val;
        // diff = head1->val;
        // diff->prev = temp;
        // temp->next = diff;
        temp->next = NULL;
        temp->prev = NULL;
        head2 = head2->next;
       
    }
    else{
        temp->val = head1->val;
        // diff = headd2->val
        // diff->prev = temp;
        // temp->next = diff;
        temp->next = NULL;
        temp->prev = NULL;
        head1 = head1->next;
    }
    struct node * temp1 = temp;
    // head1 = head1->next;
    // head2 = head2->next;
    
    while(head1 && head2)
    {
        struct node * nn = malloc(sizeof (struct node));
        
        
        if(head1->val > head2->val){
        nn->val = head2->val;
        temp1->next = nn;
        // nn->prev = temp1;
        temp1 = temp1->next;
        head2 = head2->next;
        
    }
    else
    {
        nn->val = head1->val;
        temp1->next = nn;
        // nn->prev = temp1;
        temp1 = temp1->next;
        head1 = head1->next;
    }
    
    }
    
    // temp1->next = nn;
    // nn->prev = temp1;
    while(head1){
        struct node * nn = malloc(sizeof (struct node));
        nn->val = head1->val;
        // nn->prev = temp1;
        temp1->next = nn;
        temp1 = temp1->next;
        head1 = head1->next;
        
    }
    while(head2){
        struct node * nn = malloc(sizeof (struct node));
        nn->val = head2->val;
        // nn->prev = temp1;
        temp1->next = nn;
        temp1 = temp1->next;
        head2 = head2->next;
        
    }
    
   return temp;
}



int main() {
    // Write C code here
    struct node * head1 = malloc(sizeof(struct node));
    int data;
    scanf("%d",&data);
    head1->val = data;
    head1->next = NULL;
    head1->prev = NULL;
    struct node * temp = head1;
    while(1){
        
        struct node * temp1 = malloc(sizeof(struct node));
        
        scanf("%d",&data);
        if(data == -1) break;
        temp1->val = data;
        temp1->prev = temp;
        temp1->next = NULL;
        temp->next = temp1;
        temp = temp->next;
        
        
    }
    struct node * head2 = malloc(sizeof(struct node));
    scanf("%d",&data);
    head2->val = data;
    head2->next = NULL;
    head2->prev = NULL;
    struct node * temp2 = head2;
    while(1){
        
        struct node * temp1 = malloc(sizeof(struct node));
       
        scanf("%d",&data);
        if(data == -1) break;
        temp1->val = data;
        temp1->prev = temp;
        temp1->next = NULL;
        temp2->next = temp1;
        temp2 = temp2->next;
        
        
    }
    // struct node * temp1 = head1
    struct node * t = sorting(head1, head2);
    assign(t);
    
    

    return 0;
}
