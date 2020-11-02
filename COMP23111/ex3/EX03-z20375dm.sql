/*
SQL Script produced by Daronhil Mauricette
COMP23111
z20375dm
*/
SET ECHO ON;
SPOOL EX03-z20375dm.log;

START /opt/info/courses/COMP23111/drop-University-tables.sql
START /opt/info/courses/COMP23111/create-University-tables.sql
START /opt/info/courses/COMP23111/populate-University-tables.sql

START /opt/info/courses/COMP23111/drop-Accident-tables.sql
START /opt/info/courses/COMP23111/create-Accident-tables.sql
START /opt/info/courses/COMP23111/populate-Accident-tables.sql


--(1)(a)(i)
SELECT DISTINCT student.name, student.ID, takes.course_id
FROM student
INNER JOIN takes
ON student.ID = takes.ID
WHERE takes.course_id LIKE 'CS%';


--(1)(a)(ii)
SELECT DISTINCT student.name, student.ID, takes.year, section.semester
FROM student
INNER JOIN takes
ON student.ID = takes.ID
INNER JOIN section
ON takes.course_id = section.course_id
WHERE (takes.year >= 2009 AND NOT section.semester = 'Spring'); 


--(1)(a)(iii)
SELECT MAX(salary), dept_name AS Department
FROM instructor
GROUP BY dept_name;


--(1)(a)(iv)
SELECT MIN(salary), dept_name AS Department
FROM instructor
WHERE salary = (SELECT MIN(salary) FROM instructor)
GROUP BY dept_name;


--(1)(b)(i)
INSERT INTO course (course_id, title, dept_name, credits)
VALUES ('CS-001', 'Weekly Seminar', 'Comp. Sci.','10');


--(1)(b)(ii)
--INSERT INTO course (course_id, title, dept_name, credits)
--VALUES ('CS-001', 'Monthly Seminar', 'Comp. Sci.', '0');


--(1)(b)(iii)
/*
The error that appearred says that, the user should "check constraint",
followed by the user's name and a "SYS_" code. This error arises when you
attempt to input a variable that is not allowed in a table. In this situaution, 
it is because of the restraint set on the credits, it is not allowed to be zero.
*/


--(1)(b)(iv)

INSERT INTO 
section (course_id, sec_id, semester, year)
VALUES ('CS-001', '1', 'Fall', '2009');

--(1)(b)(v)
/*
This is a query that only executes if the parent table has a matching value, in
this case the parent is the table called "course" and the child is "seciton". If
the user fails to add the correct value to the parent and integrity error will
occur.
*/

--(1)(b)(vi)
INSERT INTO takes(id, course_id, sec_id, semester, 
SELECT id, 'CS-001','1', 'Fall', '2009'
FROM student
WHERE student.dept_name = 'Comp. Sci.'; 

--(1)(b)(vii)
DELETE FROM
SELECT takes.ID, student.name, takes.course_id, student.ID
FROM takes
JOIN student ON takes.ID = student.ID)
WHERE name = 'Zhang';

--(1)(b)(viii)
DELETE FROM 
(SELECT takes.ID, course.title, takes.course_id, course.course_id
FROM takes
JOIN course ON takes.course_id = course.course_id)
WHERE title LIKE '%Database%';

--(1)(b)(ix)
DELETE FROM course WHERE course_id = 'CS-001';

--(1)(b)(x)
/*
The previous statement is allowed to run without error because the "course"
table is set to "delete on NULL", this causes all values linked via the foreign
key to be deleted in the children tables when it is removed in the parent table. 
*/
SPOOL OFF;
