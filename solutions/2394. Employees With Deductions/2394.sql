SELECT Employees.employee_id
FROM Employees
LEFT JOIN Logs
  USING (employee_id)
GROUP BY Employees.employee_id, Employees.needed_hours
HAVING (
    SUM(
      CEIL(
        IFNULL(
          TIMESTAMPDIFF(SECOND, LOGS.in_time, LOGS.out_time),
          0
        ) / 60
      )
    ) / 60
  ) < Employees.needed_hours;
