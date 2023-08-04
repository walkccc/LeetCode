class Solution {
 public:
  int countSeniors(vector<string>& details) {
    return count_if(details.begin(), details.end(), [](const string& detail) {
      return stoi(detail.substr(11, 2)) > 60;
    });
  }
};
