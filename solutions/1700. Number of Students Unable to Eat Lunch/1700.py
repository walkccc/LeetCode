class Solution:
  def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
    count = collections.Counter(students)

    for i, sandwich in enumerate(sandwiches):
      if count[sandwich] == 0:
        return len(sandwiches) - i
      count[sandwich] -= 1

    return 0
