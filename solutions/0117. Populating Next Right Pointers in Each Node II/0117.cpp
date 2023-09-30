class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;  // The node just above current needling

    while (node) {
      Node dummy(0);  // Dummy node before needling
      // Needle children of node
      for (Node* needle = &dummy; node; node = node->next) {
        if (node->left) {  // Needle left child
          needle->next = node->left;
          needle = needle->next;
        }
        if (node->right) {  // Needle right child
          needle->next = node->right;
          needle = needle->next;
        }
      }
      node = dummy.next;  // Move node to the next level
    }

    return root;
  }
};
