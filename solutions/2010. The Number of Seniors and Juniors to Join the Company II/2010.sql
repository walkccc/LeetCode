WITH
  AccumualtedCandidates AS (
    SELECT
      employee_id,
      experience,
      ROW_NUMBER() OVER(
        PARTITION BY experience
        ORDER BY salary, employee_id
      ) AS candidate_count,
      SUM(salary) OVER(
        PARTITION BY experience
        ORDER BY salary, employee_id
      ) AS accumulated_salary
    FROM Candidates
  ),
  HiredSeniors AS (
    SELECT
      employee_id,
      accumulated_salary
    FROM AccumualtedCandidates
    WHERE
      experience = 'Senior'
      AND accumulated_salary < 70000
  )
SELECT HiredSeniors.employee_id
FROM HiredSeniors
UNION ALL
SELECT Juniors.employee_id
FROM AccumualtedCandidates AS Juniors
WHERE
  experience = 'Junior'
  AND Juniors.accumulated_salary < (
    SELECT 70000 - IFNULL(MAX(accumulated_salary), 0)
    FROM AccumualtedCandidates
    WHERE
      experience = 'Senior'
      AND accumulated_salary < 70000
  );
