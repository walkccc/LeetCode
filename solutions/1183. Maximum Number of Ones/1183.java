class Solution {
  public int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
    int ans = 0;
    int[][] submatrix = new int[sideLength][sideLength];
    Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

    for (int i = 0; i < width; ++i)
      for (int j = 0; j < height; ++j)
        ++submatrix[i % sideLength][j % sideLength];

    for (int[] row : submatrix)
      for (final int a : row)
        maxHeap.offer(a);

    for (int i = 0; i < maxOnes; ++i)
      ans += maxHeap.poll();

    return ans;
  }
}
