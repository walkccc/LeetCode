struct Node {
  int val;
  shared_ptr<Node> next;
  shared_ptr<Node> down;
  Node(int val = -1, shared_ptr<Node> next = nullptr,
       shared_ptr<Node> down = nullptr)
      : val(val), next(next), down(down) {}
};

class Skiplist {
 public:
  bool search(int target) {
    for (shared_ptr<Node> node = dummy; node; node = node->down) {
      advance(node, target);
      if (node->next && node->next->val == target)
        return true;
    }
    return false;
  }

  void add(int num) {
    // Collect nodes that are before the insertion point.
    stack<shared_ptr<Node>> nodes;
    for (shared_ptr<Node> node = dummy; node; node = node->down) {
      advance(node, num);
      nodes.push(node);
    }

    shared_ptr<Node> down;
    bool shouldInsert = true;
    while (shouldInsert && !nodes.empty()) {
      shared_ptr<Node> prev = nodes.top();
      nodes.pop();
      prev->next = make_shared<Node>(num, prev->next, down);
      down = prev->next;
      shouldInsert = rand() & 1;
    }

    // Create a topmost new level dummy that points to the existing dummy.
    if (shouldInsert)
      dummy = make_shared<Node>(-1, nullptr, dummy);
  }

  bool erase(int num) {
    bool found = false;
    for (shared_ptr<Node> node = dummy; node; node = node->down) {
      advance(node, num);
      if (node->next && node->next->val == num) {
        node->next = node->next->next;
        found = true;
      }
    }
    return found;
  }

 private:
  shared_ptr<Node> dummy = make_shared<Node>(-1);

  void advance(shared_ptr<Node>& node, int target) {
    while (node->next && node->next->val < target)
      node = node->next;
  }
};
