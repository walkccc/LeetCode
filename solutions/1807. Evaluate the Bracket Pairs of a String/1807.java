class Solution {
  public String evaluate(String s, List<List<String>> knowledge) {
    StringBuilder sb = new StringBuilder();
    Map<String, String> map = new HashMap<>();

    for (List<String> list : knowledge)
      map.put("(" + list.get(0) + ")", list.get(1));

    for (int i = 0; i < s.length(); ++i) {
      final char c = s.charAt(i);
      if (c == '(') {
        final int j = s.indexOf(')', i);
        sb.append(map.getOrDefault(s.substring(i, j + 1), "?"));
        i = j;
      } else {
        sb.append(c);
      }
    }

    return sb.toString();
  }
}
