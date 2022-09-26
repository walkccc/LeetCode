class Solution {
  public int getMinSwaps(String num, int k) {
    int[] A = new int[num.length()]; // original

    for (int i = 0; i < A.length; ++i)
      A[i] = num.charAt(i) - '0';

    int[] B = A.clone(); // permutated

    for (int i = 0; i < k; ++i)
      nextPermutation(B);

    return countSteps(A, B);
  }

  public void nextPermutation(int[] nums) {
    final int n = nums.length;

    // from back to front, find the first num < nums[i + 1]
    int i;
    for (i = n - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    // from back to front, find the first num > nums[i], swap it with nums[i]
    if (i >= 0)
      for (int j = n - 1; j > i; --j)
        if (nums[j] > nums[i]) {
          swap(nums, i, j);
          break;
        }

    // reverse nums[i + 1..n - 1]
    reverse(nums, i + 1, n - 1);
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

  private int countSteps(int[] A, int[] B) {
    int count = 0;

    for (int i = 0, j = 0; i < A.length; ++i) {
      j = i;
      while (A[i] != B[j])
        ++j;
      while (i < j) {
        swap(B, j, j - 1);
        --j;
        ++count;
      }
    }

    return count;
  }
}
