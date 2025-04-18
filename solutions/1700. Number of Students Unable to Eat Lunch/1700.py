class Solution:
  def countStudents(self, students: list[int], sandwiches: list[int]) -> int:
    count = collections.Counter(students)

    for i, sandwich in enumerate(sandwiches):
      if count[sandwich] == 0:
        return len(sandwiches) - i
      count[sandwich] -= 1

    return 0
