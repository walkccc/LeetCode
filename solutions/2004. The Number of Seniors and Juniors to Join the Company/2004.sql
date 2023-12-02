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
  MaxHiredSeniors AS (
    SELECT
      IFNULL(MAX(candidate_count), 0) AS accepted_candidates,
      IFNULL(MAX(accumulated_salary), 0) AS accumulated_salary
    FROM AccumualtedCandidates
    WHERE
      experience = 'Senior'
      AND accumulated_salary < 70000
  )
SELECT
  'Senior' AS experience,
  accepted_candidates
FROM MaxHiredSeniors
UNION ALL
SELECT
  'Junior' AS experience,
  COUNT(*) AS accepted_candidates
FROM AccumualtedCandidates AS Juniors
WHERE
  experience = 'Junior'
  AND Juniors.accumulated_salary < (
    SELECT 70000 - MaxHiredSeniors.accumulated_salary
    FROM MaxHiredSeniors
  );
