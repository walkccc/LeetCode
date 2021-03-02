class Solution {
 public:
  NodeCopy* copyRandomBinaryTree(Node* root) {
    if (!root)
      return nullptr;
    if (map.count(root))
      return map[root];

    NodeCopy* newNode = new NodeCopy(root->val);
    map[root] = newNode;

    newNode->left = copyRandomBinaryTree(root->left);
    newNode->right = copyRandomBinaryTree(root->right);
    newNode->random = copyRandomBinaryTree(root->random);

    return newNode;
  }

 private:
  unordered_map<Node*, NodeCopy*> map;
};
