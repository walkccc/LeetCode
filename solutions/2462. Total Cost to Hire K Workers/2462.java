class Solution {
  public long totalCost(int[] costs, int k, int candidates) {
    long ans = 0;
    int i = 0;
    int j = costs.length - 1;
    Queue<Integer> minHeapL = new PriorityQueue<>();
    Queue<Integer> minHeapR = new PriorityQueue<>();

    for (int hired = 0; hired < k; ++hired) {
      while (minHeapL.size() < candidates && i <= j)
        minHeapL.offer(costs[i++]);
      while (minHeapR.size() < candidates && i <= j)
        minHeapR.offer(costs[j--]);
      if (minHeapL.isEmpty())
        ans += minHeapR.poll();
      else if (minHeapR.isEmpty())
        ans += minHeapL.poll();
      // Both `minHeapL` and `minHeapR` are not empty.
      else if (minHeapL.peek() <= minHeapR.peek())
        ans += minHeapL.poll();
      else
        ans += minHeapR.poll();
    }

    return ans;
  }
}
