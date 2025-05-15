class Solution {
  public int findKthLargest(int[] nums, int k) {
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int num : nums) {
      minHeap.offer(num);
      while (minHeap.size() > k)
        minHeap.poll();
    }

    return minHeap.peek();
  }
}
