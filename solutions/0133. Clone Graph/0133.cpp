class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr)
      return nullptr;

    queue<Node*> q{{node}};
    unordered_map<Node*, Node*> map{{node, new Node(node->val)}};

    while (!q.empty()) {
      Node* u = q.front();
      q.pop();
      for (Node* v : u->neighbors) {
        if (!map.count(v)) {
          map[v] = new Node(v->val);
          q.push(v);
        }
        map[u]->neighbors.push_back(map[v]);
      }
    }

    return map[node];
  }
};
