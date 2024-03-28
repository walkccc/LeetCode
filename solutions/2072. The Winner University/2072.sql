WITH
  NY AS (
    SELECT COUNT(student_id) AS `count`
    FROM NewYork
    WHERE score >= 90
  ),
  CA AS (
    SELECT COUNT(student_id) AS `count`
    FROM California
    WHERE score >= 90
  )
SELECT
  CASE
    WHEN NY.`count` > CA.`count` THEN 'New York University'
    WHEN NY.`count` < CA.`count` THEN 'California University'
    ELSE 'No Winner'
  END AS Winner
FROM NY, CA;
