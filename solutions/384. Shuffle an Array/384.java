class Solution {
  public Solution(int[] nums) {
    this.nums = nums;
  }

  public int[] reset() {
    return nums;
  }

  public int[] shuffle() {
    int[] arr = nums.clone();
    for (int i = arr.length - 1; i > 0; --i) {
      final int j = rand.nextInt(i + 1);
      swap(arr, i, j);
    }
    return arr;
  }

  private int[] nums;
  private Random rand = new Random();

  private void swap(int[] arr, int i, int j) {
    final int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}
