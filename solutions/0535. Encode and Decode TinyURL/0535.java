public class Codec {
  public String encode(String longUrl) {
    while (!urlToCode.containsKey(longUrl)) {
      String code = "";
      for (int i = 0; i < 6; ++i)
        code += alphabets.charAt(rand.nextInt(alphabets.length()));
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

  private final String alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  private Map<String, String> urlToCode = new HashMap<>();
  private Map<String, String> codeToUrl = new HashMap<>();
  private Random rand = new Random();
}