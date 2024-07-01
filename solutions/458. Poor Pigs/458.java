class Solution {
  public int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
    final int base = minutesToTest / minutesToDie + 1;
    int ans = 0;
    for (int x = 1; x < buckets; x *= base)
      ++ans;
    return ans;
  }
}
