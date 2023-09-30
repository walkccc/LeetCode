class Solution {
  public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
    final int allMask = (1 << 12) - 1;
    int maxPoint = 0;
    int maxMask = 0;

    for (int mask = 0; mask < allMask; ++mask) {
      Pair<Boolean, Integer> pair = getShotableAndPoint(mask, numArrows, aliceArrows);
      final boolean shotable = pair.getKey();
      final int point = pair.getValue();
      if (shotable && point > maxPoint) {
        maxPoint = point;
        maxMask = mask;
      }
    }

    return getBobsArrows(maxMask, numArrows, aliceArrows);
  }

  private Pair<Boolean, Integer> getShotableAndPoint(int mask, int leftArrows, int[] aliceArrows) {
    int point = 0;
    for (int i = 0; i < 12; ++i)
      if ((mask >> i & 1) == 1) {
        leftArrows -= aliceArrows[i] + 1;
        point += i;
      }
    return new Pair<>(leftArrows >= 0, point);
  }

  int[] getBobsArrows(int mask, int leftArrows, int[] aliceArrows) {
    int[] bobsArrows = new int[12];
    for (int i = 0; i < 12; ++i)
      if ((mask >> i & 1) == 1) {
        bobsArrows[i] = aliceArrows[i] + 1;
        leftArrows -= aliceArrows[i] + 1;
      }
    bobsArrows[0] = leftArrows;
    return bobsArrows;
  }
}
