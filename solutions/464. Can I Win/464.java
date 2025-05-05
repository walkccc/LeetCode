class Solution {
  public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0)
      return true;

    final int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (sum < desiredTotal)
      return false;

    Map<Integer, Boolean> mem = new HashMap<>();
    return canIWin(desiredTotal, 0, maxChoosableInteger, mem);
  }

  // Returns true if the first player can we, where `used` represents the used
  // numbers.
  private boolean canIWin(int total, int used, int maxChoosableInteger, Map<Integer, Boolean> mem) {
    if (total <= 0)
      return false;
    if (mem.containsKey(used))
      return mem.get(used);

    for (int i = 1; i <= maxChoosableInteger; ++i) {
      if ((used >> i & 1) == 1) // Integer i is used.
        continue;
      if (!canIWin(total - i, used | 1 << i, maxChoosableInteger, mem))
        return true;
    }

    mem.put(used, false);
    return false;
  }
}
