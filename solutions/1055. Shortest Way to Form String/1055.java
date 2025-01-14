class Solution {
  public int shortestWay(String source, String target) {
    int ans = 0;

    for (int i = 0; i < target.length();) {
      final int prevIndex = i;
      for (int j = 0; j < source.length(); ++j)
        if (i < target.length() && source.charAt(j) == target.charAt(i))
          ++i;
      // All chars in source didn't match target[i].
      if (i == prevIndex)
        return -1;
      ++ans;
    }

    return ans;
  }
}
