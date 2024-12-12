class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr)
      return nullptr;
    connectTwoNodes(root->left, root->right);
    return root;
  }

 private:
  void connectTwoNodes(Node* p, Node* q) {
    if (p == nullptr)
      return;
    p->next = q;
    connectTwoNodes(p->left, p->right);
    connectTwoNodes(q->left, q->right);
    connectTwoNodes(p->right, q->left);
  }
};
