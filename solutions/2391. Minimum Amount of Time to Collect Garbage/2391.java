class Solution {
  public int garbageCollection(String[] garbage, int[] travel) {
    int[] prefix = new int[travel.length];
    prefix[0] = travel[0];
    for (int i = 1; i < prefix.length; ++i)
      prefix[i] += prefix[i - 1] + travel[i];
    final int timeM = getTime(garbage, prefix, 'M');
    final int timeP = getTime(garbage, prefix, 'P');
    final int timeG = getTime(garbage, prefix, 'G');
    return timeM + timeP + timeG;
  }

  private int getTime(String[] garbage, int[] prefix, char c) {
    int characterCount = 0;
    int lastIndex = -1;
    for (int i = 0; i < garbage.length; ++i) {
      final String s = garbage[i];
      if (s.chars().anyMatch(g -> g == c))
        lastIndex = i;
      characterCount += (int) s.chars().filter(g -> g == c).count();
    }
    return characterCount + (lastIndex <= 0 ? 0 : prefix[lastIndex - 1]);
  }
}
