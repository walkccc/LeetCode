class Solution {
  public int[][] kClosest(int[][] points, int k) {
    int[][] ans = new int[k][2];
    Queue<int[]> maxHeap =
        new PriorityQueue<>((a, b) -> Integer.compare(squareDist(b), squareDist(a)));

    for (int[] point : points) {
      maxHeap.offer(point);
      if (maxHeap.size() > k)
        maxHeap.poll();
    }

    int i = k;
    while (!maxHeap.isEmpty())
      ans[--i] = maxHeap.poll();

    return ans;
  }

  private int squareDist(int[] p) {
    return p[0] * p[0] + p[1] * p[1];
  }
}
