#include"includesXdefines.h"


void sign_up_process(student& st) {
	
	std::string student_name, student_surname, student_email, student_password;
	std::cout << "Enter your name : ";
	std::cin >> student_name;
	std::cout << "Enter your surname : ";
	std::cin >> student_surname;
	std::cout << "Enter your email : ";
	std::cin >> student_email;
	std::cout << "Enter your password : ";
	std::cin >> student_password;
	st.setName(student_name);
	st.setSurame(student_surname);
	st.setEmail(student_email);
	st.setPassword(student_password);
	st.token_generation();
}

void getlessons_info_process(lessons& ls) {

	std::string input_lesson, day_of_week;
	int lesson_count, inputStart_time_hour, inputStart_time_minute, inputEnd_time_hour, inputEnd_time_minute;


	std::cout << "What day do you want to fill/change : ";
	std::cin >> day_of_week;
	ls.setDay(day_of_week);

	std::cout << "How many lessons do you have today : ";
	std::cin >> lesson_count;
	do {
		std::cout << "name of lesson : ";
		std::cin >> input_lesson;
		ls.setLesson(input_lesson);
		std::cout << "Start time hour,minute : ";
		std::cin >> inputStart_time_hour >> inputStart_time_minute;
		ls.setLesson_start_time_hour(inputStart_time_hour);
		ls.setLesson_start_time_minute(inputStart_time_minute);
		std::cout << "End time hour,minute : ";
		std::cin >> inputEnd_time_hour >> inputEnd_time_minute;
		ls.setLesson_end_time_hour(inputEnd_time_hour);
		ls.setLesson_end_time_minute(inputEnd_time_minute);
		lesson_count -= 1;
	} while (lesson_count != 0);
}









 

