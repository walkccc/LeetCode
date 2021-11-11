class Solution {
  public int kthSmallest(TreeNode root, int k) {
    List<Integer> nums = new ArrayList<>();

    inorder(root, nums);

    return nums.get(k - 1);
  }

  private void inorder(TreeNode root, List<Integer> nums) {
    if (root == null)
      return;

    inorder(root.left, nums);
    nums.add(root.val);
    inorder(root.right, nums);
  }
}
