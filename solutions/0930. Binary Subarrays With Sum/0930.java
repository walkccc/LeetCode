class Solution {
  public int numSubarraysWithSum(int[] A, int S) {
    int ans = 0;
    int prefix = 0;
    Map<Integer, Integer> count = new HashMap<>();

    count.put(0, 1);

    for (int a : A) {
      prefix += a;
      if (count.containsKey(prefix - S))
        ans += count.get(prefix - S);
      count.put(prefix, count.getOrDefault(prefix, 0) + 1);
    }

    return ans;
  }
}
