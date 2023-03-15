class StringIterator {
  public StringIterator(String compressedString) {
    int i = 0; // compressedString's index
    while (i < compressedString.length()) {
      final char c = compressedString.charAt(i++);
      int num = 0;
      while (i < compressedString.length() && Character.isDigit(compressedString.charAt(i)))
        num = num * 10 + (compressedString.charAt(i++) - '0');
      q.offer(new Pair<>(c, num));
    }
  }

  public char next() {
    if (!hasNext())
      return ' ';

    final char c = q.peek().getKey();
    final int num = q.poll().getValue();
    if (num > 1)
      q.addFirst(new Pair<>(c, num - 1));
    return c;
  }

  public boolean hasNext() {
    return !q.isEmpty();
  }

  // (currentChar, num)
  private LinkedList<Pair<Character, Integer>> q = new LinkedList<>();
}
