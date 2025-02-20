class Solution {
  public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
    final long numsSum = Arrays.stream(nums).asLongStream().sum();
    // {the second: the index of nums can be zeroed at the current second}
    Map<Integer, Integer> secondToIndex = getSecondToIndex(nums, changeIndices);
    int l = 0;
    int r = changeIndices.length + 1;

    while (l < r) {
      final int m = (l + r) / 2;
      if (canMark(nums, secondToIndex, m))
        r = m;
      else
        l = m + 1;
    }

    return l <= changeIndices.length ? l : -1;
  }

  // Returns true if all indices of `nums` can be marked within `maxSecond`.
  private boolean canMark(int[] nums, Map<Integer, Integer> secondToIndex, int maxSecond,
                          final long numsSum) {
    // Use a min-heap to greedily pop out the minimum number, which yields the
    // least saving.
    Queue<Integer> minHeap = new PriorityQueue<>();
    int marks = 0;

    for (int second = maxSecond - 1; second >= 0; --second) {
      if (secondToIndex.containsKey(second)) {
        // The number mapped by the index is a candidate to be zeroed out.
        final int index = secondToIndex.get(second);
        minHeap.offer(nums[index]);
        if (marks == 0) {
          // Running out of marks, so need to pop out the minimum number.
          // So, the current second will be used to mark an index.
          minHeap.poll();
          ++marks;
        } else {
          // There're enough marks.
          // So, the current second will be used to zero out a number.
          --marks;
        }
      } else {
        // There's no candidate to be zeroed out.
        // So, the current second will be used to mark an index.
        ++marks;
      }
    }

    final int heapSize = minHeap.size();
    final long decrementAndMarkCost = numsSum - getHeapSum(minHeap) + (nums.length - heapSize);
    final long zeroAndMarkCost = heapSize + heapSize;
    return decrementAndMarkCost + zeroAndMarkCost <= maxSecond;
  }

  private long getHeapSum(Queue<Integer> minHeap) {
    long sum = 0;
    while (!minHeap.isEmpty())
      sum += minHeap.poll();
    return sum;
  }

  private Map<Integer, Integer> getSecondToIndex(int[] nums, int[] changeIndices) {
    // {the `index` of nums: the earliest second to zero out nums[index]}
    Map<Integer, Integer> indexToFirstSecond = new HashMap<>();
    Map<Integer, Integer> secondToIndex = new HashMap<>();
    for (int zeroIndexedSecond = 0; zeroIndexedSecond < changeIndices.length; ++zeroIndexedSecond) {
      // Convert to 0-indexed.
      final int index = changeIndices[zeroIndexedSecond] - 1;
      if (nums[index] > 0)
        indexToFirstSecond.putIfAbsent(index, zeroIndexedSecond);
    }
    for (Map.Entry<Integer, Integer> entry : indexToFirstSecond.entrySet()) {
      final int index = entry.getKey();
      final int second = entry.getValue();
      secondToIndex.put(second, index);
    }
    return secondToIndex;
  }
}
