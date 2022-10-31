class T {
  public int i;
  public int j;
  public int num; // nums[i][j]
  public T(int i, int j, int num) {
    this.i = i;
    this.j = j;
    this.num = num;
  }
}

class Solution {
  public int[] smallestRange(List<List<Integer>> nums) {
    Queue<T> minHeap = new PriorityQueue<>((a, b) -> a.num - b.num);
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;

    for (int i = 0; i < nums.size(); ++i) {
      final int num = nums.get(i).get(0);
      minHeap.offer(new T(i, 0, num));
      min = Math.min(min, num);
      max = Math.max(max, num);
    }

    int minRange = min;
    int maxRange = max;

    while (minHeap.size() == nums.size()) {
      final int i = minHeap.peek().i;
      final int j = minHeap.poll().j;
      if (j + 1 < nums.get(i).size()) {
        minHeap.offer(new T(i, j + 1, nums.get(i).get(j + 1)));
        max = Math.max(max, nums.get(i).get(j + 1));
        min = minHeap.peek().num;
      }
      if (max - min < maxRange - minRange) {
        minRange = min;
        maxRange = max;
      }
    }

    return new int[] {minRange, maxRange};
  }
}
