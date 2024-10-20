struct Node {
  vector<int> children;
  int lockedBy = -1;
};

class LockingTree {
 public:
  LockingTree(vector<int>& parent) : parent(parent) {
    nodes.resize(parent.size());
    for (int i = 1; i < parent.size(); ++i)
      nodes[parent[i]].children.push_back(i);
  }

  bool lock(int num, int user) {
    if (nodes[num].lockedBy != -1)
      return false;
    return nodes[num].lockedBy = user;
  }

  bool unlock(int num, int user) {
    if (nodes[num].lockedBy != user)
      return false;
    return nodes[num].lockedBy = -1;
  }

  bool upgrade(int num, int user) {
    if (nodes[num].lockedBy != -1)
      return false;
    if (!anyLockedDescendant(num))
      return false;

    // Walk up the hierarchy to ensure that there are no locked ancestors.
    for (int i = num; i != -1; i = parent[i])
      if (nodes[i].lockedBy != -1)
        return false;

    unlockDescendants(num);
    return nodes[num].lockedBy = user;
  }

 private:
  const vector<int> parent;
  vector<Node> nodes;

  bool anyLockedDescendant(int i) {
    return nodes[i].lockedBy != -1 ||
           ranges::any_of(nodes[i].children, [this](const int child) {
      return anyLockedDescendant(child);
    });
  }

  void unlockDescendants(int i) {
    nodes[i].lockedBy = -1;
    for (const int child : nodes[i].children)
      unlockDescendants(child);
  }
};
