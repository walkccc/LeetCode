class Solution {
  public String entityParser(String text) {
    Map<String, String> entryToChar =
        Map.of("&quot;", "\"", "&apos;", "'", "&gt;", ">", "&lt;", "<", "&frasl;", "/");

    for (Map.Entry<String, String> entry : entryToChar.entrySet()) {
      final String entity = entry.getKey();
      final String c = entry.getValue();
      text = text.replaceAll(entity, c);
    }

    // Process '&' in last.
    return text.replaceAll("&amp;", "&");
  }
}
