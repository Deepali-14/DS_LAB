#include <stdio.h>
#include <stdlib.h>
struct linked_list {
   int data;
   struct linked_list *next;
};
int stack[30], top = -1;
struct linked_list* head = NULL;
int printfromstack(int stack[]) {
   printf("\nStack:\n");
   while(top>=0) {
      printf("%d ", stack[top--]);
   }
}
int push(struct linked_list** head, int n) {
   struct linked_list* newnode = (struct linked_list*)malloc(sizeof(struct linked_list));
   newnode->data = n;
   newnode->next = (*head);
   (*head) = newnode;
}
int intostack(struct linked_list* head) {
   printf("Linked list:\n");
   while(head!=NULL) {
      printf("%d ", head->data);
      stack[++top] = head->data;
      head = head->next;
   }
}
int main(int argc, char const *argv[]) {
   push(&head, 10);
   push(&head, 20);
   push(&head, 30);
   push(&head, 40);
   intostack(head);
   printfromstack(stack);
   return 0;
}
