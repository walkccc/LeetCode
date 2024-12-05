class Solution {
 public:
  string removeDuplicates(const string& s, int k) {
    string ans;
    vector<pair<char, int>> stack;

    for (const char c : s)
      if (stack.empty() || stack.back().first != c)
        stack.emplace_back(c, 1);
      else if (++stack.back().second == k)  // stack[-1] == c
        stack.pop_back();

    for (const auto& [c, count] : stack)
      ans.append(count, c);

    return ans;
  }
};
