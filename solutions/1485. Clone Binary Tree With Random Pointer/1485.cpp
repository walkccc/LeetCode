class Solution {
 public:
  NodeCopy* copyRandomBinaryTree(Node* root) {
    if (root == nullptr)
      return nullptr;
    if (const auto it = map.find(root); it != map.cend())
      return it->second;

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
