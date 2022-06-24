class Solution {
  public boolean validUtf8(int[] data) {
    int leftToCheck = 0;

    for (final int d : data)
      if (leftToCheck == 0) {
        if ((d >> 3) == 0b11110)
          leftToCheck = 3;
        else if ((d >> 4) == 0b1110)
          leftToCheck = 2;
        else if ((d >> 5) == 0b110)
          leftToCheck = 1;
        else if ((d >> 7) == 0b0)
          leftToCheck = 0;
        else
          return false;
      } else {
        if ((d >> 6) != 0b10)
          return false;
        --leftToCheck;
      }

    return leftToCheck == 0;
  }
}
