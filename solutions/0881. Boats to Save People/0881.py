class Solution:
  def numRescueBoats(self, people: List[int], limit: int) -> int:
    ans = 0
    i = 0
    j = len(people) - 1

    people.sort()

    while i <= j:
      remain = limit - people[j]
      j -= 1
      if people[i] <= remain:
        i += 1
      ans += 1

    return ans
