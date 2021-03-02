class Solution {
  public int findKthLargest(int[] nums, int k) {
    PriorityQueue<Integer> pq = new PriorityQueue<>((a, b) -> a - b); // min-heap

    for (final int num : nums) {
      pq.offer(num);
      while (pq.size() > k)
        pq.poll();
    }

    return pq.peek();
  }
}
