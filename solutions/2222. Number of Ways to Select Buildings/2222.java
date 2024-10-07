class Solution {
  public long numberOfWays(String s) {
    long ans = 0;
    // before[i] := the number of i before the current digit
    int[] before = new int[2];
    // after[i] := the number of i after the current digit
    int[] after = new int[2];
    after[0] = (int) s.chars().filter(c -> c == '0').count();
    after[1] = s.length() - after[0];

    for (final char c : s.toCharArray()) {
      final int num = c - '0';
      --after[num];
      if (num == 0)
        ans += before[1] * after[1];
      else
        ans += before[0] * after[0];
      ++before[num];
    }

    return ans;
  }
}
