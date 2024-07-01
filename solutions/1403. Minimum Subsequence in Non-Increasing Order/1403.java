class Solution {
  public List<Integer> minSubsequence(int[] nums) {
    List<Integer> ans = new ArrayList<>();
    Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    for (final int num : nums)
      maxHeap.offer(num);
    int half = Arrays.stream(nums).sum() / 2;

    while (half >= 0) {
      ans.add(maxHeap.peek());
      half -= maxHeap.poll();
    }

    return ans;
  }
}
