class Solution {
 public:
  Node* moveSubTree(Node* root, Node* p, Node* q) {
    if (find(q->children.begin(), q->children.end(), p) != q->children.end())
      return root;

    // Create a dummy node for the case when root == p.
    Node* dummy = new Node(0, {root});

    // Get each parent of p and q.
    Node* pParent = getParent(dummy, p);
    Node* qParent = getParent(p, q);

    // Get p's original index in p's parent.
    vector<Node*>& pSiblings = pParent->children;
    const int pIndex =
        find(pSiblings.begin(), pSiblings.end(), p) - pSiblings.begin();
    pSiblings.erase(pSiblings.begin() + pIndex);

    q->children.push_back(p);

    // If q is in p's subtree, qParent != nullptr.
    if (qParent != nullptr) {
      vector<Node*>& qSiblings = qParent->children;
      std::erase(qSiblings, q);
      pSiblings.insert(pSiblings.begin() + pIndex, q);
    }

    return dummy->children[0];
  }

 private:
  Node* getParent(Node* root, Node* target) {
    for (Node* child : root->children) {
      if (child == target)
        return root;
      Node* res = getParent(child, target);
      if (res != nullptr)
        return res;
    }
    return nullptr;
  }
};
