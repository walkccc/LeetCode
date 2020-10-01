class Solution {
  public boolean isPossibleDivide(int[] nums, int k) {
    TreeMap<Integer, Integer> count = new TreeMap<>();
    for (int num : nums)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (int key : count.keySet()) {
      int value = count.getOrDefault(key, 0);
      if (value > 0)
        for (int i = key; i < key + k; ++i) {
          count.put(i, count.getOrDefault(i, 0) - value);
          if (count.get(i) < 0)
            return false;
        }
    }

    return true;
  }
}