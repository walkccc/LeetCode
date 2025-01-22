class Solution {
  public int closetTarget(String[] words, String target, int startIndex) {
    final int n = words.length;

    for (int i = 0; i < n; ++i) {
      if (words[(startIndex + i + n) % n].equals(target))
        return i;
      if (words[(startIndex - i + n) % n].equals(target))
        return i;
    }

    return -1;
  }
}
