class Solution {
  public boolean isSolvable(String[] words, String result) {
    rows = words.length + 1;
    for (final String word : words)
      cols = Math.max(cols, word.length());
    cols = Math.max(cols, result.length());
    return dfs(words, result, 0, 0, 0);
  }

  private Map<Character, Integer> letterToDigit = new HashMap<>();
  private boolean[] usedDigit = new boolean[10];
  private int rows = 0;
  private int cols = 0;

  private boolean dfs(String[] words, String result, int row, int col, int sum) {
    if (col == cols)
      return sum == 0;
    if (row == rows)
      return sum % 10 == 0 && dfs(words, result, 0, col + 1, sum / 10);

    String word = row == rows - 1 ? result : words[row];
    if (col >= word.length())
      return dfs(words, result, row + 1, col, sum);

    char letter = word.charAt(word.length() - col - 1);
    int sign = row == rows - 1 ? -1 : 1;

    if (letterToDigit.containsKey(letter) &&
        (letterToDigit.get(letter) > 0 || col < word.length() - 1))
      return dfs(words, result, row + 1, col, sum + sign * letterToDigit.get(letter));

    for (int digit = 0; digit < 10; ++digit)
      if (!usedDigit[digit] && (digit > 0 || col < word.length() - 1)) {
        letterToDigit.put(letter, digit);
        usedDigit[digit] = true;
        if (dfs(words, result, row + 1, col, sum + sign * letterToDigit.get(letter)))
          return true;
        usedDigit[digit] = false;
        letterToDigit.remove(letter);
      }

    return false;
  }
}
