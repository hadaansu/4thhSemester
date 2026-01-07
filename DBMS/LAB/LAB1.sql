CREATE DATABASE anshu
USE anshu

CREATE TABLE student(
	s_id INT(3) PRIMARY KEY,
	f_name VARCHAR(15),
	l_name VARCHAR(15),
	address VARCHAR(15),
	grade INT(2),
	phone_no NUMERIC);
INSERT INTO student VALUES
(1,"Barsha","Pandey","lamjung",12,9877421454),
(2,"Kamana","Shrestha","Chitwan",10,9849887765),
(3,"Krisma","Maharjan","Jarankhu",9,9849128542),
(4,"Manila","Aryal","Syanja",11,984944877),
(5,"Shrisa","Tuladhar","Sorakhutee",8,9854663672);
SELECT * FROM student;