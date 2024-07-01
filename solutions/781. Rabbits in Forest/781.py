class Solution:
  def numRabbits(self, answers: List[int]) -> int:
    ans = 0
    count = collections.Counter()

    for answer in answers:
      if count[answer] % (answer + 1) == 0:
        ans += answer + 1
      count[answer] += 1

    return ans
