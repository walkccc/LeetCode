class Solution {
  public String nextPalindrome(String num) {
    final int n = num.length();
    int[] arr = new int[n / 2];

    for (int i = 0; i < arr.length; ++i)
      arr[i] = num.charAt(i) - '0';

    if (!nextPermutation(arr))
      return "";

    StringBuilder sb = new StringBuilder();

    for (final int a : arr)
      sb.append(a);

    if (n % 2 == 1)
      return sb.toString() + num.charAt(n / 2) + sb.reverse().toString();
    return sb.toString() + sb.reverse().toString();
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
