WITH
  TotalScores AS (
    SELECT assignment1 + assignment2 + assignment3 AS score
    FROM Scores
  )
SELECT MAX(score) - MIN(score) AS difference_in_score
FROM TotalScores;
