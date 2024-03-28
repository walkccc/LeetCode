class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> wordSet = new HashSet<>(wordList);
    if (!wordSet.contains(endWord))
      return 0;

    int ans = 0;
    Queue<String> q = new ArrayDeque<>(Arrays.asList(beginWord));

    while (!q.isEmpty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        StringBuilder sb = new StringBuilder(q.poll());
        for (int i = 0; i < sb.length(); ++i) {
          final char cache = sb.charAt(i);
          for (char c = 'a'; c <= 'z'; ++c) {
            sb.setCharAt(i, c);
            final String word = sb.toString();
            if (word.equals(endWord))
              return ans + 1;
            if (wordSet.contains(word)) {
              q.offer(word);
              wordSet.remove(word);
            }
          }
          sb.setCharAt(i, cache);
        }
      }
    }

    return 0;
  }
}
