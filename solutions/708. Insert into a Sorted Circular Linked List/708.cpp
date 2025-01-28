class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    if (head == nullptr) {
      Node* newNode = new Node(insertVal);
      newNode->next = newNode;
      return newNode;
    }

    Node* prev = head;
    Node* curr = head->next;

    while (curr != head) {
      // 1. the minimum <= insertVal <= the maximum
      // 2. insertVal >= the maximum or insertVal <= the minimum
      if ((prev->val <= insertVal && insertVal <= curr->val) ||
          // `prev` is the maximum and `curr` is the minimum
          (prev->val > curr->val &&
           (insertVal >= prev->val || insertVal <= curr->val))) {
        // Insert the node between `prev` and `curr`.
        prev->next = new Node(insertVal, curr);
        return head;
      }
      prev = prev->next;
      curr = curr->next;
    }

    // All the values in the list are identical.
    prev->next = new Node(insertVal, curr);
    return head;
  }
};
