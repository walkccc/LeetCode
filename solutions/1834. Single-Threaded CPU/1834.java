class T {
  public int procTime;
  public int index;

  public T(int procTime, int index) {
    this.procTime = procTime;
    this.index = index;
  }
}

class Solution {
  public int[] getOrder(int[][] tasks) {
    final int n = tasks.length;

    int[][] A = new int[n][3];

    for (int i = 0; i < n; ++i) {
      A[i][0] = tasks[i][0];
      A[i][1] = tasks[i][1];
      A[i][2] = i;
    }

    int[] ans = new int[n];
    int ansIndex = 0;
    PriorityQueue<T> pq = new PriorityQueue<>(
        (a, b) -> a.procTime == b.procTime ? a.index - b.index : a.procTime - b.procTime);
    int i = 0;     // tasks' pointer
    long time = 0; // current time

    Arrays.sort(A, Comparator.comparing(a -> a[0]));

    while (i < n || !pq.isEmpty()) {
      if (pq.isEmpty())
        time = Math.max(time, (long) A[i][0]);
      while (i < n && time >= (long) A[i][0]) {
        pq.offer(new T(A[i][1], A[i][2]));
        ++i;
      }
      final int procTime = pq.peek().procTime;
      final int index = pq.poll().index;
      time += procTime;
      ans[ansIndex++] = index;
    }

    return ans;
  }
}
