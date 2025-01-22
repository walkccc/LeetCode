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
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> Integer.compare(a.num, b.num));

    for (int i = 0; i < k && i < matrix.length; ++i)
      minHeap.offer(new T(i, 0, matrix[i][0]));

    while (k-- > 1) {
      final int i = minHeap.peek().i;
      final int j = minHeap.poll().j;
      if (j + 1 < matrix[0].length)
        minHeap.offer(new T(i, j + 1, matrix[i][j + 1]));
    }

    return minHeap.peek().num;
  }
}
