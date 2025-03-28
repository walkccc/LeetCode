class Solution {
 public:
  int generateKey(int num1, int num2, int num3) {
    const string s1 = zfill(num1, 4);
    const string s2 = zfill(num2, 4);
    const string s3 = zfill(num3, 4);
    string ans;

    for (int i = 0; i < 4; ++i)
      ans += min({s1[i], s2[i], s3[i]});

    return stoi(ans);
  }

 private:
  string zfill(int num, int width) {
    ostringstream oss;
    oss.width(width);
    oss.fill('0');
    oss << num;
    return oss.str();
  }
};
