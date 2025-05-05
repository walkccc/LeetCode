class Solution {
  public long calculateScore(String s) {
    long ans = 0;
    Deque<Integer>[] indices = new ArrayDeque[26];

    for (int i = 0; i < 26; ++i)
      indices[i] = new ArrayDeque<>();

    for (int i = 0; i < s.length(); ++i) {
      final int index = s.charAt(i) - 'a';
      final int oppositeIndex = 25 - index;
      if (!indices[oppositeIndex].isEmpty())
        ans += i - indices[oppositeIndex].poll();
      else
        indices[index].push(i);
    }

    return ans;
  }
}
