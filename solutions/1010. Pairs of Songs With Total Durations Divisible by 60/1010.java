class Solution {
  public int numPairsDivisibleBy60(int[] time) {
    int ans = 0;
    int[] count = new int[60];

    for (int t : time) {
      t %= 60;
      ans += count[(60 - t) % 60];
      ++count[t];
    }

    return ans;
  }
}
