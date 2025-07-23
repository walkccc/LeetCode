class Solution:
  def maxWeight(self, pizzas: list[int]) -> int:
    eat = len(pizzas) // 4
    odd = math.ceil(eat / 2)
    even = eat - odd
    pizzas.sort(reverse=True)
    return (sum(pizzas[:odd]) +
            sum(pizzas[odd + 1:odd + 1 + even * 2:2]))
