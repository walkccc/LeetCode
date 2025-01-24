class Solution {
  public String fractionAddition(String expression) {
    Scanner sc = new Scanner(expression).useDelimiter("/|(?=[+-])");
    int A = 0;
    int B = 1;

    // Init: A / B = 0 / 1
    // A / B + a / b = (Ab + aB) / Bb
    // So, in each round, set A = Ab + aB, B = Bb.
    while (sc.hasNext()) {
      final int a = sc.nextInt();
      final int b = sc.nextInt();
      A = A * b + a * B;
      B *= b;
      final int g = gcd(A, B);
      A /= g;
      B /= g;
    }

    return A + "/" + B;
  }

  private int gcd(int a, int b) {
    return a == 0 ? Math.abs(b) : gcd(b % a, a);
  }
}
