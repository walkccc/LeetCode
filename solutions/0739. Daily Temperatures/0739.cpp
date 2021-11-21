class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> stack;  // decreasing stack

    for (int i = 0; i < T.size(); ++i) {
      while (!stack.empty() && T[stack.top()] < T[i]) {
        const int index = stack.top();
        stack.pop();
        ans[index] = i - index;
      }
      stack.push(i);
    }

    return ans;
  }
};
