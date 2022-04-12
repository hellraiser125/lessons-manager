#include "includesXdefines.h"

void sign_up_process(student& st);
void getlessons_info_process(lessons& ls);
void to_json(nlohmann::json& j, student& st, lessons& ls);
//void from_json(const nlohmann::json& j, student& st);
void write_data(nlohmann::json& j);
void get_data();


int main() {

	student st;
	lessons ls;

	sign_up_process(st);
	getlessons_info_process(ls);
	
	nlohmann::json j;
	
	to_json(j, st, ls);
	write_data(j);
	get_data();


	return 0;
}