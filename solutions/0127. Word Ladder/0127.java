class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> wordSet = new HashSet<>(wordList);
    if (!wordSet.contains(endWord))
      return 0;

    int ans = 0;
    Queue<String> q = new LinkedList<>();
    q.offer(beginWord);

    while (!q.isEmpty()) {
      ++ans;
      for (int i = q.size(); i > 0; --i) {
        StringBuilder sb = new StringBuilder(q.poll());
        for (int j = 0; j < sb.length(); ++j) {
          final char cache = sb.charAt(j);
          for (char c = 'a'; c <= 'z'; ++c) {
            sb.setCharAt(j, c);
            final String word = sb.toString();
            if (word.equals(endWord))
              return ans + 1;
            if (wordSet.contains(word)) {
              wordSet.remove(word);
              q.offer(word);
            }
          }
          sb.setCharAt(j, cache);
        }
      }
    }

    return 0;
  }
}
