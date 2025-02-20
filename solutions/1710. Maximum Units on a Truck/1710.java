class Solution {
  public int maximumUnits(int[][] boxTypes, int truckSize) {
    int ans = 0;

    Arrays.sort(boxTypes, (a, b) -> Integer.compare(b[1], a[1]));

    for (int[] boxType : boxTypes) {
      final int boxes = boxType[0];
      final int units = boxType[1];
      if (boxes >= truckSize)
        return ans + truckSize * units;
      ans += boxes * units;
      truckSize -= boxes;
    }

    return ans;
  }
}
