class Solution {
  public long countVowels(String word) {
    final long n = word.length();

    long ans = 0;

    for (int i = 0; i < n; ++i)
      if ("aeiou".indexOf(word.charAt(i)) != -1)
        ans += (i + 1) * (n - i);

    return ans;
  }
}
