class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (!node)
      return nullptr;

    queue<Node*> q{{node}};
    unordered_map<Node*, Node*> map;
    map[node] = new Node(node->val);

    while (!q.empty()) {
      Node* n = q.front();
      q.pop();
      for (Node* neighbor : n->neighbors) {
        if (!map.count(neighbor)) {
          map[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }
        map[n]->neighbors.push_back(map[neighbor]);
      }
    }

    return map[node];
  }
};
