class Solution {
  public int minimumDeviation(int[] nums) {
    int ans = Integer.MAX_VALUE;
    int mn = Integer.MAX_VALUE;
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    for (final int num : nums) {
      final int evenNum = num % 2 == 0 ? num : num * 2;
      mn = Math.min(mn, evenNum);
      maxHeap.offer(evenNum);
    }

    while (maxHeap.peek() % 2 == 0) {
      final int mx = maxHeap.poll();
      ans = Math.min(ans, mx - mn);
      mn = Math.min(mn, mx / 2);
      maxHeap.offer(mx / 2);
    }

    return Math.min(ans, maxHeap.peek() - mn);
  }
}
