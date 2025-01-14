class Solution {
  public List<Integer> findLonely(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();

    for (final int num : nums)
      count.merge(num, 1, Integer::sum);

    for (final int num : count.keySet())
      if (count.get(num) == 1 && !count.containsKey(num - 1) && !count.containsKey(num + 1))
        ans.add(num);

    return ans;
  }
}
