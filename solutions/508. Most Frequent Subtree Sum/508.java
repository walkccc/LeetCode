class Solution {
  public int[] findFrequentTreeSum(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();
    int maxCount = 0;

    sumDownFrom(root, count);

    for (final int freq : count.values())
      maxCount = Math.max(maxCount, freq);

    for (final int sum : count.keySet())
      if (count.get(sum) == maxCount)
        ans.add(sum);

    return ans.stream().mapToInt(Integer::intValue).toArray();
  }

  private int sumDownFrom(TreeNode root, Map<Integer, Integer> count) {
    if (root == null)
      return 0;

    final int sum = root.val + sumDownFrom(root.left, count) + sumDownFrom(root.right, count);
    count.merge(sum, 1, Integer::sum);
    return sum;
  }
}
