class Solution {
  public boolean isValid(String code) {
    if (code.charAt(0) != '<' || code.charAt(code.length() - 1) != '>')
      return false;

    Deque<String> stack = new ArrayDeque<>();

    for (int i = 0; i < code.length(); ++i) {
      int closeIndex = 0;
      if (stack.isEmpty() && containsTag)
        return false;
      if (code.charAt(i) == '<') {
        // inside a tag, so we can check if it's a cdata
        if (!stack.isEmpty() && code.charAt(i + 1) == '!') {
          closeIndex = code.indexOf("]]>", i + 2);
          if (closeIndex < 0 || !isValidCdata(code.substring(i + 2, closeIndex)))
            return false;
        } else if (code.charAt(i + 1) == '/') { // end tag
          closeIndex = code.indexOf('>', i + 2);
          if (closeIndex < 0 || !isValidTagName(stack, code.substring(i + 2, closeIndex), true))
            return false;
        } else { // start tag
          closeIndex = code.indexOf('>', i + 1);
          if (closeIndex < 0 || !isValidTagName(stack, code.substring(i + 1, closeIndex), false))
            return false;
        }
        i = closeIndex;
      }
    }

    return stack.isEmpty() && containsTag;
  }

  private boolean containsTag = false;

  private boolean isValidCdata(final String s) {
    return s.indexOf("[CDATA[") == 0;
  }

  private boolean isValidTagName(Deque<String> stack, String tagName, boolean isEndTag) {
    if (tagName.isEmpty() || tagName.length() > 9)
      return false;

    for (final char c : tagName.toCharArray())
      if (!Character.isUpperCase(c))
        return false;

    if (isEndTag)
      return !stack.isEmpty() && stack.pop().equals(tagName);

    containsTag = true;
    stack.push(tagName);
    return true;
  }
}
