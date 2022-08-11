# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
# class HtmlParser(object):
#   def getUrls(self, url: str) -> List[str]:

class Solution:
  def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
    q = deque([startUrl])
    seen = {startUrl}
    hostname = startUrl.split('/')[2]

    while q:
      currUrl = q.popleft()
      for url in htmlParser.getUrls(currUrl):
        if url in seen:
          continue
        if hostname in url:
          q.append(url)
          seen.add(url)

    return seen
