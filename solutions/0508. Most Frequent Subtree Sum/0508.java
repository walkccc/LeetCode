class Solution {
  public int[] findFrequentTreeSum(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();
    int maxFreq = 0;

    dfs(root, count);

    for (int freq : count.values())
      maxFreq = Math.max(maxFreq, freq);

    for (int sum : count.keySet())
      if (count.get(sum) == maxFreq)
        ans.add(sum);

    return ans.stream().mapToInt(i -> i).toArray();
  }

  private int dfs(TreeNode root, Map<Integer, Integer> count) {
    if (root == null)
      return 0;

    int sum = root.val + dfs(root.left, count) + dfs(root.right, count);
    count.put(sum, count.getOrDefault(sum, 0) + 1);

    return sum;
  }
}