class Solution {
  public boolean canAliceWin(int n) {
    for (int stones = 10; stones >= 0; --stones) {
      if (stones > n)
        return stones % 2 == 1;
      n -= stones;
    }
    throw new IllegalArgumentException();
  }
}
