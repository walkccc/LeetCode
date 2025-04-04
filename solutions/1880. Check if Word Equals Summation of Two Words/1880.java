class Solution {
  public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
    final int first = getNumber(firstWord);
    final int second = getNumber(secondWord);
    final int target = getNumber(targetWord);
    return first + second == target;
  }

  private int getNumber(String word) {
    int num = 0;
    for (final char c : word.toCharArray())
      num = num * 10 + (c - 'a');
    return num;
  }
}
