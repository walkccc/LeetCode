class Solution {
  public int subarraysDivByK(int[] A, int K) {
    int ans = 0;
    int prefix = 0;
    int[] count = new int[K];
    count[0] = 1;

    for (int a : A) {
      prefix = (prefix + a % K + K) % K;
      ans += count[prefix];
      ++count[prefix];
    }

    return ans;
  }
}
