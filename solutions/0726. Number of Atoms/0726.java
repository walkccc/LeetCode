class Solution {
  public String countOfAtoms(String formula) {
    String ans = "";
    i = 0;
    Map<String, Integer> count = parse(formula);

    for (String elem : count.keySet())
      ans += elem + (count.get(elem) == 1 ? "" : String.valueOf(count.get(elem)));

    return ans;
  }

  private int i;

  private Map<String, Integer> parse(String formula) {
    final int n = formula.length();
    Map<String, Integer> count = new TreeMap<>();

    while (i < n) {
      if (formula.charAt(i) == '(') {
        ++i;
        for (Map.Entry<String, Integer> entry : parse(formula).entrySet()) {
          String elem = entry.getKey();
          Integer freq = entry.getValue();
          count.put(elem, count.getOrDefault(elem, 0) + freq);
        }
      } else if (formula.charAt(i) == ')') {
        int numStart = ++i;
        while (i < n && Character.isDigit(formula.charAt(i)))
          ++i;
        int factor = Integer.valueOf(formula.substring(numStart, i));
        for (String elem : count.keySet())
          count.put(elem, count.get(elem) * factor);
        return count;
      } else if (Character.isUpperCase(formula.charAt(i))) {
        int elemStart = i++;
        while (i < n && Character.isLowerCase(formula.charAt(i)))
          ++i;
        String elem = formula.substring(elemStart, i);
        int numStart = i;
        while (i < n && Character.isDigit(formula.charAt(i)))
          ++i;
        String numString = formula.substring(numStart, i);
        Integer num = numString.isEmpty() ? 1 : Integer.valueOf(numString);
        count.put(elem, count.getOrDefault(elem, 0) + num);
      }
    }

    return count;
  }
}