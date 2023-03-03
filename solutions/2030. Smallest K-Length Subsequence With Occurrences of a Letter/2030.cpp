class Solution {
 public:
  string smallestSubsequence(string s, int k, char letter, int repetition) {
    string ans;
    vector<char> stack;
    int required = repetition;
    int nLetters = count(begin(s), end(s), letter);

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      while (!stack.empty() && stack.back() > c &&
             stack.size() + s.length() - i - 1 >= k &&
             (stack.back() != letter || nLetters > required)) {
        const char popped = stack.back();
        stack.pop_back();
        if (popped == letter)
          ++required;
      }
      if (stack.size() < k)
        if (c == letter) {
          stack.push_back(c);
          --required;
        } else if (k > stack.size() + required) {
          stack.push_back(c);
        }
      if (c == letter)
        --nLetters;
    }

    for (const char c : stack)
      ans += c;

    return ans;
  }
};
