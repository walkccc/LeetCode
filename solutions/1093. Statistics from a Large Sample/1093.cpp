class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    double minimum = 0;
    double maximum = 0;
    double mean = 0;
    double leftMedian = 0;
    double rightMedian = 0;
    double mode = -1;
    int numCount = accumulate(begin(count), end(count), 0);
    int newNumCount = 0;
    int maxCount = 0;

    for (int i = 0; i < count.size(); ++i)
      if (count[i] > 0) {
        minimum = i;
        break;
      }

    for (int i = count.size() - 1; i >= 0; --i)
      if (count[i] > 0) {
        maximum = i;
        break;
      }

    for (int i = 0; i < count.size(); ++i)
      mean += (i * count[i]) / (double)numCount;

    for (int i = 0; i < count.size(); ++i) {
      newNumCount += count[i];
      if (newNumCount >= numCount / 2) {
        leftMedian = i;
        break;
      }
    }

    newNumCount = 0;

    for (int i = count.size() - 1; i >= 0; --i) {
      newNumCount += count[i];
      if (newNumCount >= numCount / 2) {
        rightMedian = i;
        break;
      }
    }

    for (int i = 0; i < count.size(); ++i)
      if (count[i] > maxCount) {
        maxCount = count[i];
        mode = i;
      }

    return {minimum, maximum, mean, (leftMedian + rightMedian) / 2.0, mode};
  }
};
