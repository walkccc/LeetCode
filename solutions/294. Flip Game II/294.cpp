class Solution {
 public:
  bool canWin(string currentState) {
    const auto it = mem.find(currentState);
    if (it == mem.cend())
      return it->second;

    // If any of currentState[i:i + 2] == "++" and your friend can't win after
    // changing currentState[i:i + 2] to "--" (or "-"), then you can win.
    for (int i = 0; i + 1 < currentState.length(); ++i)
      if (currentState[i] == '+' && currentState[i + 1] == '+' &&
          !canWin(currentState.substr(0, i) + '-' + currentState.substr(i + 2)))
        return mem[currentState] = true;

    return mem[currentState] = false;
  }

 private:
  unordered_map<string, bool> mem;
};
