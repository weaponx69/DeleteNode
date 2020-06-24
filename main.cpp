#include <stdio.h> 
#include <stdlib.h> 
  
typedef struct LinkNode { 
    int data; 
    struct LinkNode* next; 
    struct LinkNode* prev; 
}LinkNode_t;

//global pointer to head of linked list
LinkNode_t *g_pLinkedList;

void KillNode(LinkNode_t** Head_ref, LinkNode_t* del)
{ 
    /* base case */
    if (*Head_ref == NULL || del == NULL)
        return;
  
    /* If node to be deleted is Head node */
    if (*Head_ref == del)
        *Head_ref = del->next;
  
    /* Change next only if node to be deleted is NOT the last node */
    if (del->next != NULL) 
        del->next->prev = del->prev; 
  
    /* Change prev only if node to be deleted is NOT the first node */
    if (del->prev != NULL) 
        del->prev->next = del->next; 
  
    /* Finally, free the memory occupied by del*/
    free(del); 
    return; 
} 
  
void pushFront(LinkNode_t** Head_ref, int new_data)
{ 
    /* allocate node */
    LinkNode_t* new_node = (LinkNode_t*)malloc(sizeof(LinkNode_t)); 
  
    /* put in the data  */
    new_node->data = new_data; 
  
    /* since we are adding at the beginning, 
    prev is always NULL */
    new_node->prev = NULL; 
  
    /* link the old list off the new node */
    new_node->next = (*Head_ref); 
  
    /* change prev of Head node to new node */
    if ((*Head_ref) != NULL)
        (*Head_ref)->prev = new_node; 
  
    /* move the Head to point to the new node */
    (*Head_ref) = new_node;
} 

void printList(LinkNode_t* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    }
    printf("\n");
} 
  
/* Driver program to test above functions*/
int main() 
{ 
  /* Start with the empty list */
  LinkNode_t* Head = NULL;

  // create list.
  pushFront(&Head, 2);
  pushFront(&Head, 4);
  pushFront(&Head, 8);
  pushFront(&Head, 10);

  printf("Original Linked list \n");
  printList(Head);

  //KillNode(&Head, Head);
  KillNode(&Head, Head->next); 
  //KillNode(&Head, Head->next);

  printf("Modified Linked list\n");
  printList(Head);
} 