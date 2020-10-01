class Solution {
 public:
  vector<vector<int>> levelOrder(Node* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    queue<Node*> q{{root}};

    while (!q.empty()) {
      vector<int> currLevel;
      for (int i = q.size(); i > 0; --i) {
        root = q.front(), q.pop();
        currLevel.push_back(root->val);
        for (Node* child : root->children)
          q.push(child);
      }
      ans.push_back(currLevel);
    }

    return ans;
  }
};