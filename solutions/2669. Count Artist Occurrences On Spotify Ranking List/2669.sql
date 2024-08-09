SELECT
  artist,
  COUNT(id) AS occurrences
FROM Spotify
GROUP BY 1
ORDER BY 2 DESC, 1;
