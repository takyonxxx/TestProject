#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "libraries.h"

/*Singly linked list is a type of data structure that is made up of nodes that are created using self referential structures.
Each of these nodes contain two parts, namely the data and the reference to the next list node.
Only the reference to the first list node is required to access the whole linked list.
This is known as the head. The last node in the list points to nothing so it stores NULL in that part.*/

struct Node {
   int data;
   struct Node *next;
};
struct Node* head = nullptr;

void insert(int new_data)
{
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = head;
   head = new_node;
}

void display()
{
   struct Node* ptr;
   ptr = head;
   while (ptr != nullptr)
   {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void testLinkList() {
   insert(3);
   insert(1);
   insert(7);
   insert(2);
   insert(9);
   cout<<"The linked list is: ";
   display();
}

#endif // LINKEDLIST_H
