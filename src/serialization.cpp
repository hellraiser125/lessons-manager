#include"includesXdefines.h"


void to_json(nlohmann::json& j, student& st, lessons& ls) {

	j = nlohmann::json{ {"name", st.getName()}, {"surname", st.getSurname()}, {"email", st.getEmail()}, {"password", st.getPassword()}, {"token", st.getUser_token()},
	{"lesson", ls.getLesson()}, {"day", ls.getDay()}, {"stTime_hour",ls.getStart_time_hour()}, {"stTime_min",ls.getStart_time_minute()},{"endTime_hour",ls.getend_time_hour()},
		{"endTime_min",ls.getend_time_minute()} };
	
}

//void from_json(const nlohmann::json& j, student& st) {
//
//	std::string name, surname, email, password;
//	int token;
//	j.at("name").get_to(name);
//	j.at("surname").get_to(surname);
//	j.at("email").get_to(email);
//	j.at("password").get_to(password);
//	j.at("token").get_to(token);
//	st.setName(name);
//	st.setSurame(surname);
//	st.setEmail(email);
//	st.setPassword(password);
//	st.SetToken(token);
//}


void write_data(nlohmann::json& j) {

	std::ofstream file_id;
	file_id.open("data", std::ios_base::app);
	if (!file_id.is_open()) 
		std::cout << "Open File ERROr!\n"; 
	else {
		file_id << j << "\n";
	}
	file_id.close();
}

void get_data() {

	std::string line;
	std::ifstream file("data");
	if (!file.is_open()) { std::cout << "OpenFile ERROR!\n"; }
	else {
		while (!file.eof()) { getline(file, line); std::cout << line << std::endl; }
	}
	file.close();
}

