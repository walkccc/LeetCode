SELECT ABS(
    (
      SELECT MAX(salary) AS salary
      FROM Salaries
      WHERE department = 'Engineering'
    ) - (
      SELECT MAX(salary) AS salary
      FROM Salaries
      WHERE department = 'Marketing'
    )
  ) AS salary_difference;
