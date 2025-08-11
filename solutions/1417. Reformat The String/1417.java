class Solution {
  public String reformat(String s) {
    List<Character> A = new ArrayList<>();
    List<Character> B = new ArrayList<>();

    for (final char c : s.toCharArray())
      if (Character.isAlphabetic(c))
        A.add(c);
      else
        B.add(c);

    if (A.size() < B.size()) {
      List<Character> temp = A;
      A = B;
      B = temp;
    }
    if (A.size() - B.size() > 1)
      return "";

    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < B.size(); ++i) {
      sb.append(A.get(i));
      sb.append(B.get(i));
    }

    if (A.size() > B.size())
      sb.append(A.get(A.size() - 1));
    return sb.toString();
  }
}
