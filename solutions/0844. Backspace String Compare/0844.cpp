class Solution {
 public:
  bool backspaceCompare(string S, string T) {
    return backspace(S) == backspace(T);
  }

 private:
  string backspace(const string& s) {
    string stack;

    for (const char c : s)
      if (c != '#')
        stack.push_back(c);
      else if (!stack.empty())
        stack.pop_back();

    return stack;
  }
};
