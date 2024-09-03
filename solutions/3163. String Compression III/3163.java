class Solution {
  public String compressedString(String word) {
    final int n = word.length();
    StringBuilder sb = new StringBuilder();

    for (int i = 0, j = 0; i < n; i = j) {
      int count = 0;
      while (j < n && word.charAt(j) == word.charAt(i) && count < 9) {
        ++j;
        ++count;
      }
      sb.append(String.valueOf(count)).append(word.charAt(i));
    }

    return sb.toString();
  }
}
