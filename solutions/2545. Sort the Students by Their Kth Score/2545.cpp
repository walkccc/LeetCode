class Solution {
 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    sort(score.begin(), score.end(),
         [k](const vector<int>& a, const vector<int>& b) {
      return a[k] > b[k];
    });
    return score;
  }
};
