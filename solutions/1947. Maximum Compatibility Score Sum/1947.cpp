class Solution {
 public:
  int maxCompatibilitySum(vector<vector<int>>& students,
                          vector<vector<int>>& mentors) {
    int ans = 0;
    dfs(students, mentors, 0, /*score=*/0, vector<bool>(students.size()), ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& students,
           const vector<vector<int>>& mentors, int i, int scoreSum,
           vector<bool>&& used, int& ans) {
    if (i == students.size()) {
      ans = max(ans, scoreSum);
      return;
    }
    for (int j = 0; j < students.size(); ++j) {
      if (used[j])
        continue;
      used[j] = true;  // The `mentors[j]` is used.
      dfs(students, mentors, i + 1,
          scoreSum + getScore(students[i], mentors[j]), std::move(used), ans);
      used[j] = false;
    }
  }

  int getScore(const vector<int>& student, const vector<int>& mentor) {
    int score = 0;
    for (int i = 0; i < student.size(); ++i)
      if (student[i] == mentor[i])
        ++score;
    return score;
  }
};
