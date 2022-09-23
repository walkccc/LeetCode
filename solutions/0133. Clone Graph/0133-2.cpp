class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node)
      return nullptr;
    if (map.count(node))
      return map[node];

    Node* newNode = new Node(node->val);
    map[node] = newNode;

    for (Node* neighbor : node->neighbors)
      newNode->neighbors.push_back(cloneGraph(neighbor));

    return newNode;
  }

 private:
  unordered_map<Node*, Node*> map;
};
