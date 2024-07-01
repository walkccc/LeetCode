class Solution {
  public int countQuadruples(String s1, String s2) {
    // To minimize j - a, the length of the substring should be 1. This is
    // because for substrings with a size greater than 1, a will decrease,
    // causing j - a to become larger.
    int ans = 0;
    int diff = Integer.MAX_VALUE; // diff := j - a
    int[] firstJ = new int[26];
    int[] lastA = new int[26];
    Arrays.fill(firstJ, -1);
    Arrays.fill(lastA, -1);

    for (int j = s1.length() - 1; j >= 0; --j)
      firstJ[s1.charAt(j) - 'a'] = j;

    for (int a = 0; a < s2.length(); ++a)
      lastA[s2.charAt(a) - 'a'] = a;

    for (int i = 0; i < 26; ++i) {
      if (firstJ[i] == -1 || lastA[i] == -1)
        continue;
      if (firstJ[i] - lastA[i] < diff) {
        diff = firstJ[i] - lastA[i];
        ans = 0;
      }
      if (firstJ[i] - lastA[i] == diff)
        ++ans;
    }

    return ans;
  }
}
