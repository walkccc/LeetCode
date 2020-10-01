class Solution {
  public String fractionAddition(String expression) {
    Scanner sc = new Scanner(expression).useDelimiter("/|(?=[+-])");
    int A = 0;
    int B = 1;

    while (sc.hasNext()) {
      int a = sc.nextInt();
      int b = sc.nextInt();
      A = A * b + a * B;
      B *= b;
      int g = gcd(A, B);
      A /= g;
      B /= g;
    }

    return A + "/" + B;
  }

  private int gcd(int a, int b) {
    return a == 0 ? Math.abs(b) : gcd(b % a, a);
  }
}