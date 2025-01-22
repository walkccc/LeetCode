class Solution {
  public int reachNumber(int target) {
    final int newTarget = Math.abs(target);
    int ans = 0;
    int pos = 0;

    while (pos < newTarget)
      pos += ++ans;
    while ((pos - newTarget) % 2 == 1)
      pos += ++ans;

    return ans;
  }
}
