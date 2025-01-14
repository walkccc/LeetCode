class Solution:
  def numberOfWeakCharacters(self, properties: list[list[int]]) -> int:
    ans = 0
    maxAttack = max(attack for attack, _ in properties)
    # maxDefenses[i] := the maximum defense for the i-th attack
    maxDefenses = [0] * (maxAttack + 2)

    for attack, defense in properties:
      maxDefenses[attack] = max(maxDefenses[attack], defense)

    for i in range(maxAttack, 0, -1):
      maxDefenses[i] = max(maxDefenses[i], maxDefenses[i + 1])

    for attack, defense in properties:
      if maxDefenses[attack + 1] > defense:
        ans += 1

    return ans
