class Solution {
 public:
  int maxStudentsOnBench(vector<vector<int>>& students) {
    constexpr int kMax = 100;
    size_t ans = 0;
    vector<unordered_set<int>> benchToStudents(kMax + 1);

    for (const vector<int>& student : students) {
      const int studentId = student[0];
      const int benchId = student[1];
      benchToStudents[benchId].insert(studentId);
    }

    for (const unordered_set<int>& students : benchToStudents)
      ans = max(ans, students.size());

    return ans;
  }
};
