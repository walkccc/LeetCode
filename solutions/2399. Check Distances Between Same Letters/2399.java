class Solution {
  public boolean checkDistances(String s, int[] distance) {
    int[] firstSeenIndex = new int[26];
    Arrays.fill(firstSeenIndex, -1);

    for (int i = 0; i < s.length(); ++i) {
      final int j = s.charAt(i) - 'a';
      final int prevIndex = firstSeenIndex[j];
      if (prevIndex != -1 && i - prevIndex - 1 != distance[j])
        return false;
      firstSeenIndex[j] = i;
    }

    return true;
  }
}
