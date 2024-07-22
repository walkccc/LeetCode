class Solution:
  def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
    ans = []

    people.sort(key=lambda x: (-x[0], x[1]))

    for p in people:
      ans.insert(p[1], p)

    return ans
