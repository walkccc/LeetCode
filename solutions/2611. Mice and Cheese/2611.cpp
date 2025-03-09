class Solution {
 public:
  int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
    // diffs[i] := reward1[i] - reward2[i].
    vector<int> diffs;

    for (int i = 0; i < reward1.size(); ++i)
      diffs.push_back(reward1[i] - reward2[i]);

    nth_element(diffs.begin(), diffs.begin() + k, diffs.end(), greater<>());
    return accumulate(reward2.begin(), reward2.end(), 0) +
           accumulate(diffs.begin(), diffs.begin() + k, 0);
  }
};
