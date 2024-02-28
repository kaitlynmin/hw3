#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head == NULL) {
    smaller = NULL;
    larger = NULL;
    return;
  } else {
    if (head->val <= pivot) {
      Node* temp = head;
      head = head->next;
      temp->next = smaller;
      smaller = temp;
      llpivot (head, smaller->next, larger, pivot);
    }
    else {
      Node* temp = head;
      head = head->next;
      temp->next = larger;
      larger = temp;
      llpivot(head, smaller, larger->next, pivot);
    }
  }
}

