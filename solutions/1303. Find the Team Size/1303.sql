SELECT
  employee_id,
  COUNT(*) OVER(PARTITION BY team_id) AS team_size
FROM Employee;
