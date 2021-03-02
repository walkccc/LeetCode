class Solution {
 public:
  Node* cloneTree(Node* root) {
    if (!root)
      return nullptr;
    if (map.count(root))
      return map[root];

    Node* newNode = new Node(root->val);
    map[root] = newNode;

    for (Node* child : root->children)
      newNode->children.push_back(cloneTree(child));

    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
