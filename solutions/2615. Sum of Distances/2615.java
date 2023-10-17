public class Solution {
  public long[] distance(int[] nums) {
    long[] ans = new long[nums.length];
    Map<Integer, List<Integer>> numToIndices = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      numToIndices.putIfAbsent(nums[i], new ArrayList<>());
      numToIndices.get(nums[i]).add(i);
    }

    for (List<Integer> indices : numToIndices.values()) {
      final int n = indices.size();
      if (n == 1) {
        continue;
      }
      long sumSoFar = indices.stream().mapToLong(Integer::intValue).sum();
      int prevIndex = 0;
      for (int i = 0; i < n; ++i) {
        sumSoFar += (i - 1) * (indices.get(i) - prevIndex);
        sumSoFar -= (n - i - 1) * (indices.get(i) - prevIndex);
        ans[indices.get(i)] = sumSoFar;
        prevIndex = indices.get(i);
      }
    }

    return ans;
  }
}
