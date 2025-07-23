
class Solution {
  public long[] findMaxSum(int[] nums1, int[] nums2, int k) {
    final int n = nums1.length;
    long[] ans = new long[n];
    Pair<Integer, Integer>[] numAndIndexes = new Pair[n];
    Queue<Long> minHeap = new PriorityQueue<>();

    for (int i = 0; i < n; ++i)
      numAndIndexes[i] = new Pair<>(nums1[i], i);

    Arrays.sort(numAndIndexes, Comparator.comparingInt(Pair::getKey));

    final int firstIndex = numAndIndexes[0].getValue();
    minHeap.offer((long) nums2[firstIndex]);
    long sum = nums2[firstIndex];

    for (int i = 1; i < n; ++i) {
      final int currNum = numAndIndexes[i].getKey();
      final int currIndex = numAndIndexes[i].getValue();
      final int prevNum = numAndIndexes[i - 1].getKey();
      final int prevIndex = numAndIndexes[i - 1].getValue();
      if (currNum == prevNum)
        ans[currIndex] = ans[prevIndex];
      else
        ans[currIndex] = sum;
      minHeap.offer((long) nums2[currIndex]);
      sum += nums2[currIndex];
      if (minHeap.size() == k + 1)
        sum -= minHeap.poll();
    }

    return ans;
  }
}
