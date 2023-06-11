class Solution {
  public Solution(int[] nums) {
    this.nums = nums;
  }

  /** Resets the array to its original configuration and return it. */
  public int[] reset() {
    return nums;
  }

  /** Returns a random shuffling of the array. */
  public int[] shuffle() {
    int[] A = nums.clone();
    for (int i = A.length - 1; i > 0; --i) {
      final int j = rand.nextInt(i + 1);
      swap(A, i, j);
    }
    return A;
  }

  private int[] nums;
  private Random rand = new Random();

  private void swap(int[] A, int i, int j) {
    final int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
  }
}
