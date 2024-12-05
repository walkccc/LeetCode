class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;  // the node that is above the current needling

    while (node && node->left) {
      Node dummy(0);  // the dummy node before needling
      // Needle the children of the node.
      for (Node* needle = &dummy; node; node = node->next) {
        needle->next = node->left;
        needle = needle->next;
        needle->next = node->right;
        needle = needle->next;
      }
      node = dummy.next;  // Move the node to the next level.
    }

    return root;
  }
};
