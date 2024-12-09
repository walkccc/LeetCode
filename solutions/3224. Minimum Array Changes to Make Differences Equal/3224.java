class Solution {
  public int minChanges(int[] nums, int k) {
    final int n = nums.length;
    final int pairSize = n / 2;
    int ans = n;
    Map<Integer, Integer> diffCount = new HashMap<>(); // {abs(nums[-i - 1] - nums[i]): freq}
    // oneChangeCount[i] := the number of pairs that need only one change to
    // achieve a difference of `i`
    int[] oneChangeCount = new int[k + 1];

    for (int i = 0; i < pairSize; ++i) {
      final int a = nums[i];
      final int b = nums[n - i - 1];
      diffCount.merge(Math.abs(a - b), 1, Integer::sum);
      ++oneChangeCount[Math.max(Math.max(a, b), Math.max(k - a, k - b))];
    }

    // prefixOneChangeCount[i] := the number of pairs that need only one change
    // to achieve a difference >= `i`
    // prefixOneChangeCount[i] = sum(oneChangeCount[i..k])
    int[] prefixOneChangeCount = oneChangeCount.clone();

    for (int i = k - 1; i >= 0; --i)
      prefixOneChangeCount[i] += prefixOneChangeCount[i + 1];

    for (Map.Entry<Integer, Integer> entry : diffCount.entrySet()) {
      final int diff = entry.getKey();
      final int freq = entry.getValue();
      final int oneChange = prefixOneChangeCount[diff] - freq;
      final int twoChanges = (pairSize - prefixOneChangeCount[diff]) * 2;
      ans = Math.min(ans, oneChange + twoChanges);
    }

    return ans;
  }
}
