class Solution:
  def dividePlayers(self, skill: list[int]) -> int:
    n = len(skill)
    teamSkill = sum(skill) // (n // 2)
    ans = 0
    count = collections.Counter(skill)

    for s, freq in count.items():
      requiredSkill = teamSkill - s
      if count[requiredSkill] != freq:
        return -1
      ans += s * requiredSkill * freq

    return ans // 2
