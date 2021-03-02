class Solution {
  public String orderlyQueue(String S, int K) {
    if (K > 1) {
      char[] chars = S.toCharArray();
      Arrays.sort(chars);
      return String.valueOf(chars);
    }

    String ans = S;

    for (int i = 1; i < S.length(); ++i) {
      String S2 = S.substring(i) + S.substring(0, i);
      if (ans.compareTo(S2) > 0)
        ans = S2;
    }

    return ans;
  }
}
