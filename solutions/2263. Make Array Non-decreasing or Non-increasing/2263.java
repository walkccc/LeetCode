class Solution {
  public int convertArray(int[] nums) {
    return Math.min(cost(nums), cost(negative(nums)));
  }

  private int cost(int[] nums) {
    int ans = 0;
    Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

    // Greedily make `nums` non-decreasing.
    for (final int num : nums) {
      if (!maxHeap.isEmpty() && maxHeap.peek() > num) {
        ans += maxHeap.poll() - num;
        maxHeap.offer(num);
      }
      maxHeap.offer(num);
    }

    return ans;
  }

  private int[] negative(int[] nums) {
    int[] A = nums.clone();
    for (int i = 0; i < A.length; ++i)
      A[i] *= -1;
    return A;
  }
}
