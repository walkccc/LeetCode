class Solution:
  def phonePrefix(self, numbers: list[str]) -> bool:
    return not any(b.startswith(a)
                   for a, b in itertools.pairwise(sorted(numbers)))
