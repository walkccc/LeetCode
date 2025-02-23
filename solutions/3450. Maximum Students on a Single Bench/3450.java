class Solution {
  public int maxStudentsOnBench(int[][] students) {
    final int kMax = 100;
    int ans = 0;
    Set<Integer>[] benchToStudents = new Set[kMax + 1];

    for (int i = 0; i <= kMax; ++i)
      benchToStudents[i] = new HashSet<>();

    for (int[] student : students) {
      final int studentId = student[0];
      final int benchId = student[1];
      benchToStudents[benchId].add(studentId);
    }

    for (Set<Integer> studentsOnBench : benchToStudents)
      ans = Math.max(ans, studentsOnBench.size());

    return ans;
  }
}
