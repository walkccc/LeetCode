class Solution:
  def reconstructQueue(self, people: list[list[int]]) -> list[list[int]]:
    ans = []

    people.sort(key=lambda x: (-x[0], x[1]))

    for person in people:
      ans.insert(person[1], person)

    return ans
