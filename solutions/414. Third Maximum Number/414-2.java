public class Solution {
  public int thirdMax(int[] nums) {
    Queue<Integer> minHeap = new PriorityQueue<>();
    Set<Integer> seen = new HashSet<>();

    for (final int num : nums)
      if (seen.add(num)) {
        minHeap.offer(num);
        if (minHeap.size() > 3)
          minHeap.poll();
      }

    if (minHeap.size() == 2)
      minHeap.poll();

    return minHeap.peek();
  }
}
