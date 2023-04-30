class Solution {
 public:
  string categorizeBox(int length, int width, int height, int mass) {
    const bool isBulky =
        length >= 10000 || width >= 10000 || height >= 10000 ||
        static_cast<long>(length) * width * height >= 1'000'000'000;
    const bool isHeavy = mass >= 100;
    if (isBulky && isHeavy)
      return "Both";
    if (isBulky)
      return "Bulky";
    if (isHeavy)
      return "Heavy";
    return "Neither";
  }
};
