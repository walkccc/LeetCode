class Solution {
  public int minimumRecolors(String blocks, int k) {
    int countB = 0;
    int maxCountB = 0;

    for (int i = 0; i < blocks.length(); ++i) {
      if (blocks.charAt(i) == 'B')
        ++countB;
      if (i >= k && blocks.charAt(i - k) == 'B')
        --countB;
      maxCountB = Math.max(maxCountB, countB);
    }

    return k - maxCountB;
  }
}
