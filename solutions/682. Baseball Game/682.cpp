class Solution {
 public:
  int calPoints(vector<string>& operations) {
    vector<int> scores;

    for (const string& operation : operations)
      if (operation == "+")
        scores.push_back(scores.back() + scores[scores.size() - 2]);
      else if (operation == "D")
        scores.push_back(scores.back() * 2);
      else if (operation == "C")
        scores.pop_back();
      else
        scores.push_back(stoi(operation));

    return accumulate(scores.begin(), scores.end(), 0);
  }
};
