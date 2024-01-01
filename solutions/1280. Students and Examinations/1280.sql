SELECT
  Students.student_id,
  Students.student_name,
  Subjects.subject_name,
  COUNT(Examinations.student_id) AS attended_exams
FROM Students
CROSS JOIN Subjects
LEFT JOIN Examinations
  ON (
    Students.student_id = Examinations.student_id
    AND Subjects.subject_name = Examinations.subject_name)
GROUP BY 1, 2, 3
ORDER BY Students.student_id, Subjects.subject_name;
