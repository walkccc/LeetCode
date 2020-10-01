class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> stack;  // decreasing stack

    for (int i = 0; i < T.size(); ++i) {
      while (!stack.empty() && T[stack.top()] < T[i]) {
        const int index = stack.top();
        ans[index] = i - index;
        stack.pop();
      }
      stack.push(i);
    }

    return ans;
  }
};