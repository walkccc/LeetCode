class Solution {
  public String countOfAtoms(String s) {
    StringBuilder sb = new StringBuilder();
    Map<String, Integer> count = parse(s);

    for (final String elem : count.keySet())
      sb.append(elem + (count.get(elem) == 1 ? "" : String.valueOf(count.get(elem))));

    return sb.toString();
  }

  private int i = 0;

  private Map<String, Integer> parse(String s) {
    Map<String, Integer> count = new TreeMap<>();

    while (i < s.length())
      if (s.charAt(i) == '(') {
        ++i; // skip '('
        for (Map.Entry<String, Integer> entry : parse(s).entrySet()) {
          final String elem = entry.getKey();
          final int freq = entry.getValue();
          count.put(elem, count.getOrDefault(elem, 0) + freq);
        }
      } else if (s.charAt(i) == ')') {
        ++i; // skip ')'
        final int num = getNum(s);
        for (final String elem : count.keySet()) {
          final int freq = count.get(elem);
          count.put(elem, freq * num);
        }
        return count; // return back to previous scope
      } else {
        final String elem = getElem(s);
        final int num = getNum(s);
        count.put(elem, count.getOrDefault(elem, 0) + num);
      }

    return count;
  }

  private String getElem(final String s) {
    final int elemStart = i++; // s[elemStart] is uppercased
    while (i < s.length() && Character.isLowerCase(s.charAt(i)))
      ++i;
    return s.substring(elemStart, i);
  }

  private int getNum(final String s) {
    final int numStart = i;
    while (i < s.length() && Character.isDigit(s.charAt(i)))
      ++i;
    final String numString = s.substring(numStart, i);
    return numString.isEmpty() ? 1 : Integer.parseInt(numString);
  }
}
