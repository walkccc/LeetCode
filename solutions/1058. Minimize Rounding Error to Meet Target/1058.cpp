class Solution {
 public:
  string minimizeError(vector<string>& prices, int target) {
    // A[i] := (costCeil - costFloor, costCeil, costFloor)
    // The lower the costCeil - costFloor is, the cheaper to ceil it.
    vector<tuple<double, double, double>> A;
    int sumFloored = 0;
    int sumCeiled = 0;

    for (const string& p : prices) {
      const double price = stod(p);
      const int floored = floor(price);
      const int ceiled = ceil(price);
      sumFloored += floored;
      sumCeiled += ceiled;
      const double costFloor = price - static_cast<double>(floored);
      const double costCeil = static_cast<double>(ceiled) - price;
      A.emplace_back(costCeil - costFloor, costCeil, costFloor);
    }

    if (sumFloored > target || sumCeiled < target)
      return "-1";

    ranges::sort(A);

    double sumError = 0.0;
    const int nCeiled = target - sumFloored;
    for (int i = 0; i < nCeiled; ++i)
      sumError += get<1>(A[i]);
    for (int i = nCeiled; i < A.size(); ++i)
      sumError += get<2>(A[i]);

    stringstream ss;
    ss << std::fixed << std::setprecision(3) << sumError;
    return ss.str();
  }
};
