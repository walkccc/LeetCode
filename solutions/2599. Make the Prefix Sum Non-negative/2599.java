class Solution {
  public int makePrefSumNonNegative(int[] nums) {
    int ans = 0;
    long prefix = 0;
    Queue<Integer> minHeap = new PriorityQueue<>();

    for (final int num : nums) {
      prefix += num;
      if (num < 0)
        minHeap.offer(num);
      while (prefix < 0) {
        prefix -= minHeap.poll();
        ++ans;
      }
    }

    return ans;
  }
}
