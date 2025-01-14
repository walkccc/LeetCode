class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;  // the node that is above the current needling

    while (node != nullptr) {
      Node dummy(0);  // the dummy node before needling
      // Needle the children of the node.
      for (Node* needle = &dummy; node; node = node->next) {
        if (node->left != nullptr) {  // Needle the left child.
          needle->next = node->left;
          needle = needle->next;
        }
        if (node->right != nullptr) {  // Needle the right child.
          needle->next = node->right;
          needle = needle->next;
        }
      }
      node = dummy.next;  // Move the node to the next level.
    }

    return root;
  }
};
