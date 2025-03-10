class Solution {
  public int mostExpensiveItem(int primeOne, int primeTwo) {
    // https://en.wikipedia.org/wiki/Coin_problem
    return primeOne * primeTwo - primeOne - primeTwo;
  }
}
