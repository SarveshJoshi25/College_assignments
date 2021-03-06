create database university_27079;
use university_27079;
create table department(department_name varchar(255) primary key, building int not null, budget int not null);
create table student (student_id varchar(255) primary key, student_name varchar(255) not null, total_credits int default 190, department_name varchar(255), foreign key(department_name) references department(department_name));
create table instructor (instructor_id int primary key, instructor_name varchar(255) not null, salary int not null, department_name varchar(255),foreign key(department_name) references department(department_name));
create table course(course_id varchar(255) primary key, course_title varchar(255) not null, credits int not null, department_name varchar(255), foreign key(department_name) references department(department_name));
create table classroom (building int, room_number varchar(255), capacity int default 60, primary key(building, room_number));
create table time_slot(time_slot_id varchar(255) primary key, day varchar(255) not null, start_time time not null, end_time time not null);

create table section(section_id varchar(255), semester varchar(255), year varchar(255), course_id varchar(255), foreign key(course_id) references course(course_id), building int, room_number varchar(255), foreign key(building, room_number) references classroom(building,room_number), time_slot_id varchar(255), foreign key(time_slot_id) references time_slot(time_slot_id), primary key(course_id, section_id, semester, year));
create table teaches(instructor_id int(11), section_id varchar(255), semester varchar(255), year varchar(255), course_id varchar(255), foreign key(instructor_id) references instructor(instructor_id), foreign key(course_id, section_id, semester, year) references section(course_id, section_id, semester, year));
alter table teaches add primary key(instructor_id, course_id, section_id, semester, year);

 create table takes(student_id varchar(255), section_id varchar(255), semester varchar(255), year varchar(255), course_id varchar(255), grade varchar(255), foreign key(student_id) references student(student_id), foreign key(course_id, section_id, semester, year) references section(course_id, section_id, semester, year), primary key(course_id, section_id, semester, year, student_id));

