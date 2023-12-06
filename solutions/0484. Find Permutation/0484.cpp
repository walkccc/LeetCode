class Solution {
 public:
  vector<int> findPermutation(string s) {
    vector<int> ans;
    stack<int> stack;

    for (int i = 0; i < s.length(); ++i) {
      stack.push(i + 1);
      if (s[i] == 'I')
        while (!stack.empty())
          ans.push_back(stack.top()), stack.pop();
    }
    stack.push(s.length() + 1);

    while (!stack.empty())
      ans.push_back(stack.top()), stack.pop();

    return ans;
  }
};
