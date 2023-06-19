class Solution {
 public:
  string decodeMessage(string key, string message) {
    vector<char> keyToActual(128);
    keyToActual[' '] = ' ';
    char currChar = 'a';

    for (const char c : key)
      keyToActual[c] = keyToActual[c] ?: currChar++;

    transform(message.cbegin(), message.cend(), message.begin(),
              [&](char c) { return keyToActual[c]; });

    return message;
  }
};
