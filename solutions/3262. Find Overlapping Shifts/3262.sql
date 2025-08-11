SELECT
  Shift1.employee_id,
  COUNT(*) AS overlapping_shifts
FROM EmployeeShifts AS Shift1
INNER JOIN EmployeeShifts AS Shift2
  USING (employee_id)
WHERE
  Shift1.start_time < Shift2.start_time
  AND Shift2.start_time < Shift1.end_time
GROUP BY 1
ORDER BY 1;
