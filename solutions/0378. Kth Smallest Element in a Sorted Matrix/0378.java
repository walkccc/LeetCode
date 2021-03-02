class T {
  public int i;
  public int j;
  public int num; // matrix[i][j]

  public T(int i, int j, int num) {
    this.i = i;
    this.j = j;
    this.num = num;
  }
}

class Solution {
  public int kthSmallest(int[][] matrix, int k) {
    PriorityQueue<T> pq = new PriorityQueue<>((a, b) -> a.num - b.num);

    for (int i = 0; i < k && i < matrix.length; ++i)
      pq.offer(new T(i, 0, matrix[i][0]));

    while (k-- > 1) {
      final int i = pq.peek().i;
      final int j = pq.poll().j;
      if (j + 1 < matrix[0].length)
        pq.offer(new T(i, j + 1, matrix[i][j + 1]));
    }

    return pq.peek().num;
  }
}
