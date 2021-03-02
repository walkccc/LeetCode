class Solution {
  public int[][] kClosest(int[][] points, int K) {
    int[][] ans = new int[K][2];
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> squareDist(b) - squareDist(a));

    for (int[] point : points) {
      pq.offer(point);
      if (pq.size() > K)
        pq.poll();
    }

    int i = K;
    while (!pq.isEmpty())
      ans[--i] = pq.poll();

    return ans;
  }

  private int squareDist(int[] p) {
    return p[0] * p[0] + p[1] * p[1];
  }
}
