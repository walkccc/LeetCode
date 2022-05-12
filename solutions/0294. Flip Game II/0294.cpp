class Solution {
 public:
  bool canWin(string currentState) {
    if (memo.count(currentState))
      return memo[currentState];

    // if any of currentState[i:i + 2] == "++" and your friend can't win after
    // changing currentState[i:i + 2] to "--" (or "-"), then you can win
    for (int i = 0; i + 1 < currentState.length(); ++i)
      if (currentState[i] == '+' && currentState[i + 1] == '+' &&
          !canWin(currentState.substr(0, i) + '-' + currentState.substr(i + 2)))
        return memo[currentState] = true;

    return memo[currentState] = false;
  }

 private:
  unordered_map<string, bool> memo;
};
