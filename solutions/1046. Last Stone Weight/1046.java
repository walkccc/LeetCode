class Solution {
  public int lastStoneWeight(int[] stones) {
    Queue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

    for (final int stone : stones)
      pq.offer(stone);

    while (pq.size() >= 2) {
      final int n1 = pq.poll();
      final int n2 = pq.poll();
      if (n1 != n2)
        pq.offer(n1 - n2);
    }

    return pq.isEmpty() ? 0 : pq.peek();
  }
}
