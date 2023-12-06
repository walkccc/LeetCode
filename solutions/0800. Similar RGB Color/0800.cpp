class Solution {
 public:
  string similarRGB(string color) {
    const vector<string> kShorthands = {"00", "11", "22", "33", "44", "55",
                                        "66", "77", "88", "99", "aa", "bb",
                                        "cc", "dd", "ee", "ff"};
    string ans = "#";

    for (int i = 1; i < color.length(); i += 2) {
      const int currValue = stoi(color.substr(i, 2), 0, 16);
      ans += findClosestShorthand(kShorthands, currValue);
    }

    return ans;
  }

 private:
  static constexpr int maxSimilarity = 255 * 255;

  string findClosestShorthand(const vector<string>& shorthands,
                              int targetValue) {
    string closest = shorthands[0];
    int minSimilarity = maxSimilarity;

    for (const string& shorthand : shorthands) {
      const int shorthandValue = stoi(shorthand, 0, 16);
      const int similarity = pow((targetValue - shorthandValue), 2);
      if (similarity < minSimilarity) {
        closest = shorthand;
        minSimilarity = similarity;
      }
    }

    return closest;
  }
};
