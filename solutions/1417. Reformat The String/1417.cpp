class Solution {
 public:
  string reformat(string s) {
    vector<char> A;
    vector<char> B;

    for (const char c : s)
      isalpha(c) ? A.push_back(c) : B.push_back(c);

    if (A.size() < B.size())
      swap(A, B);
    if (A.size() - B.size() > 1)
      return "";

    string ans;

    for (int i = 0; i < B.size(); ++i)
      ans += string{A[i], B[i]};

    if (A.size() > B.size())
      ans += A.back();
    return ans;
  }
};
