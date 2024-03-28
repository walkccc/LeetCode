class Solution {
  public int furthestDistanceFromOrigin(String moves) {
    int countL = 0;
    int countR = 0;
    int countUnderline = 0;

    for (final char c : moves.toCharArray())
      if (c == 'L')
        ++countL;
      else if (c == 'R')
        ++countR;
      else // c == '_'
        ++countUnderline;

    return Math.abs(countL - countR) + countUnderline;
  }
}
