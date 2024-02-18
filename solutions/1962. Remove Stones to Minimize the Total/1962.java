class Solution {
  public int minStoneSum(int[] piles, int k) {
    int ans = Arrays.stream(piles).sum();
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    for (final int pile : piles)
      maxHeap.offer(pile);

    for (int i = 0; i < k; ++i) {
      final int maxPile = maxHeap.poll();
      maxHeap.offer(maxPile - maxPile / 2);
      ans -= maxPile / 2;
    }

    return ans;
  }
}
