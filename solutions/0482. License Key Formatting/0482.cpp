class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    string ans;
    int length = 0;

    for (int i = S.length() - 1; i >= 0; --i) {
      if (S[i] == '-')
        continue;
      if (length > 0 && length % K == 0)
        ans += "-";
      ans += toupper(S[i]);
      ++length;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
