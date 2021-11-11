class Solution {
  public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
    List<Pair<Integer, Integer>> sortedIndexes = new ArrayList<>();

    for (int i = 0; i < indexes.length; ++i)
      sortedIndexes.add(new Pair<>(indexes[i], i));

    Collections.sort(sortedIndexes, (a, b) -> b.getKey() - a.getKey());

    for (var sortedIndex : sortedIndexes) {
      final int index = sortedIndex.getKey();
      final int i = sortedIndex.getValue();
      final String source = sources[i];
      final String target = targets[i];
      if (S.substring(index, index + source.length()).equals(source))
        S = S.substring(0, index) + target + S.substring(index + source.length());
    }

    return S;
  }
}
