class Solution:
  def mostExpensiveItem(self, primeOne: int, primeTwo: int) -> int:
    # https://en.wikipedia.org/wiki/Coin_problem
    return primeOne * primeTwo - primeOne - primeTwo
