class Item {
  public int i;
  public int j;
  public int num; // nums[i][j]

  public Item(int i, int j, int num) {
    this.i = i;
    this.j = j;
    this.num = num;
  }
}

class Solution {
  public int[] smallestRange(List<List<Integer>> nums) {
    PriorityQueue<Item> pq = new PriorityQueue<>((a, b) -> a.num - b.num);
    int min = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;

    for (int i = 0; i < nums.size(); ++i) {
      final int num = nums.get(i).get(0);
      pq.offer(new Item(i, 0, num));
      min = Math.min(min, num);
      max = Math.max(max, num);
    }

    int minRange = min;
    int maxRange = max;

    while (pq.size() == nums.size()) {
      final int i = pq.peek().i;
      final int j = pq.poll().j;
      if (j + 1 < nums.get(i).size()) {
        pq.offer(new Item(i, j + 1, nums.get(i).get(j + 1)));
        max = Math.max(max, nums.get(i).get(j + 1));
        min = pq.peek().num;
      }
      if (max - min < maxRange - minRange) {
        minRange = min;
        maxRange = max;
      }
    }

    return new int[] {minRange, maxRange};
  }
}
