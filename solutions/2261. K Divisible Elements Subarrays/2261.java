class TrieNode {
  public Map<Integer, TrieNode> children = new HashMap<>();
  public int count = 0;
}

class Solution {
  public int countDistinct(int[] nums, int k, int p) {
    for (int i = 0; i < nums.length; ++i)
      insert(root, nums, i, k, p);
    return ans;
  }

  private int ans = 0;
  private TrieNode root = new TrieNode();

  private void insert(TrieNode node, int[] nums, int i, int k, int p) {
    if (i == nums.length || k - (nums[i] % p == 0 ? 1 : 0) < 0)
      return;
    if (!node.children.containsKey(nums[i])) {
      node.children.put(nums[i], new TrieNode());
      ++ans;
    }
    insert(node.children.get(nums[i]), nums, i + 1, k - (nums[i] % p == 0 ? 1 : 0), p);
  }
}
