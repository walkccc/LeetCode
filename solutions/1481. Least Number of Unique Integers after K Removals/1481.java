class Solution {
  public int findLeastNumOfUniqueInts(int[] arr, int k) {
    Map<Integer, Integer> count = new HashMap<>();

    for (final int a : arr)
      count.merge(a, 1, Integer::sum);

    Queue<Integer> minHeap = new PriorityQueue<>(count.values());

    // Greedily remove the k least frequent numbers to have the least number of unique integers.
    while (k > 0)
      k -= minHeap.poll();

    return minHeap.size() + (k < 0 ? 1 : 0);
  }
}
