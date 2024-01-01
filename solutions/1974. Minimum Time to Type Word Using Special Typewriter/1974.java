class Solution {
  public int minTimeToType(String word) {
    int moves = 0;
    char letter = 'a';

    for (final char c : word.toCharArray()) {
      final int diff = Math.abs(c - letter);
      moves += Math.min(diff, 26 - diff);
      letter = c;
    }

    return moves + word.length();
  }
}
