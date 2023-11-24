SELECT
  gender,
  day,
  SUM(score_points) OVER(
    PARTITION BY gender
    ORDER BY day
  ) AS total
FROM Scores
ORDER BY 1, 2;
