class Solution {
 public:
  string stringHash(string s, int k) {
    string ans;

    for (int i = 0; i < s.length(); i += k) {
      int sumHash = 0;
      for (int j = i; j < i + k; ++j)
        sumHash += s[j] - 'a';
      ans += 'a' + sumHash % 26;
    }

    return ans;
  }
};
