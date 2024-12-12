class Solution {
 public:
  vector<int> topStudents(vector<string>& positive_feedback,
                          vector<string>& negative_feedback,
                          vector<string>& report, vector<int>& student_id,
                          int k) {
    vector<int> ans;
    vector<pair<int, int>> scoreAndIds;
    unordered_set<string> pos{positive_feedback.begin(),
                              positive_feedback.end()};
    unordered_set<string> neg{negative_feedback.begin(),
                              negative_feedback.end()};

    for (int i = 0; i < report.size(); ++i) {
      int score = 0;
      istringstream iss(report[i]);
      for (string word; iss >> word;) {
        if (pos.contains(word))
          score += 3;
        if (neg.contains(word))
          score -= 1;
      }
      scoreAndIds.emplace_back(-score, student_id[i]);
    }

    partial_sort(scoreAndIds.begin(), scoreAndIds.begin() + k,
                 scoreAndIds.end());
    transform(
        scoreAndIds.begin(), scoreAndIds.begin() + k, back_inserter(ans),
        [](const pair<int, int>& scoreAndId) { return scoreAndId.second; });
    return ans;
  }
};
