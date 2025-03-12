class Solution {
  // Similar to 215. Kth Largest Element in an Array
  public String kthLargestNumber(String[] nums, int k) {
    Queue<String> minHeap = new PriorityQueue<>(
        (a, b) //
        -> a.length() == b.length() ? a.compareTo(b) : Integer.compare(a.length(), b.length()));

    for (final String num : nums) {
      minHeap.offer(num);
      if (minHeap.size() > k)
        minHeap.poll();
    }

    return minHeap.poll();
  }
}
