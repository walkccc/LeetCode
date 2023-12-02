class Solution {
  public String robotWithString(String s) {
    StringBuilder sb = new StringBuilder();
    int[] count = new int[26];
    Deque<Character> stack = new ArrayDeque<>();

    for (final char c : s.toCharArray())
      ++count[c - 'a'];

    for (final char c : s.toCharArray()) {
      stack.push(c);
      --count[c - 'a'];
      final char minChar = getMinChar(count);
      while (!stack.isEmpty() && stack.peek() <= minChar)
        sb.append(stack.pop());
    }

    while (!stack.isEmpty())
      sb.append(stack.pop());

    return sb.toString();
  }

  private char getMinChar(int[] count) {
    for (int i = 0; i < 26; ++i)
      if (count[i] > 0)
        return (char) ('a' + i);
    return 'a';
  }
}
