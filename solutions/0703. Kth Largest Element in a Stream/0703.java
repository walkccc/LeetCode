class KthLargest {
  public KthLargest(int k, int[] nums) {
    this.k = k;
    for (final int num : nums)
      heapify(num);
  }

  public int add(int val) {
    heapify(val);
    return pq.peek();
  }

  private final int k;
  private PriorityQueue<Integer> pq = new PriorityQueue<>();

  private void heapify(int val) {
    pq.offer(val);
    if (pq.size() > k)
      pq.poll();
  }
}
