class Solution {
  public boolean validUtf8(int[] data) {
    int followedBytes = 0;

    for (final int d : data)
      if (followedBytes == 0) {
        if ((d >> 3) == 0b11110)
          followedBytes = 3;
        else if ((d >> 4) == 0b1110)
          followedBytes = 2;
        else if ((d >> 5) == 0b110)
          followedBytes = 1;
        else if ((d >> 7) == 0b0)
          followedBytes = 0;
        else
          return false;
      } else {
        if ((d >> 6) != 0b10)
          return false;
        --followedBytes;
      }

    return followedBytes == 0;
  }
}
