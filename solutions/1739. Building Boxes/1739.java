class Solution {
  public int minimumBoxes(int n) {
    int nBoxes = 0;
    int nextTouchings = 0;  // j
    int currLevelBoxes = 0; // 1 + 2 + ... + j

    // find min j s.t. nBoxes = 1 + (1 + 2) + ... + (1 + 2 + ... + j) >= n
    while (nBoxes < n) {
      ++nextTouchings;
      currLevelBoxes += nextTouchings;
      nBoxes += currLevelBoxes;
    }

    // if nBoxes = n, the answer is currLevelBoxes = 1 + 2 + ... + j
    if (nBoxes == n)
      return currLevelBoxes;

    // otherwise we need to remove boxes in current level and rebuild it
    nBoxes -= currLevelBoxes;
    currLevelBoxes -= nextTouchings;
    nextTouchings = 0;

    while (nBoxes < n) {
      ++nextTouchings;
      nBoxes += nextTouchings;
    }

    return currLevelBoxes + nextTouchings;
  }
}
