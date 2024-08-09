class IndexedWord {
  public String word;
  public int index;
  public IndexedWord(final String word, int index) {
    this.word = word;
    this.index = index;
  }
}

class TrieNode {
  public TrieNode[] children = new TrieNode[26];
  public int count = 0;
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
      TrieNode root = new TrieNode();
      for (IndexedWord iw : indexedWords)
        insertWord(root, iw.word);
      for (IndexedWord iw : indexedWords) {
        final int index = firstUniqueIndex(root, iw.word);
        ans[iw.index] = getAbbrev(iw.word, index);
      }
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

  private void insertWord(TrieNode root, final String word) {
    TrieNode node = root;
    for (final char c : word.toCharArray()) {
      final int i = c - 'a';
      if (node.children[i] == null)
        node.children[i] = new TrieNode();
      node = node.children[i];
      ++node.count;
    }
  }

  private int firstUniqueIndex(TrieNode root, final String word) {
    TrieNode node = root;
    for (int i = 0; i < word.length(); ++i) {
      node = node.children[word.charAt(i) - 'a'];
      if (node.count == 1)
        return i;
    }
    return word.length();
  }
}
