class Solution {
  public int findSubstringInWraproundString(String p) {
    int maxLength = 1;
    int[] count = new int[26]; // substrings end at i

    for (int i = 0; i < p.length(); ++i) {
      if (i > 0 && (p.charAt(i) - p.charAt(i - 1) == 1 || p.charAt(i - 1) - p.charAt(i) == 25))
        ++maxLength;
      else
        maxLength = 1;
      final int index = p.charAt(i) - 'a';
      count[index] = Math.max(count[index], maxLength);
    }

    return Arrays.stream(count).sum();
  }
}
