class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string encoded;

    for (const string& s : strs)
      encoded += to_string(s.length()) + '/' + s;

    return encoded;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> decoded;

    for (int i = 0; i < s.length();) {
      const int slash = s.find('/', i);
      const int length = stoi(s.substr(i, slash - i));
      i = slash + length + 1;
      decoded.push_back(s.substr(slash + 1, i - slash - 1));
    }

    return decoded;
  }
};
