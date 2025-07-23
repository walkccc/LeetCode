class Solution {
  public int findSubstringInWraproundString(String s) {
    int maxLength = 1;
    // count[i] := the number of substrings ending in ('a' + i)
    int[] count = new int[26];

    for (int i = 0; i < s.length(); ++i) {
      if (i > 0 && (s.charAt(i) - s.charAt(i - 1) == 1 || s.charAt(i - 1) - s.charAt(i) == 25))
        ++maxLength;
      else
        maxLength = 1;
      final int index = s.charAt(i) - 'a';
      count[index] = Math.max(count[index], maxLength);
    }

    return Arrays.stream(count).sum();
  }
}
