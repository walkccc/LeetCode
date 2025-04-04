class Solution:
  def maxStudentsOnBench(self, students: list[list[int]]) -> int:
    benchToStudents = collections.defaultdict(set)
    for studentId, benchId in students:
      benchToStudents[benchId].add(studentId)
    return max(map(len, benchToStudents.values()), default=0)
