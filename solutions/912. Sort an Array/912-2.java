class Solution {
  public int[] sortArray(int[] nums) {
    heapSort(nums);
    return nums;
  }

  private void heapSort(int[] nums) {
    buildMaxHeap(nums);
    int heapSize = nums.length;
    for (int i = nums.length - 1; i > 0; --i) {
      swap(nums, i, 0);
      --heapSize;
      maxHeapify(nums, 0, heapSize);
    }
  }

  private void buildMaxHeap(int[] nums) {
    for (int i = nums.length / 2; i >= 0; --i)
      maxHeapify(nums, i, nums.length);
  }

  private void maxHeapify(int[] nums, int i, int heapSize) {
    final int l = 2 * i + 1;
    final int r = 2 * i + 2;
    int largest = i;
    if (l < heapSize && nums[largest] < nums[l])
      largest = l;
    if (r < heapSize && nums[largest] < nums[r])
      largest = r;
    if (largest != i) {
      swap(nums, largest, i);
      maxHeapify(nums, largest, heapSize);
    }
  }

  private void swap(int[] nums, int i, int j) {
    final int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}
