class Solution {
  public String stringShift(String s, int[][] shift) {
    final int n = s.length();
    int move = 0;

    for (int[] pair : shift) {
      final int direction = pair[0];
      final int amount = pair[1];
      if (direction == 0)
        move -= amount;
      else
        move += amount;
    }

    move = ((move % n) + n) % n;
    return s.substring(n - move) + s.substring(0, n - move);
  }
}
