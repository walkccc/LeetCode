class Solution {
 public:
  bool isPreorder(vector<vector<int>>& nodes) {
    stack<int> stack;  // Stores `id`s.

    for (const vector<int>& node : nodes) {
      const int id = node[0];
      const int parentId = node[1];
      if (parentId == -1) {
        stack.push(id);
        continue;
      }
      while (!stack.empty() && stack.top() != parentId)
        stack.pop();
      if (stack.empty())
        return false;
      stack.push(id);
    }

    return true;
  }
};
