class Solution {
  public int[] recoverArray(int[] nums) {
    final int n = nums.length;
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    Arrays.sort(nums);

    for (int i = 1; i < n; ++i) {
      final int x = nums[i] - nums[0]; // 2 * k
      if (x <= 0 || x % 2 == 1)
        continue;
      Map<Integer, Integer> countCopy = new HashMap<>();
      countCopy.putAll(count);
      int[] A = getArray(nums, x, countCopy);
      if (A.length == n / 2)
        return A;
    }

    throw new IllegalArgumentException();
  }

  private int[] getArray(int[] nums, int x, Map<Integer, Integer> count) {
    List<Integer> A = new ArrayList<>();
    for (final int num : nums) {
      if (count.getOrDefault(num, 0) == 0)
        continue;
      if (count.getOrDefault(num + x, 0) == 0)
        return new int[] {};
      count.merge(num, -1, Integer::sum);
      count.merge(num + x, -1, Integer::sum);
      A.add(num + x / 2);
    }
    return A.stream().mapToInt(i -> i).toArray();
  }
}
