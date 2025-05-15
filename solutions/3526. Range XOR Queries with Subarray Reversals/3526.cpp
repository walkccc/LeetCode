struct Node {
  Node(int v) : val(v), subXor(v) {}
  int val;
  int subXor;
  int sz = 1;
  int rev = false;
  int prior = rand();
  Node* l = nullptr;
  Node* r = nullptr;
};

class AVLTree {
 public:
  AVLTree(const vector<int>& nums) : root(nullptr) {
    build(nums);
  }

  void updateValue(int index, int val) {
    Node* l = nullptr;
    Node* r = nullptr;
    Node* m = nullptr;
    split(root, index, l, r);
    split(r, 1, m, r);
    if (m != nullptr)
      m->val = val;
    update(m);
    root = merge(merge(l, m), r);
  }

  int rangeXor(int left, int right) {
    Node* l = nullptr;
    Node* m = nullptr;
    Node* r = nullptr;
    split(root, left, l, r);
    split(r, right - left + 1, m, r);
    const int res = getXor(m);
    root = merge(merge(l, m), r);
    return res;
  }

  void reverseRange(int left, int right) {
    Node* l = nullptr;
    Node* m = nullptr;
    Node* r = nullptr;
    split(root, left, l, r);
    split(r, right - left + 1, m, r);
    if (m != nullptr)
      m->rev = !m->rev;
    root = merge(merge(l, m), r);
  }

 private:
  Node* root;

  void build(const vector<int>& nums) {
    for (const int num : nums)
      root = merge(root, new Node(num));
  }

  int getSize(Node* t) {
    return t ? t->sz : 0;
  }

  int getXor(Node* t) {
    return t ? t->subXor : 0;
  }

  void push(Node* t) {
    if (t == nullptr || !t->rev)
      return;
    swap(t->l, t->r);
    if (t->l != nullptr)
      t->l->rev ^= 1;
    if (t->r != nullptr)
      t->r->rev ^= 1;
    t->rev = false;
  }

  void update(Node* t) {
    if (t == nullptr)
      return;
    t->sz = 1 + getSize(t->l) + getSize(t->r);
    t->subXor = t->val ^ getXor(t->l) ^ getXor(t->r);
  }

  void split(Node* t, int k, Node*& l, Node*& r) {
    if (t == nullptr)
      return void(l = r = nullptr);
    push(t);
    if (getSize(t->l) >= k) {
      split(t->l, k, l, t->l);
      r = t;
    } else {
      split(t->r, k - getSize(t->l) - 1, t->r, r);
      l = t;
    }
    update(t);
  }

  Node* merge(Node* l, Node* r) {
    push(l);
    push(r);
    if (l == nullptr || r == nullptr)
      return l == nullptr ? r : l;
    if (l->prior > r->prior) {
      l->r = merge(l->r, r);
      update(l);
      return l;
    } else {
      r->l = merge(l, r->l);
      update(r);
      return r;
    }
  }
};

class Solution {
 public:
  vector<int> getResults(vector<int>& nums, vector<vector<int>>& queries) {
    AVLTree tree(nums);
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int type = query[0];
      if (type == 1)
        tree.updateValue(/*index=*/query[1], /*val=*/query[2]);
      else if (type == 2)
        ans.push_back(tree.rangeXor(/*left=*/query[1], /*right=*/query[2]));
      else if (type == 3)
        tree.reverseRange(/*left=*/query[1], /*right=*/query[2]);
    }

    return ans;
  }
};
