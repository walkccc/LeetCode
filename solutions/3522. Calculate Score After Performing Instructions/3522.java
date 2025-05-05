class Solution {
  public long calculateScore(String[] instructions, int[] values) {
    final int n = instructions.length;
    long ans = 0;
    int i = 0;
    boolean[] seen = new boolean[n];

    while (i >= 0 && i < n && !seen[i]) {
      seen[i] = true;
      if (instructions[i].equals("add")) {
        ans += values[i];
        ++i;
      } else if (instructions[i].equals("jump")) {
        i += values[i];
      }
    }

    return ans;
  }
}
