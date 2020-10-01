class Solution {
  public String countAndSay(int n) {
    StringBuilder ans = new StringBuilder("1");

    while (--n > 0) {
      StringBuilder next = new StringBuilder();
      for (int i = 0; i < ans.length(); ++i) {
        int count = 1;
        while (i + 1 < ans.length() && ans.charAt(i) == ans.charAt(i + 1)) {
          ++count;
          ++i;
        }
        next.append(count).append(ans.charAt(i));
      }
      ans = next;
    }

    return ans.toString();
  }
}