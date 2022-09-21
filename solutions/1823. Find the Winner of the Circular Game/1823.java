class Solution {
  public int findTheWinner(int n, int k) {
    // true if i-th friend is left
    boolean[] friends = new boolean[n];

    int friendCount = n;
    int fp = n; // friends' pointer

    while (friendCount > 1) {
      for (int i = 0; i < k; ++i, ++fp)
        while (friends[fp % n]) // the friend is not there
          ++fp;                 // point to the next one
      friends[(fp - 1) % n] = true;
      --friendCount;
    }

    for (fp = 0; friends[fp]; ++fp)
      ;
    return fp + 1;
  }
}
