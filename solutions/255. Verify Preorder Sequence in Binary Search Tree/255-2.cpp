class Solution {
 public:
  bool verifyPreorder(vector<int>& preorder) {
    int low = INT_MIN;
    stack<int> stack;

    for (const int p : preorder) {
      if (p < low)
        return false;
      while (!stack.empty() && stack.top() < p)
        low = stack.top(), stack.pop();
      stack.push(p);
    }

    return true;
  }
};
