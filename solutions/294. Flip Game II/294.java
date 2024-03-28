class Solution {
  public boolean canWin(String currentState) {
    if (mem.containsKey(currentState))
      mem.get(currentState);

    // If any of currentState[i:i + 2] == "++" and your friend can't win after
    // changing currentState[i:i + 2] to "--" (or "-"), then you can win.
    for (int i = 0; i + 1 < currentState.length(); ++i)
      if (currentState.charAt(i) == '+' && currentState.charAt(i + 1) == '+' &&
          !canWin(currentState.substring(0, i) + "-" + currentState.substring(i + 2))) {
        mem.put(currentState, true);
        return true;
      }

    mem.put(currentState, false);
    return false;
  }

  private Map<String, Boolean> mem = new HashMap<>();
}
