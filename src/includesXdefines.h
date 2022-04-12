#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <random>
#include <ctime>
#include <Windows.h>
#include <nlohmann/json.hpp>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <json/writer.h>



class student 
{
private:
	std::string name, surname, email, password;
	int user_token = 0;
public:
	student(int user_token, std::string name, std::string surname, std::string email, std::string password) {
		name = this->name, surname = this->surname, email = this->email, password = this->password,
			user_token = this->user_token;
	}

public:
	void token_generation();

public:
	student() {}
	std::string getName() { return name; }
	std::string getSurname() { return surname; }
	std::string getEmail() { return email; }
	std::string getPassword() { return password; }
	int getUser_token() { return user_token; }
	void setName(std::string& student_name) { name = student_name; }
	void setSurame(std::string& student_surname) { surname = student_surname; }
	void setEmail(std::string& student_email) { email = student_email; }
	void setPassword(std::string& student_password) { password = student_password; }
	void SetToken(int& token) { user_token = token; }
	
};

class lessons : student {

private:
	std::string lesson, day;
	int start_time_hour, start_time_minute, end_time_hour, end_time_minute;
public:
	lessons(std::string lesson, std::string day, int start_time_hour, int start_time_minute, int end_time_hour, int end_time_minute) {
		lesson = this->lesson, day = this->day, start_time_hour = this->start_time_hour,
			end_time_hour = this->end_time_hour, start_time_minute = this->start_time_minute, end_time_minute = this->end_time_minute;
	}
public:
	std::pair<int, int> getSystemtime();

public:
	lessons() {}
	std::string getLesson() { return lesson; }
	std::string getDay() { return day; }
	int getStart_time_hour() { return start_time_hour; }
	int getStart_time_minute() { return start_time_minute; }
	int getend_time_hour() { return end_time_hour; }
	int getend_time_minute() { return end_time_minute; }
	void setLesson(std::string& input_lesson) { lesson = input_lesson; }
	void setDay(std::string& day_of_week) { day = day_of_week; }
	void setLesson_start_time_hour(int& inputStart_time_hour) { start_time_hour = inputStart_time_hour; }
	void setLesson_start_time_minute(int& inputStart_time_minute) { start_time_minute = inputStart_time_minute; }
	void setLesson_end_time_hour(int& inputEnd_time_hour) { end_time_hour = inputEnd_time_hour; }
	void setLesson_end_time_minute(int& inputEnd_time_minute) { end_time_minute = inputEnd_time_minute; }
	rapidjson::Document toJSON(student& st, lessons& ls);
	
};