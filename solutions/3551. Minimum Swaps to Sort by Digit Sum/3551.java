class Solution {
  public int minSwaps(int[] nums) {
    int ans = 0;
    Set<Integer> seen = new HashSet<>();
    Map<Integer, Integer> numToIndex = new HashMap<>();
    int[] sortedNums = Arrays.stream(nums)
                           .boxed()
                           .sorted(Comparator.comparingInt((Integer num) -> getDigitSum(num))
                                       .thenComparingInt(num -> num))
                           .mapToInt(Integer::intValue)
                           .toArray();

    for (int i = 0; i < sortedNums.length; ++i)
      numToIndex.put(sortedNums[i], i);

    for (int i = 0; i < nums.length; ++i) {
      if (seen.contains(i) || numToIndex.get(nums[i]) == i)
        continue;
      int cycleSize = 0;
      int j = i;
      while (seen.add(j)) {
        j = numToIndex.get(nums[j]);
        ++cycleSize;
      }
      ans += Math.max(cycleSize - 1, 0);
    }

    return ans;
  }

  private int getDigitSum(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
}
