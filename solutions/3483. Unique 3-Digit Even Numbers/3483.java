class Solution {
  public int totalNumbers(int[] digits) {
    Set<Integer> nums = new HashSet<>();
    int[] perm = digits.clone();

    Arrays.sort(perm);

    do {
      final int a = perm[0];
      final int b = perm[1];
      final int c = perm[2];
      if (a != 0 && c % 2 == 0) {
        nums.add(a * 100 + b * 10 + c);
      }
    } while (nextPermutation(perm));

    return nums.size();
  }

  private boolean nextPermutation(int[] nums) {
    final int n = nums.length;

    // From the back to the front, find the first num < nums[i + 1].
    int i;
    for (i = n - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    if (i < 0)
      return false;

    // From the back to the front, find the first num > nums[i] and swap it with
    // nums[i].
    for (int j = n - 1; j > i; --j)
      if (nums[j] > nums[i]) {
        swap(nums, i, j);
        break;
      }

    // Reverse nums[i + 1..n - 1].
    reverse(nums, i + 1, n - 1);
    return true;
  }

  private void reverse(int[] nums, int l, int r) {
    while (l < r)
      swap(nums, l++, r--);
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
