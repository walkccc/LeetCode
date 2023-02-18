class Solution {
 public:
  int scoreOfParentheses(string S) {
    int ans = 0;
    int layer = 0;

    for (int i = 0; i + 1 < S.length(); ++i) {
      const char a = S[i];
      const char b = S[i + 1];
      if (a == '(' && b == ')')
        ans += 1 << layer;
      layer += a == '(' ? 1 : -1;
    }

    return ans;
  }
};
