class Solution {
 public:
  int maximumNumberOfStringPairs(vector<string>& words) {
    int ans = 0;
    vector<bool> seen(26 * 26);

    for (const string& word : words) {
      if (seen[val(word[1]) * 26 + val(word[0])])
        ++ans;
      seen[val(word[0]) * 26 + val(word[1])] = true;
    }

    return ans;
  }

 private:
  constexpr int val(char c) {
    return c - 'a';
  }
};
