class Solution {
  public int minCostII(int[][] costs) {
    int prevIndex = -1; // the previous minimum index
    int prevMin1 = 0;   // minimum cost so far
    int prevMin2 = 0;   // 2nd minimum cost so far

    for (int[] cost : costs) { // O(n)
      // the painted index s.t. achieve the minimum cost after painting current house
      int index = -1;
      int min1 = Integer.MAX_VALUE;           // the minimum cost after painting current house
      int min2 = Integer.MAX_VALUE;           // the 2nd minimum cost after painting current house
      for (int i = 0; i < cost.length; ++i) { // O(k)
        final int theCost = cost[i] + (i == prevIndex ? prevMin2 : prevMin1);
        if (theCost < min1) {
          index = i;
          min2 = min1;
          min1 = theCost;
        } else if (theCost < min2) { // min1 <= theCost < min2
          min2 = theCost;
        }
      }
      prevIndex = index;
      prevMin1 = min1;
      prevMin2 = min2;
    }

    return prevMin1;
  }
}
