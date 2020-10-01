class Solution {
 public:
  Node* connect(Node* root) {
    Node* node = root;
    Node* cache = new Node;

    while (node) {
      Node* curr = cache;
      while (node) {
        if (node->left) {
          curr->next = node->left;
          curr = curr->next;
        }
        if (node->right) {
          curr->next = node->right;
          curr = curr->next;
        }
        node = node->next;
      }
      node = cache->next;
      cache->next = nullptr;
    }

    return root;
  }
};