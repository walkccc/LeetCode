class Solution {
  public boolean isOneBitCharacter(int[] bits) {
    int i = 0;
    while (i < bits.length - 1)
      i += bits[i] + 1;

    return i == bits.length - 1;
  }
}