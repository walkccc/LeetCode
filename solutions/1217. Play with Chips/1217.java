class Solution {
  public int minCostToMoveChips(int[] chips) {
    int[] count = new int[2];

    for (int chip : chips)
      ++count[chip % 2];

    return Math.min(count[0], count[1]);
  }
}
