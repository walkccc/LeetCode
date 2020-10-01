class Solution {
  public int reachNumber(int target) {
    int ans = 0;
    int pos = 0;
    target = Math.abs(target);

    while (pos < target)
      pos += ++ans;
    while ((pos - target) % 2 == 1)
      pos += ++ans;

    return ans;
  }
}