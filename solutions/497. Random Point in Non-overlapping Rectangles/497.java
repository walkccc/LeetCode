class Solution {
  public Solution(int[][] rects) {
    this.rects = rects;
    areas = new int[rects.length];
    for (int i = 0; i < rects.length; ++i)
      areas[i] = getArea(rects[i]) + (i > 0 ? areas[i - 1] : 0);
  }

  public int[] pick() {
    final int target = rand.nextInt(areas[areas.length - 1]);
    final int index = firstGreater(areas, target);
    final int[] r = rects[index];
    return new int[] {
        rand.nextInt(r[2] - r[0] + 1) + r[0],
        rand.nextInt(r[3] - r[1] + 1) + r[1],
    };
  }

  private int[][] rects;
  private int[] areas;
  private Random rand = new Random();

  private int getArea(int[] r) {
    return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
  }

  private int firstGreater(int[] A, int target) {
    final int i = Arrays.binarySearch(A, target + 1);
    return i < 0 ? -i - 1 : i;
  }
}
