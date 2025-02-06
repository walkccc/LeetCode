class Solution {
  public String nextClosestTime(String time) {
    char[] ans = time.toCharArray();
    Character[] digits = {ans[0], ans[1], ans[3], ans[4]};
    TreeSet<Character> digitsSet = new TreeSet<Character>(Arrays.asList(digits));

    ans[4] = nextClosest(digitsSet, ans[4], '9');
    if (time.charAt(4) < ans[4])
      return new String(ans);

    ans[3] = nextClosest(digitsSet, ans[3], '5');
    if (time.charAt(3) < ans[3])
      return new String(ans);

    ans[1] = nextClosest(digitsSet, ans[1], ans[0] == '2' ? '3' : '9');
    if (time.charAt(1) < ans[1])
      return new String(ans);

    ans[0] = nextClosest(digitsSet, ans[0], '2');
    return new String(ans);
  }

  private char nextClosest(TreeSet<Character> digitsSet, char digit, char limit) {
    Character next = digitsSet.higher(digit);
    return next == null || next > limit ? digitsSet.first() : next;
  }
}
