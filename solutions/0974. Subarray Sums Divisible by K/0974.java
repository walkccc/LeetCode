class Solution {
  public int subarraysDivByK(int[] A, int K) {
    int ans = 0;
    int prefixSum = 0;
    int[] count = new int[K];
    count[0] = 1;

    for (int a : A) {
      prefixSum = (prefixSum + a % K + K) % K;
      ans += count[prefixSum];
      ++count[prefixSum];
    }

    return ans;
  }
}