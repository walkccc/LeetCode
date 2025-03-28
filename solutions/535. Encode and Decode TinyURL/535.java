public class Codec {
  public String encode(String longUrl) {
    while (!urlToCode.containsKey(longUrl)) {
      StringBuilder sb = new StringBuilder();
      for (int i = 0; i < 6; ++i) {
        final char nextChar = alphabets.charAt(rand.nextInt(alphabets.length()));
        sb.append(nextChar);
      }
      final String code = sb.toString();
      if (!codeToUrl.containsKey(code)) {
        codeToUrl.put(code, longUrl);
        urlToCode.put(longUrl, code);
        return "http://tinyurl.com/" + code;
      }
    }

    throw new IllegalArgumentException();
  }

  public String decode(String shortUrl) {
    return codeToUrl.get(shortUrl.substring(19));
  }

  private static final String alphabets =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  private Map<String, String> urlToCode = new HashMap<>();
  private Map<String, String> codeToUrl = new HashMap<>();
  private Random rand = new Random();
}
