WITH
  Majors AS (
    SELECT major, COUNT(course_id) AS course_count
    FROM Courses
    GROUP BY 1
  ),
  StudentMetadata AS (
    SELECT
      Students.student_id,
      Students.major,
      SUM(
        Students.major = Courses.major
        AND Enrollments.grade = 'A'
      ) AS major_grade_a_count
    FROM Students
    INNER JOIN Courses
      USING (major)
    INNER JOIN Enrollments
      USING (student_id, course_id)
    GROUP BY 1
  )
SELECT StudentMetadata.student_id
FROM StudentMetadata
INNER JOIN Majors
  ON (
    StudentMetadata.major = Majors.major
    AND StudentMetadata.major_grade_a_count = Majors.course_count)
ORDER BY 1;
