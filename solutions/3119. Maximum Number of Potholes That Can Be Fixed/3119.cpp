class Solution {
 public:
  int maxPotholes(string road, int budget) {
    int ans = 0;

    for (const int length : getSortedPotholeLengths(road)) {
      const int canRepair = max(0, budget - 1);
      if (length > canRepair)
        return ans + canRepair;
      ans += length;
      budget -= length + 1;
    }

    return ans;
  }

 private:
  vector<int> getSortedPotholeLengths(const string& road) {
    vector<int> potholeLengths;
    istringstream iss(road);
    string pothole;

    while (getline(iss, pothole, '.'))
      potholeLengths.push_back(pothole.length());

    ranges::sort(potholeLengths, greater<>());
    return potholeLengths;
  }
};
