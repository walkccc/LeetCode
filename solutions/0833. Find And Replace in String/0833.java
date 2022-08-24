class Solution {
  public String findReplaceString(String s, int[] indices, String[] sources, String[] targets) {
    List<Pair<Integer, Integer>> sortedIndices = new ArrayList<>();

    for (int i = 0; i < indices.length; ++i)
      sortedIndices.add(new Pair<>(indices[i], i));

    Collections.sort(sortedIndices, (a, b) -> b.getKey() - a.getKey());

    for (Pair<Integer, Integer> sortedIndex : sortedIndices) {
      final int index = sortedIndex.getKey();
      final int i = sortedIndex.getValue();
      final String source = sources[i];
      final String target = targets[i];
      if (s.substring(index, index + source.length()).equals(source))
        s = s.substring(0, index) + target + s.substring(index + source.length());
    }

    return s;
  }
}
