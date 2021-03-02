class MedianFinder {
  public void addNum(int num) {
    if (l.isEmpty() || num <= l.peek())
      l.offer(num);
    else
      r.offer(num);

    // balance two heaps s.t. |l| >= |r| and |l| - |r| <= 1
    if (l.size() < r.size())
      l.offer(r.poll());
    else if (l.size() - r.size() > 1)
      r.offer(l.poll());
  }

  public double findMedian() {
    if (l.size() == r.size())
      return (double) (l.peek() + r.peek()) / 2.0;
    return (double) l.peek();
  }

  private PriorityQueue<Integer> l = new PriorityQueue<>(Collections.reverseOrder()); // max-heap
  private PriorityQueue<Integer> r = new PriorityQueue<>(); // min-heap
}
