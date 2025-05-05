class Solution {
  public List<String> removeAnagrams(String[] words) {
    List<String> ans = new ArrayList<>();

    for (int i = 0; i < words.length;) {
      int j = i + 1;
      while (j < words.length && isAnagram(words[i], words[j]))
        ++j;
      ans.add(words[i]);
      i = j;
    }

    return ans;
  }

  private boolean isAnagram(final String a, final String b) {
    if (a.length() != b.length())
      return false;

    int[] count = new int[26];

    for (final char c : a.toCharArray())
      ++count[c - 'a'];

    for (final char c : b.toCharArray())
      --count[c - 'a'];

    return Arrays.stream(count).allMatch(c -> c == 0);
  }
}
