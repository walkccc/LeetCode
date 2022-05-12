class Solution {
  public List<Integer> diffWaysToCompute(String expression) {
    return ways(expression, new HashMap<>());
  }

  private List<Integer> ways(final String s, Map<String, List<Integer>> memo) {
    if (memo.containsKey(s))
      return memo.get(s);

    List<Integer> ans = new ArrayList<>();

    for (int i = 0; i < s.length(); ++i)
      if (!Character.isDigit(s.charAt(i)))
        for (final int a : ways(s.substring(0, i), memo))
          for (final int b : ways(s.substring(i + 1), memo))
            if (s.charAt(i) == '+')
              ans.add(a + b);
            else if (s.charAt(i) == '-')
              ans.add(a - b);
            else
              ans.add(a * b);

    if (ans.isEmpty()) { // single number
      memo.put(s, Arrays.asList(Integer.parseInt(s)));
      return memo.get(s);
    }
    memo.put(s, ans);
    return ans;
  }
}
