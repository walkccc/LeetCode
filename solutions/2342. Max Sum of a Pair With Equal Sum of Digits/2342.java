class Solution {
  public int maximumSum(int[] nums) {
    final int kMax = 9 * 9; // 999,999,999
    int ans = -1;
    List<Integer>[] count = new List[kMax + 1];

    for (int i = 0; i <= kMax; ++i)
      count[i] = new ArrayList<>();

    for (final int num : nums)
      count[getSum(num)].add(num);

    for (List<Integer> groupNums : count) {
      if (groupNums.size() < 2)
        continue;
      Collections.sort(groupNums, Collections.reverseOrder());
      ans = Math.max(ans, groupNums.get(0) + groupNums.get(1));
    }

    return ans;
  }

  private int getSum(int num) {
    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return sum;
  }
}
