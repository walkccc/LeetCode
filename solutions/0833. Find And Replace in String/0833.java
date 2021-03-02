class Solution {
  public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
    List<int[]> sortedIndexes = new ArrayList<>();

    for (int i = 0; i < indexes.length; ++i)
      sortedIndexes.add(new int[] {indexes[i], i});

    Collections.sort(sortedIndexes, Comparator.comparing(i -> - i[0]));

    for (int[] sortedIndex : sortedIndexes) {
      final int index = sortedIndex[0];
      final int i = sortedIndex[1];
      final String source = sources[i];
      final String target = targets[i];
      if (S.substring(index, index + source.length()).equals(source))
        S = S.substring(0, index) + target + S.substring(index + source.length());
    }

    return S;
  }
}
