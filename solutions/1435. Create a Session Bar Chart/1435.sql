SELECT '[0-5>' AS bin,
  SUM(duration <= 300) AS total
FROM Sessions
UNION ALL
SELECT '[5-10>' AS bin,
  SUM(
    duration > 300
    AND duration <= 600
  ) AS total
FROM Sessions
UNION ALL
SELECT '[10-15>' AS bin,
  SUM(
    duration > 600
    AND duration <= 900
  ) AS total
FROM Sessions
UNION ALL
SELECT '15 or more' AS bin,
  SUM(duration > 900) AS total
FROM Sessions
