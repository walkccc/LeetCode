class Solution {
  public int minNumberOfFrogs(String croakOfFrogs) {
    final String kCroak = "croak";
    int ans = 0;
    int frogs = 0;
    int[] count = new int[5];

    for (final char c : croakOfFrogs.toCharArray()) {
      ++count[kCroak.indexOf(c)];
      for (int i = 1; i < 5; ++i)
        if (count[i] > count[i - 1])
          return -1;
      if (c == 'c')
        ++frogs;
      else if (c == 'k')
        --frogs;
      ans = Math.max(ans, frogs);
    }

    return frogs == 0 ? ans : -1;
  }
}
