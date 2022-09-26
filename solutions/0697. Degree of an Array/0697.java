class Solution {
  public int findShortestSubArray(int[] nums) {
    int ans = 0;
    int degree = 0;
    Map<Integer, Integer> debut = new HashMap<>();
    Map<Integer, Integer> count = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      final int num = nums[i];
      debut.putIfAbsent(num, i);
      count.put(num, count.getOrDefault(num, 0) + 1);
      if (count.get(num) > degree) {
        degree = count.get(num);
        ans = i - debut.get(num) + 1;
      } else if (count.get(num) == degree) {
        ans = Math.min(ans, i - debut.get(num) + 1);
      }
    }

    return ans;
  }
}
