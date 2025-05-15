class Complex {
  public double real;
  public double imag;

  public Complex(double real, double imag) {
    this.real = real;
    this.imag = imag;
  }

  public Complex add(Complex other) {
    return new Complex(this.real + other.real, this.imag + other.imag);
  }

  public Complex subtract(Complex other) {
    return new Complex(this.real - other.real, this.imag - other.imag);
  }

  public Complex multiply(Complex other) {
    return new Complex(this.real * other.real - this.imag * other.imag,
                       this.real * other.imag + this.imag * other.real);
  }

  public Complex divide(double scalar) {
    return new Complex(this.real / scalar, this.imag / scalar);
  }
}

class Solution {
  public long[] multiply(int[] poly1, int[] poly2) {
    final int n1 = poly1.length;
    final int n2 = poly2.length;
    final int n = n1 + n2 - 1;
    final int sz = 1 << bitLength(n - 1);

    // Prepare input arrays for FFT.
    Complex[] a = new Complex[sz];
    Complex[] b = new Complex[sz];

    // Initialize arrays with Complex objects
    for (int i = 0; i < sz; ++i) {
      a[i] = new Complex(0, 0);
      b[i] = new Complex(0, 0);
    }

    // Copy polynomial coefficients to complex arrays.
    for (int i = 0; i < n1; ++i)
      a[i] = new Complex(poly1[i], 0);

    for (int i = 0; i < n2; ++i)
      b[i] = new Complex(poly2[i], 0);

    // Transform polynomials to frequency domain.
    fft(a, false);
    fft(b, false);

    // Multiply in frequency domain.
    for (int i = 0; i < sz; ++i)
      a[i] = a[i].multiply(b[i]);

    // Transform back to coefficient domain.
    fft(a, true);

    // Extract real parts as polynomial coefficients.
    long[] ans = new long[n];

    for (int i = 0; i < n; ++i)
      ans[i] = Math.round(a[i].real);

    return ans;
  }

  private void fft(Complex[] a, boolean inverse) {
    final int n = a.length;

    // Bit-reversal permutation.
    for (int i = 1, j = 0; i < n; ++i) {
      int bit = n >> 1;
      for (; (j & bit) != 0; bit >>= 1)
        j ^= bit;
      j ^= bit;
      if (i < j)
        swap(a, i, j);
    }

    // FFT computation.
    for (int len = 2; len <= n; len *= 2) {
      final double angle = 2 * Math.PI / len * (inverse ? -1 : 1);
      final Complex wLen = new Complex(Math.cos(angle), Math.sin(angle));
      for (int i = 0; i < n; i += len) {
        Complex w = new Complex(1, 0);
        for (int j = 0; j < len / 2; ++j) {
          final Complex u = a[i + j];
          final Complex v = a[i + j + len / 2].multiply(w);
          a[i + j] = u.add(v);
          a[i + j + len / 2] = u.subtract(v);
          w = w.multiply(wLen);
        }
      }
    }

    // Normalize if inverse transform.
    if (inverse)
      for (int i = 0; i < n; ++i)
        a[i] = a[i].divide(n);
  }

  private void swap(Complex[] a, int i, int j) {
    Complex temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }

  private int bitLength(int n) {
    return Integer.SIZE - Integer.numberOfLeadingZeros(n);
  }
}
