class Solution {
 public:
  Node* cloneTree(Node* root) {
    if (root == nullptr)
      return nullptr;
    if (const auto it = map.find(root); it != map.cend())
      return it->second;

    Node* newNode = new Node(root->val);
    map[root] = newNode;

    for (Node* child : root->children)
      newNode->children.push_back(cloneTree(child));

    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
