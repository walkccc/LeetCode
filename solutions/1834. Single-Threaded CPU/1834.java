class Solution {
  public int[] getOrder(int[][] tasks) {
    record T(int procTime, int index) {}
    final int n = tasks.length;
    int[][] A = new int[n][3];

    for (int i = 0; i < n; ++i) {
      A[i][0] = tasks[i][0];
      A[i][1] = tasks[i][1];
      A[i][2] = i;
    }

    int[] ans = new int[n];
    int ansIndex = 0;
    Queue<T> minHeap =
        new PriorityQueue<>(Comparator.comparingInt(T::procTime).thenComparingInt(T::index));
    int i = 0;     // tasks' index
    long time = 0; // the current time

    Arrays.sort(A, Comparator.comparingInt(a -> a[0]));

    while (i < n || !minHeap.isEmpty()) {
      if (minHeap.isEmpty())
        time = Math.max(time, (long) A[i][0]);
      while (i < n && time >= (long) A[i][0]) {
        minHeap.offer(new T(A[i][1], A[i][2]));
        ++i;
      }
      final int procTime = minHeap.peek().procTime;
      final int index = minHeap.poll().index;
      time += procTime;
      ans[ansIndex++] = index;
    }

    return ans;
  }
}
