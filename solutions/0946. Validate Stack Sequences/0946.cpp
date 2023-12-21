class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stack;
    int i = 0;  // popped's index

    for (const int x : pushed) {
      stack.push(x);
      while (!stack.empty() && stack.top() == popped[i]) {
        stack.pop();
        ++i;
      }
    }

    return stack.empty();
  }
};
