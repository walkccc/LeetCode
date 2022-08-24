class Solution {
  public String minimizeError(String[] prices, int target) {
    // A[i] := (costCeil - costFloor, costCeil, costFloor)
    // the lower the costCeil - costFloor, the cheaper to ceil it
    List<double[]> A = new ArrayList<>();
    int sumFloored = 0;
    int sumCeiled = 0;

    for (final String p : prices) {
      final double price = Double.parseDouble(p);
      final int floored = (int) Math.floor(price);
      final int ceiled = (int) Math.ceil(price);
      sumFloored += floored;
      sumCeiled += ceiled;
      final double costFloor = price - (double) floored;
      final double costCeil = (double) ceiled - price;
      A.add(new double[] {costCeil - costFloor, costCeil, costFloor});
    }

    if (sumFloored > target || sumCeiled < target)
      return "-1";

    Collections.sort(A, new Comparator<double[]>() {
      @Override
      public int compare(double[] a, double[] b) {
        return Double.compare(a[0], b[0]);
      }
    });

    double sumError = 0.0;
    final int nCeiled = target - sumFloored;
    for (int i = 0; i < nCeiled; ++i)
      sumError += A.get(i)[1];
    for (int i = nCeiled; i < A.size(); ++i)
      sumError += A.get(i)[2];

    return String.format("%.3f", sumError);
  }
}
