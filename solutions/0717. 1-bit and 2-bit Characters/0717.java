class Solution {
  public boolean isOneBitCharacter(int[] bits) {
    final int n = bits.length;

    int i = 0;
    while (i < n - 1)
      if (bits[i] == 0)
        i += 1;
      else
        i += 2;

    return i == n - 1;
  }
}
