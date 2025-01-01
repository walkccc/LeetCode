class Solution {
 public:
  string robotWithString(string s) {
    string ans;
    vector<int> count(26);
    stack<char> stack;

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : s) {
      stack.push(c);
      --count[c - 'a'];
      const char minChar = getMinChar(count);
      while (!stack.empty() && stack.top() <= minChar)
        ans += stack.top(), stack.pop();
    }

    while (!stack.empty())
      ans += stack.top(), stack.pop();

    return ans;
  }

 private:
  char getMinChar(const vector<int>& count) {
    for (int i = 0; i < 26; ++i)
      if (count[i])
        return 'a' + i;
    return 'a';
  }
};
