class Solution {
  public String reorganizeString(String S) {
    final int n = S.length();

    int[] count = new int[26];
    for (char c : S.toCharArray())
      ++count[c - 'a'];

    int maxCount = Arrays.stream(count).max().getAsInt();
    if (maxCount > (n + 1) / 2)
      return "";

    char[] ans = new char[n];

    if (maxCount == (n + 1) / 2)
      for (char c = 'a'; c <= 'z'; ++c)
        if (count[c - 'a'] == maxCount) {
          for (int i = 0; i < n; i += 2)
            ans[i] = c;
          count[c - 'a'] = 0;
          break;
        }

    int i = maxCount == (n + 1) / 2 ? 1 : 0;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c - 'a']-- > 0) {
        ans[i] = c;
        i += 2;
        if (i >= n)
          i = 1;
      }

    return new String(ans);
  }
}