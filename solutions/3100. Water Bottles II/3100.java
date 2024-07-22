class Solution {
  public int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = numBottles;

    while (numBottles >= numExchange) {
      numBottles = (numBottles - numExchange + 1);
      ++numExchange;
      ++ans;
    }

    return ans;
  }
}
