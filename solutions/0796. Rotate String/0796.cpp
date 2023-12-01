class Solution {
 public:
  bool rotateString(string A, string B) {
    return A.length() == B.length() && (A + A).find(B) != string::npos;
  }
};
