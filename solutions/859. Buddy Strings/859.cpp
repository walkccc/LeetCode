class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    if (s.length() != goal.length())
      return false;
    if (s == goal && hasDuplicateLetters(s))
      return true;

    vector<int> diffIndices;

    for (int i = 0; i < s.length(); ++i)
      if (s[i] != goal[i])
        diffIndices.push_back(i);

    return diffIndices.size() == 2 &&
           s[diffIndices[0]] == goal[diffIndices[1]] &&
           s[diffIndices[1]] == goal[diffIndices[0]];
  }

 private:
  bool hasDuplicateLetters(const string& s) {
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    return ranges::any_of(count, [](int freq) { return freq > 1; });
  }
};
