class Solution:
  def countVowelPermutation(self, n: int) -> int:
    kMod = 1_000_000_007
    dp = {'a': 1, 'e': 1, 'i': 1, 'o': 1, 'u': 1}

    for _ in range(n - 1):
      newDp = {'a': dp['e'] + dp['i'] + dp['u'],
               'e': dp['a'] + dp['i'],
               'i': dp['e'] + dp['o'],
               'o': dp['i'],
               'u': dp['i'] + dp['o']}
      dp = newDp

    return sum(dp.values()) % kMod
