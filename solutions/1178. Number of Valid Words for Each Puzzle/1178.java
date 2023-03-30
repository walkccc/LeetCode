class Solution {
  public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> binaryCount = new HashMap<>();

    for (final String word : words) {
      int mask = 0;
      for (char c : word.toCharArray())
        mask |= 1 << (c - 'a');
      binaryCount.merge(mask, 1, Integer::sum);
    }

    for (final String puzzle : puzzles) {
      int valid = 0;
      final int n = puzzle.length() - 1;
      for (int i = 0; i < (1 << n); ++i) {
        int mask = 1 << puzzle.charAt(0) - 'a';
        for (int j = 0; j < n; ++j)
          if ((i & 1 << j) > 0)
            mask |= 1 << puzzle.charAt(j + 1) - 'a';
        if (binaryCount.containsKey(mask))
          valid += binaryCount.get(mask);
      }
      ans.add(valid);
    }

    return ans;
  }
}
