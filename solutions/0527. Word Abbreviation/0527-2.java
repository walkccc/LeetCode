class IndexedWord {
  public String word;
  public int index;
  public IndexedWord(final String word, int index) {
    this.word = word;
    this.index = index;
  }
}

class Solution {
  public List<String> wordsAbbreviation(List<String> words) {
    String[] ans = new String[words.size()];
    Map<String, List<IndexedWord>> abbrevToIndexedWords = new HashMap<>();

    for (int i = 0; i < words.size(); ++i) {
      final String abbrev = getAbbrev(words.get(i), 0);
      abbrevToIndexedWords.putIfAbsent(abbrev, new ArrayList<>());
      abbrevToIndexedWords.get(abbrev).add(new IndexedWord(words.get(i), i));
    }

    for (List<IndexedWord> indexedWords : abbrevToIndexedWords.values()) {
      Collections.sort(indexedWords, (a, b) -> a.word.compareTo(b.word));
      int[] lcp = new int[indexedWords.size()];
      for (int i = 1; i < indexedWords.size(); ++i) {
        final int k = longestCommonPrefix(indexedWords.get(i - 1).word, indexedWords.get(i).word);
        lcp[i - 1] = Math.max(lcp[i - 1], k);
        lcp[i] = k;
      }
      for (int i = 0; i < indexedWords.size(); ++i)
        ans[indexedWords.get(i).index] = getAbbrev(indexedWords.get(i).word, lcp[i]);
    }

    return Arrays.asList(ans);
  }

  private String getAbbrev(final String s, int prefixIndex) {
    final int n = s.length();
    final int num = n - (prefixIndex + 1) - 1;
    final int numLength = num < 10 ? 1 : num < 100 ? 2 : 3;
    final int abbrevLength = (prefixIndex + 1) + numLength + 1;
    if (abbrevLength >= n)
      return s;
    return s.substring(0, prefixIndex + 1) + num + s.charAt(n - 1);
  }

  private int longestCommonPrefix(final String s1, final String s2) {
    int i = 0;
    while (i < s1.length() && i < s2.length() && s1.charAt(i) == s2.charAt(i))
      ++i;
    return i;
  }
}
