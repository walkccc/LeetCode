class Solution {
  public int kSimilarity(String s1, String s2) {
    Queue<String> q = new ArrayDeque<>(List.of(s1));
    Set<String> seen = new HashSet<>(Arrays.asList(s1));

    for (int step = 0; !q.isEmpty(); ++step)
      for (int sz = q.size(); sz > 0; --sz) {
        final String curr = q.poll();
        if (curr.equals(s2))
          return step;
        for (final String child : getChildren(curr, s2)) {
          if (seen.contains(child))
            continue;
          q.offer(child);
          seen.add(child);
        }
      }

    return -1;
  }

  private List<String> getChildren(final String curr, final String target) {
    List<String> children = new ArrayList<>();
    char[] charArray = curr.toCharArray();
    int i = 0; // the first index s.t. curr.charAt(i) != target.charAt(i)
    while (curr.charAt(i) == target.charAt(i))
      ++i;

    for (int j = i + 1; j < charArray.length; ++j)
      if (curr.charAt(j) == target.charAt(i)) {
        swap(charArray, i, j);
        children.add(String.valueOf(charArray));
        swap(charArray, i, j);
      }

    return children;
  }

  private void swap(char[] charArray, int i, int j) {
    final char temp = charArray[i];
    charArray[i] = charArray[j];
    charArray[j] = temp;
  }
}
