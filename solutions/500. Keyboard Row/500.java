class Solution {
  public String[] findWords(String[] words) {
    List<String> ans = new ArrayList<>();
    final int[] rows = {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3,
                        3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};

    for (final String word : words) {
      final String lowerWord = word.toLowerCase();
      final int row = rows[lowerWord.charAt(0) - 'a'];
      final boolean isValid = lowerWord.chars().allMatch(c -> rows[c - 'a'] == row);
      if (isValid)
        ans.add(word);
    }

    return ans.toArray(new String[0]);
  }
}
