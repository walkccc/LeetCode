class Solution {
  public int maxJump(int[] stones) {
    // Let's denote the forwarding path as F and the backwarding path as B.
    // "F1 B2 B1 F2" is no better than "F1 B2 F2 B1" since the distance between
    // F1 and F2 increase, resulting a larger `ans`.
    int ans = stones[1] - stones[0]; // If there're only two stones.
    for (int i = 2; i < stones.length; ++i)
      ans = Math.max(ans, stones[i] - stones[i - 2]);
    return ans;
  }
}
