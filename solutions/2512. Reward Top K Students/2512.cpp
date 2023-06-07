class Solution {
 public:
  vector<int> topStudents(vector<string>& positive_feedback,
                          vector<string>& negative_feedback,
                          vector<string>& report, vector<int>& student_id,
                          int k) {
    vector<int> ans;
    vector<pair<int, int>> scoreAndIds;
    unordered_set<string> pos{begin(positive_feedback), end(positive_feedback)};
    unordered_set<string> neg{begin(negative_feedback), end(negative_feedback)};

    for (int i = 0; i < report.size(); ++i) {
      int score = 0;
      istringstream iss(report[i]);
      for (string word; iss >> word;) {
        if (pos.count(word))
          score += 3;
        if (neg.count(word))
          score -= 1;
      }
      scoreAndIds.emplace_back(-score, student_id[i]);
    }

    partial_sort(begin(scoreAndIds), begin(scoreAndIds) + k, end(scoreAndIds));
    transform(
        begin(scoreAndIds), begin(scoreAndIds) + k, back_inserter(ans),
        [](const pair<int, int>& scoreAndId) { return scoreAndId.second; });
    return ans;
  }
};
