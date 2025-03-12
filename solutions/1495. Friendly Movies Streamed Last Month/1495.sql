SELECT DISTINCT Content.title
FROM Content
INNER JOIN TVProgram
  USING (content_id)
WHERE
  Content.kids_content = 'Y'
  AND Content.content_type = 'Movies'
  AND DATE_FORMAT(TVProgram.program_date, '%Y-%m') = '2020-06';
