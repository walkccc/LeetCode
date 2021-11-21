public class Solution {
  public int thirdMax(int[] nums) {
    Queue<Integer> pq = new PriorityQueue<>(); // min-heap
    Set<Integer> seen = new HashSet<>();

    for (final int num : nums)
      if (seen.add(num)) {
        pq.offer(num);
        if (pq.size() > 3)
          pq.poll();
      }

    if (pq.size() == 2)
      pq.poll();

    return pq.peek();
  }
}
