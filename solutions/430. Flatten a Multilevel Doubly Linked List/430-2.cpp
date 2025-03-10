class Solution {
 public:
  Node* flatten(Node* head) {
    for (Node* curr = head; curr; curr = curr->next)
      if (curr->child) {
        Node* cachedNext = curr->next;
        curr->next = curr->child;
        curr->child->prev = curr;
        curr->child = nullptr;
        Node* tail = curr->next;
        while (tail->next != nullptr)
          tail = tail->next;
        tail->next = cachedNext;
        if (cachedNext != nullptr)
          cachedNext->prev = tail;
      }

    return head;
  }
};
