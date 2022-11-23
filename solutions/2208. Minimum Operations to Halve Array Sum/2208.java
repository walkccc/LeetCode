class Solution {
  public int halveArray(int[] nums) {
    final double halfSum = Arrays.stream(nums).asDoubleStream().sum() / 2;
    int ans = 0;
    double runningSum = 0;
    Queue<Double> maxHeap = new PriorityQueue<>(Collections.reverseOrder());

    for (final double num : nums)
      maxHeap.offer(num);

    while (runningSum < halfSum) {
      final double maxValue = maxHeap.poll() / 2;
      runningSum += maxValue;
      maxHeap.offer(maxValue);
      ++ans;
    }

    return ans;
  }
}
