class Solution {
 public:
  int minimumBuckets(string street) {
    for (int i = 0; i < street.length(); ++i)
      if (street[i] == 'H') {
        if (i > 0 && street[i - 1] == 'B')
          continue;
        if (i + 1 < street.length() && street[i + 1] == '.')
          // Always prefer place a bucket in (i + 1) because it enhances the
          // possibility to collect the upcoming houses.
          street[i + 1] = 'B';
        else if (i > 0 && street[i - 1] == '.')
          street[i - 1] = 'B';
        else
          return -1;
      }

    return ranges::count(street, 'B');
  }
};
