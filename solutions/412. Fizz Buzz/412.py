class Solution:
  def fizzBuzz(self, n: int) -> list[str]:
    d = {3: 'Fizz', 5: 'Buzz'}
    return [''.join([d[k] for k in d if i % k == 0]) or str(i) for i in range(1, n + 1)]
