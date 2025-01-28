WITH
  RankedScores AS (
    SELECT
      student_id,
      subject,
      score,
      exam_date,
      RANK() OVER (PARTITION BY student_id, subject ORDER BY exam_date) AS rn_asc,
      RANK() OVER (PARTITION BY student_id, subject ORDER BY exam_date DESC) AS rn_desc
    FROM Scores
  ),
  FirstLastScores AS (
    SELECT
      student_id,
      subject,
      MIN(CASE WHEN rn_asc = 1 THEN score END) AS first_score,
      MAX(CASE WHEN rn_desc = 1 THEN score END) AS latest_score
    FROM RankedScores GROUP BY 1, 2
    HAVING COUNT(*) > 1
  )
SELECT student_id, subject, first_score, latest_score
FROM FirstLastScores
WHERE latest_score > first_score;
