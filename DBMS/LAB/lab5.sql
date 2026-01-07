CREATE DATABASE anu;
USE anu
CREATE TABLE EMPLOYEE (
    eid INT(3) PRIMARY KEY,
    ename VARCHAR(50),
    eaddress VARCHAR(50),
    eage INT(3),
    esalary INT(8)
);
INSERT INTO EMPLOYEE VALUES
(1, 'Prabin Shrestha', 'Ghatekullo', 26, 35000),
(2, 'Prashant Yadav', 'Lalitpur', 31, 11000),
(3, 'Rose Pradhan', 'Dillibazar', 25, 20000),
(4, 'Krish Kandel', 'Kirtipur', 27, 38000),
(5, 'Kamal Sharma', 'Sundhara',  26, 10000),
(6, 'Surekshya Shrestha', 'Kantipur',27, 40000),
(7, 'Ranju KC', 'Sankhamul', 23, 30000),
(8, 'Anita Neupane', 'Bhaktapur', 24, 91000),
(9, 'Anshu Hada', 'Kathmandu',  22, 100000),
(10, 'Kamana Hamal', 'Ason',  26, 20000);

SELECT * FROM EMPLOYEE
WHERE ename LIKE 'P%';
SELECT * FROM EMPLOYEE
WHERE ename LIKE '%e';
SELECT * FROM EMPLOYEE
WHERE ename LIKE 'K%' AND ename LIKE '%l';
SELECT * FROM EMPLOYEE
WHERE eaddress LIKE '%pur%';

SELECT * FROM EMPLOYEE
WHERE ename LIKE 'K%' AND ename LIKE '%l' AND eaddress = 'Kirtipur';
