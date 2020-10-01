class Solution {
  public String[] findWords(String[] words) {
    List<String> ans = new ArrayList<>();
    int[] rows = { 2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3 };

    for (final String word : words) {
      String lowerWord = word.toLowerCase();
      int row = rows[lowerWord.charAt(0) - 'a'];
      boolean isValid = true;
      for (int i = 1; i < lowerWord.length(); ++i)
        if (rows[lowerWord.charAt(i) - 'a'] != row) {
          isValid = false;
          break;
        }
      if (isValid)
        ans.add(word);
    }

    return ans.toArray(new String[0]);
  }
}