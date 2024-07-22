class Solution {
  public int minimumDeviation(int[] nums) {
    int ans = Integer.MAX_VALUE;
    int min = Integer.MAX_VALUE;
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    for (final int num : nums) {
      final int evenNum = num % 2 == 0 ? num : num * 2;
      min = Math.min(min, evenNum);
      maxHeap.offer(evenNum);
    }

    while (maxHeap.peek() % 2 == 0) {
      final int max = maxHeap.poll();
      ans = Math.min(ans, max - min);
      min = Math.min(min, max / 2);
      maxHeap.offer(max / 2);
    }

    return Math.min(ans, maxHeap.peek() - min);
  }
}
