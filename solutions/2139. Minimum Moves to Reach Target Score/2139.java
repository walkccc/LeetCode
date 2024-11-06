class Solution {
  public int minMoves(int target, int maxDoubles) {
    int steps = 0;

    while (target > 1 && maxDoubles > 0) {
      if (target % 2 == 1) {
        --target;
      } else {
        target /= 2;
        --maxDoubles;
      }
      ++steps;
    }

    return steps + target - 1;
  }
}
