class TextEditor {
  public void addText(String text) {
    sb.append(text);
  }

  public int deleteText(int k) {
    final int numDeleted = Math.min(k, sb.length());
    for (int i = 0; i < numDeleted; ++i)
      sb.deleteCharAt(sb.length() - 1);
    return numDeleted;
  }

  public String cursorLeft(int k) {
    while (!sb.isEmpty() && k-- > 0) {
      stack.push(sb.charAt(sb.length() - 1));
      sb.deleteCharAt(sb.length() - 1);
    }
    return getString();
  }

  public String cursorRight(int k) {
    while (!stack.isEmpty() && k-- > 0)
      sb.append(stack.pop());
    return getString();
  }

  private String getString() {
    if (sb.length() < 10)
      return sb.toString();
    return sb.substring(sb.length() - 10).toString();
  }

  private StringBuilder sb = new StringBuilder();
  private Deque<Character> stack = new ArrayDeque<>();
}
