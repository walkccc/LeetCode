class Solution {
  public int numSubarraysWithSum(int[] A, int S) {
    int ans = 0;
    int prefixSum = 0;
    Map<Integer, Integer> count = new HashMap<>();

    count.put(0, 1);

    for (int a : A) {
      prefixSum += a;
      if (count.containsKey(prefixSum - S))
        ans += count.get(prefixSum - S);
      count.put(prefixSum, count.getOrDefault(prefixSum, 0) + 1);
    }

    return ans;
  }
}