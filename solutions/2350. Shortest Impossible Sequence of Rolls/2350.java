class Solution {
  public int shortestSequence(int[] rolls, int k) {
    int ans = 1; // next target length
    Set<Integer> seen = new HashSet<>();

    for (final int roll : rolls) {
      seen.add(roll);
      if (seen.size() == k) {
        // have all combinations that form `ans` length, and we are going to
        // extend the sequence to `ans + 1` length
        ++ans;
        seen.clear();
      }
    }

    return ans;
  }
}
