class Solution {
 public:
  int scoreOfParentheses(string S) {
    int ans = 0;
    int layer = 0;

    for (int i = 0; i < S.length(); ++i) {
      layer += S[i] == '(' ? 1 : -1;
      if (S[i] == ')' && S[i - 1] == '(') ans += 1 << layer;
    }

    return ans;
  }
};