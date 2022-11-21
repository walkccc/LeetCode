class Solution {
  public int[][] kClosest(int[][] points, int K) {
    int[][] ans = new int[K][2];
    PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> squareDist(b) - squareDist(a));

    for (int[] p : points) {
      maxHeap.offer(p);
      if (maxHeap.size() > K)
        maxHeap.poll();
    }

    int i = K;
    while (!maxHeap.isEmpty())
      ans[--i] = maxHeap.poll();

    return ans;
  }

  private int squareDist(int[] p) {
    return p[0] * p[0] + p[1] * p[1];
  }
}
