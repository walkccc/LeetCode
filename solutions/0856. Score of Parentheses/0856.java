class Solution {
  public int scoreOfParentheses(String S) {
    int ans = 0;
    int layer = 0;

    for (int i = 0; i + 1 < S.length(); ++i) {
      final char a = S.charAt(i);
      final char b = S.charAt(i + 1);
      if (a == '(' && b == ')')
        ans += 1 << layer;
      layer += a == '(' ? 1 : -1;
    }

    return ans;
  }
}
