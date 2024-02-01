class Solution {
  public boolean nimGame(int[] piles) {
    return Arrays.stream(piles).reduce((a, b) -> a ^ b).getAsInt() > 0;
  }
}
