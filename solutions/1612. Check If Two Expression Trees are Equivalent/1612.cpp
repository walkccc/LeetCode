class Solution {
 public:
  bool checkEquivalence(Node* root1, Node* root2) {
    vector<int> count(26);
    dfs(root1, count, 1);
    dfs(root2, count, -1);
    return ranges::count_if(count, [](int c) { return c != 0; }) == 0;
  }

 private:
  void dfs(Node* root, vector<int>& count, int add) {
    if (root == nullptr)
      return;
    if ('a' <= root->val && root->val <= 'z')
      count[root->val - 'a'] += add;
    dfs(root->left, count, add);
    dfs(root->right, count, add);
  }
};
