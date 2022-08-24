class Poly {
  public Poly add(Poly o) {
    for (final String term : o.terms.keySet())
      terms.merge(term, o.terms.get(term), Integer::sum);
    return this;
  }

  public Poly minus(Poly o) {
    for (final String term : o.terms.keySet())
      terms.merge(term, -o.terms.get(term), Integer::sum);
    return this;
  }

  public Poly mult(Poly o) {
    Poly res = new Poly();
    for (final String a : terms.keySet())
      for (final String b : o.terms.keySet())
        res.terms.merge(merge(a, b), terms.get(a) * o.terms.get(b), Integer::sum);
    return res;
  }

  // @Override
  // public String toString() {
  //   StringBuilder sb = new StringBuilder();
  //   sb.append("{");
  //   for (final String term : terms.keySet())
  //     sb.append(term).append(": ").append(terms.get(term)).append(", ");
  //   sb.append("}");
  //   return sb.toString();
  // }

  public List<String> toList() {
    List<String> res = new ArrayList<>();
    List<String> keys = new ArrayList<>(terms.keySet());
    Collections.sort(keys, new Comparator<String>() {
      @Override
      public int compare(final String a, final String b) {
        // smallest degree is the last
        if (a.equals("1"))
          return 1;
        if (b.equals("1"))
          return -1;
        String[] as = a.split("\\*");
        String[] bs = b.split("\\*");
        // largest degree is the first
        // breaking ties by lexicographic order
        return as.length == bs.length ? a.compareTo(b) : bs.length - as.length;
      }
    });
    for (final String key : keys)
      if (terms.get(key) != 0)
        res.add(concat(key));
    return res;
  }

  public Poly() {}
  public Poly(final String term, int coef) {
    terms.put(term, coef);
  }

  private Map<String, Integer> terms = new HashMap<>();

  // e.g. merge("a*b", "a*c") -> "a*a*b*c"
  private static String merge(final String a, final String b) {
    if (a.equals("1"))
      return b;
    if (b.equals("1"))
      return a;
    StringBuilder sb = new StringBuilder();
    String[] A = a.split("\\*");
    String[] B = b.split("\\*");
    int i = 0; // A's index
    int j = 0; // B's index
    while (i < A.length && j < B.length)
      if (A[i].compareTo(B[j]) < 0)
        sb.append("*").append(A[i++]);
      else
        sb.append("*").append(B[j++]);
    while (i < A.length)
      sb.append("*").append(A[i++]);
    while (j < B.length)
      sb.append("*").append(B[j++]);
    return sb.substring(1).toString();
  }

  private String concat(final String term) {
    if (term.equals("1"))
      return String.valueOf(terms.get(term));
    return new StringBuilder().append(terms.get(term)).append('*').append(term).toString();
  }
}

class Solution {
  public List<String> basicCalculatorIV(String expression, String[] evalvars, int[] evalints) {
    List<String> tokens = getTokens(expression);
    Map<String, Integer> evalMap = new HashMap<>();

    for (int i = 0; i < evalvars.length; ++i)
      evalMap.put(evalvars[i], evalints[i]);

    for (int i = 0; i < tokens.size(); ++i)
      if (evalMap.containsKey(tokens.get(i)))
        tokens.set(i, String.valueOf(evalMap.get(tokens.get(i))));

    List<String> postfix = infixToPostfix(tokens);
    return evaluate(postfix).toList();
  }

  private List<String> getTokens(final String s) {
    List<String> tokens = new ArrayList<>();
    int i = 0;
    for (int j = 0; j < s.length(); ++j)
      if (s.charAt(j) == ' ') {
        if (i < j)
          tokens.add(s.substring(i, j));
        i = j + 1;
      } else if ("()+-*".contains(s.substring(j, j + 1))) {
        if (i < j)
          tokens.add(s.substring(i, j));
        tokens.add(s.substring(j, j + 1));
        i = j + 1;
      }
    if (i < s.length())
      tokens.add(s.substring(i));
    return tokens;
  }

  private boolean isOperator(final String token) {
    return token.equals("+") || token.equals("-") || token.equals("*");
  }

  private boolean precedes(final String prevOp, final String currOp) {
    if (prevOp.equals("("))
      return false;
    return prevOp.equals("*") || currOp.equals("+") || currOp.equals("-");
  }

  private List<String> infixToPostfix(List<String> tokens) {
    List<String> postfix = new ArrayList<>();
    Deque<String> ops = new ArrayDeque<>();

    for (final String token : tokens)
      if (token.equals("(")) {
        ops.push(token);
      } else if (token.equals(")")) {
        while (!ops.peek().equals("("))
          postfix.add(ops.pop());
        ops.pop();
      } else if (isOperator(token)) {
        while (!ops.isEmpty() && precedes(ops.peek(), token))
          postfix.add(ops.pop());
        ops.push(token);
      } else { // isOperand(token)
        postfix.add(token);
      }

    while (!ops.isEmpty())
      postfix.add(ops.pop());

    return postfix;
  }

  private Poly evaluate(List<String> postfix) {
    LinkedList<Poly> polys = new LinkedList<>();
    for (final String token : postfix)
      if (isOperator(token)) {
        final Poly b = polys.removeLast();
        final Poly a = polys.removeLast();
        if (token.equals("+"))
          polys.add(a.add(b));
        else if (token.equals("-"))
          polys.add(a.minus(b));
        else // token == "*"
          polys.add(a.mult(b));
      } else if (token.charAt(0) == '-' || token.chars().allMatch(c -> Character.isDigit(c))) {
        polys.add(new Poly("1", Integer.parseInt(token)));
      } else {
        polys.add(new Poly(token, 1));
      }
    return polys.getFirst();
  }
}
