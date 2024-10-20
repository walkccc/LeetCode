class Solution {
  public List<String> generatePossibleNextMoves(String currentState) {
    List<String> ans = new ArrayList<>();

    for (int i = 0; i + 1 < currentState.length(); ++i)
      if (currentState.charAt(i) == '+' && currentState.charAt(i + 1) == '+') {
        StringBuilder sb = new StringBuilder(currentState);
        sb.setCharAt(i, '-');
        sb.setCharAt(i + 1, '-');
        ans.add(sb.toString());
      }

    return ans;
  }
}
