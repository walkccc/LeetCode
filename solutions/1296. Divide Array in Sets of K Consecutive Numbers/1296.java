class Solution {
  public boolean isPossibleDivide(int[] nums, int k) {
    TreeMap<Integer, Integer> count = new TreeMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int start : count.keySet()) {
      final int value = count.getOrDefault(start, 0);
      if (value > 0)
        for (int i = start; i < start + k; ++i)
          if (count.merge(i, -value, Integer::sum) < 0)
            return false;
    }

    return true;
  }
}
