class Solution {
 public:
  vector<long long> multiply(vector<int>& poly1, vector<int>& poly2) {
    const unsigned n1 = poly1.size();
    const unsigned n2 = poly2.size();
    const unsigned n = n1 + n2 - 1;
    const unsigned sz = 1 << std::bit_width(n - 1);

    // Prepare input arrays for FFT.
    vector<complex<double>> a(sz);
    vector<complex<double>> b(sz);

    // Copy polynomial coefficients to complex arrays.
    for (int i = 0; i < n1; ++i)
      a[i] = poly1[i];

    for (int i = 0; i < n2; ++i)
      b[i] = poly2[i];

    // Transform polynomials to frequency domain.
    fft(a, false);
    fft(b, false);

    // Multiply in frequency domain.
    for (int i = 0; i < sz; ++i)
      a[i] *= b[i];

    // Transform back to coefficient domain.
    fft(a, true);

    // Extract real parts as polynomial coefficients.
    vector<long long> ans(n);

    for (int i = 0; i < n; ++i)
      ans[i] = round(a[i].real());

    return ans;
  }

 private:
  // Fast Fourier Transform.
  void fft(vector<complex<double>>& a, bool inverse) {
    const unsigned n = a.size();

    // Bit-reversal permutation.
    for (int i = 1, j = 0; i < n; ++i) {
      int bit = n >> 1;
      for (; j & bit; bit >>= 1)
        j ^= bit;
      j ^= bit;
      if (i < j)
        swap(a[i], a[j]);
    }

    // FFT computation.
    for (int len = 2; len <= n; len *= 2) {
      const double angle = 2 * M_PI / len * (inverse ? -1 : 1);
      const complex<double> w_len(cos(angle), sin(angle));
      for (int i = 0; i < n; i += len) {
        complex<double> w(1);
        for (int j = 0; j < len / 2; ++j) {
          const complex<double> u = a[i + j];
          const complex<double> v = a[i + j + len / 2] * w;
          a[i + j] = u + v;
          a[i + j + len / 2] = u - v;
          w *= w_len;
        }
      }
    }

    // Normalize if inverse transform.
    if (inverse)
      for (complex<double>& x : a)
        x /= n;
  }
};
