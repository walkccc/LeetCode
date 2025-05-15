class Solution {
  public String smallestSubsequence(String s, int k, char letter, int repetition) {
    StringBuilder sb = new StringBuilder();
    Deque<Character> stack = new ArrayDeque<>();
    int required = repetition;
    int nLetters = (int) s.chars().filter(c -> c == letter).count();

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      while (!stack.isEmpty() && stack.peek() > c && stack.size() + s.length() - i - 1 >= k &&
             (stack.peek() != letter || nLetters > required))
        if (stack.pop() == letter)
          ++required;
      if (stack.size() < k)
        if (c == letter) {
          stack.push(c);
          --required;
        } else if (k - stack.size() > required) {
          stack.push(c);
        }
      if (c == letter)
        --nLetters;
    }

    for (final char c : stack)
      sb.append(c);

    return sb.reverse().toString();
  }
}
