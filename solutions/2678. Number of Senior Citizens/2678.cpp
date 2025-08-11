class Solution {
 public:
  int countSeniors(vector<string>& details) {
    return ranges::count_if(details, [](const string& detail) {
      return stoi(detail.substr(11, 2)) > 60;
    });
  }
};
