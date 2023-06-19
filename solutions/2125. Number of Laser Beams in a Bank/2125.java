class Solution {
  public int numberOfBeams(String[] bank) {
    int ans = 0;
    int prevOnes = 0;

    for (final String row : bank) {
      final int ones = (int) row.chars().filter(c -> c == '1').count();
      if (ones > 0) {
        ans += prevOnes * ones;
        prevOnes = ones;
      }
    }

    return ans;
  }
}
