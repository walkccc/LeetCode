class Solution:
  def numberOfWeakCharacters(self, properties: list[list[int]]) -> int:
    ans = 0
    maxDefense = 0

    # Sort properties by `attack` in descending order, then by `defense` in
    # ascending order.
    for _, defense in sorted(properties, key=lambda x: (-x[0], x[1])):
      if defense < maxDefense:
        ans += 1
      maxDefense = max(maxDefense, defense)

    return ans
