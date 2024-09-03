class Solution {
  public boolean areAlmostEqual(String s1, String s2) {
    List<Integer> diffIndices = new ArrayList<>();

    for (int i = 0; i < s1.length(); ++i)
      if (s1.charAt(i) != s2.charAt(i))
        diffIndices.add(i);

    return diffIndices.isEmpty() ||
        (diffIndices.size() == 2 &&
         s1.charAt(diffIndices.get(0)) == s2.charAt(diffIndices.get(1)) &&
         s1.charAt(diffIndices.get(1)) == s2.charAt(diffIndices.get(0)));
  }
}
