public class Codec {
  // Encodes a list of strings to a single string.
  public String encode(List<String> strs) {
    StringBuilder encoded = new StringBuilder();

    for (final String s : strs)
      encoded.append(s.length()).append('/').append(s);

    return encoded.toString();
  }

  // Decodes a single string to a list of strings.
  public List<String> decode(String s) {
    List<String> decoded = new ArrayList<>();

    for (int i = 0; i < s.length();) {
      final int slash = s.indexOf('/', i);
      final int length = Integer.parseInt(s.substring(i, slash));
      i = slash + length + 1;
      decoded.add(s.substring(slash + 1, i));
    }

    return decoded;
  }
}
