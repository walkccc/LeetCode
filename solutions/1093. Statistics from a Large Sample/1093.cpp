class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    const int n = accumulate(count.begin(), count.end(), 0);
    const double mode = ranges::max_element(count) - count.begin();
    return {
        getMinimum(count),
        getMaximum(count),
        getMean(count, n),
        (getLeftMedian(count, n) + getRightMedian(count, n)) / 2.0,
        mode,
    };
  }

 private:
  double getMinimum(const vector<int>& count) {
    for (int i = 0; i < count.size(); ++i)
      if (count[i])
        return i;
    return -1;
  }

  double getMaximum(const vector<int>& count) {
    for (int i = count.size() - 1; i >= 0; --i)
      if (count[i])
        return i;
    return -1;
  }

  double getMean(const vector<int>& count, double n) {
    double mean = 0;
    for (long i = 0; i < count.size(); ++i)
      mean += (i * count[i]) / n;
    return mean;
  }

  double getLeftMedian(const vector<int>& count, double n) {
    int numCount = 0;
    for (int i = 0; i < count.size(); ++i) {
      numCount += count[i];
      if (numCount >= n / 2)
        return i;
    }
    return -1;
  }

  double getRightMedian(const vector<int>& count, double n) {
    int numCount = 0;
    for (int i = count.size() - 1; i >= 0; --i) {
      numCount += count[i];
      if (numCount >= n / 2)
        return i;
    }
    return -1;
  }
};
