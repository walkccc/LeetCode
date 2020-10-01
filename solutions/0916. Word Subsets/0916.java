class Solution {
  public List<String> wordSubsets(String[] A, String[] B) {
    List<String> ans = new ArrayList<>();
    int[] countB = new int[26];

    for (final String b : B) {
      int[] temp = counter(b);
      for (int i = 0; i < 26; ++i)
        countB[i] = Math.max(countB[i], temp[i]);
    }

    for (final String a : A)
      if (isUniversal(counter(a), countB))
        ans.add(a);

    return ans;
  }

  private int[] counter(final String s) {
    int[] count = new int[26];
    for (char c : s.toCharArray())
      ++count[c - 'a'];
    return count;
  }

  private boolean isUniversal(int[] countA, int[] countB) {
    for (int i = 0; i < 26; ++i)
      if (countA[i] < countB[i])
        return false;
    return true;
  }
}