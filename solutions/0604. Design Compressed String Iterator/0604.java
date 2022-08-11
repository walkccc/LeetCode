class StringIterator {
  public StringIterator(String compressedString) {
    s = compressedString;
  }

  public char next() {
    if (!hasNext())
      return ' ';

    if (num == 0) {
      currentChar = s.charAt(i++);
      while (i < s.length() && Character.isDigit(s.charAt(i)))
        num = num * 10 + (s.charAt(i++) - '0');
    }

    --num;
    return currentChar;
  }

  public boolean hasNext() {
    return i < s.length() || num > 0;
  }

  private final String s;
  private int i = 0;   // s's index
  private int num = 0; // currentChar's count
  private char currentChar = ' ';
}
