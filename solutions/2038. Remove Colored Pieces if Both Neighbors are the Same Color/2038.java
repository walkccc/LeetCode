class Solution {
  public boolean winnerOfGame(String colors) {
    int countAAA = 0;
    int countBBB = 0;

    for (int i = 1; i + 1 < colors.length(); ++i)
      if (colors.charAt(i - 1) == colors.charAt(i) && colors.charAt(i) == colors.charAt(i + 1))
        if (colors.charAt(i) == 'A')
          ++countAAA;
        else
          ++countBBB;

    return countAAA > countBBB;
  }
}
