class T {
  public int size;
  public int right;
  public T(int size, int right) {
    this.size = size;
    this.right = right;
  }
}

class Solution {
  public int[] minInterval(int[][] intervals, int[] queries) {
    int[] ans = new int[queries.length];
    Arrays.fill(ans, -1);
    Queue<T> minHeap = new Queue<T>((a, b) -> a.size - b.size);
    Integer[] indices = new Integer[queries.length];

    for (int i = 0; i < queries.length; ++i)
      indices[i] = i;

    Arrays.sort(intervals, (a, b) -> a[0] - b[0]);
    Arrays.sort(indices, (a, b) -> queries[a] - queries[b]);

    int i = 0; // intervals' pointer
    for (final int index : indices) {
      while (i < intervals.length && intervals[i][0] <= queries[index]) {
        minHeap.offer(new T(intervals[i][1] - intervals[i][0] + 1, intervals[i][1]));
        ++i;
      }
      while (!minHeap.isEmpty() && minHeap.peek().right < queries[index])
        minHeap.poll();
      if (!minHeap.isEmpty())
        ans[index] = minHeap.peek().size;
    }

    return ans;
  }
}
