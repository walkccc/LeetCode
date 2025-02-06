class Solution {
  public int maxOperations(int[] nums) {
    final int n = nums.length;
    Map<String, Integer> mem = new HashMap<>();
    return Math.max(Math.max(maxOperations(nums, 0, n - 1, nums[0] + nums[1], mem),
                             maxOperations(nums, 0, n - 1, nums[n - 1] + nums[n - 2], mem)),
                    maxOperations(nums, 0, n - 1, nums[0] + nums[n - 1], mem));
  }

  // Returns the maximum number of operations that can be performed for
  // nums[i..j], s.t. all operations have the same `score`.
  private int maxOperations(int[] nums, int i, int j, int score, Map<String, Integer> mem) {
    if (i >= j)
      return 0;
    final String key = hash(i, j, score);
    if (mem.containsKey(key))
      return mem.get(key);
    final int deleteFirstTwo =
        nums[i] + nums[i + 1] == score ? 1 + maxOperations(nums, i + 2, j, score, mem) : 0;
    final int deleteLastTwo =
        nums[j] + nums[j - 1] == score ? 1 + maxOperations(nums, i, j - 2, score, mem) : 0;
    final int deleteFirstAndLast =
        nums[i] + nums[j] == score ? 1 + maxOperations(nums, i + 1, j - 1, score, mem) : 0;
    mem.put(key, Math.max(Math.max(deleteFirstTwo, deleteLastTwo), deleteFirstAndLast));
    return mem.get(key);
  }

  private String hash(int i, int j, int score) {
    return i + "," + j + "," + score;
  }
}
