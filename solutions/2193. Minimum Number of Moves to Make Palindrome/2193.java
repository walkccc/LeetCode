class Solution {
  public int minMovesToMakePalindrome(String s) {
    int ans = 0;
    StringBuilder sb = new StringBuilder(s);

    while (sb.length() > 1) {
      // Greedily match the last digit.
      final int i = sb.indexOf(sb.substring(sb.length() - 1));
      if (i == sb.length() - 1) {
        // s[i] is the middle letter.
        ans += i / 2;
      } else {
        sb.deleteCharAt(i);
        ans += i; // Swap the matched letter to the left.
      }
      sb.deleteCharAt(sb.length() - 1);
    }

    return ans;
  }
}
