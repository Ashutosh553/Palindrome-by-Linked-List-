#include <stdbool.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
 
struct node { 
    char text; 
    struct node* next; 
}; 
  
void overturnlist(struct node**); 
bool comparelist(struct node*, struct node*); 
  

bool checkpalindrome(struct node* head) 
{ 
    struct node *slow_pointer = head, *fast_pointer = head; 
    struct node *second_half, *prev_of_slow_pointer = head; 
    struct node* midnode = NULL;  
    bool result = true; 
  
    if (head != NULL && head->next != NULL) { 
         
        while (fast_pointer != NULL && fast_pointer->next != NULL) { 
            fast_pointer = fast_pointer->next->next; 
  
            
            prev_of_slow_pointer = slow_pointer; 
            slow_pointer = slow_pointer->next; 
        } 
  
        
        if (fast_pointer != NULL) { 
            midnode = slow_pointer; 
            slow_pointer = slow_pointer->next; 
        } 
  
         
        second_half = slow_pointer; 
        prev_of_slow_pointer->next = NULL;  
        overturnlist(&second_half);  
        result = comparelist(head, second_half); 
  
         
        overturnlist(&second_half); 
  
         
        
        if (midnode != NULL) { 
            prev_of_slow_pointer->next = midnode; 
            midnode->next = second_half; 
        } 
        else
            prev_of_slow_pointer->next = second_half; 
    } 
    return result; 
} 
  

void overturnlist(struct node** head_ref) 
{ 
    struct node* prev = NULL; 
    struct node* current = *head_ref; 
    struct node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  

bool comparelist(struct node* head1, struct node* head2) 
{ 
    struct node* temp1 = head1; 
    struct node* temp2 = head2; 
  
    while (temp1 && temp2) { 
        if (temp1->text == temp2->text) { 
            temp1 = temp1->next; 
            temp2 = temp2->next; 
        } 
        else
            return 0; 
    } 
  
     
    if (temp1 == NULL && temp2 == NULL) 
        return 1; 
  
    
    return 0; 
} 
  

void push(struct Node** head_ref, char new_data) 
{ 
    
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
  
     new_node->text = new_data; 
  
    
    new_node->next = (*head_ref); 
  
    
    (*head_ref) = new_node; 
} 
  

void printList(struct node* ptr) 
{ 
    while (ptr != NULL) { 
        printf("%c->", ptr->text); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
  

int main() 
{ 
    
    struct node* head = NULL; 
    char str[] = "level"; 
    int i; 
  
    for (i = 0; str[i] != '\0'; i++) { 
        push(&head, str[i]); 
        printList(head); 
        checkpalindrome(head) ? printf("your given text is Palindrome\n\n") : printf("Your given text is not Palindrome\n\n"); 
    } 
  
    return 0; 
} 

