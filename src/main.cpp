#include "includesXdefines.h"

void sign_up_process(student& st);
void getlessons_info_process(lessons& ls);
void log_in_process();


int main() {

	student st;
	lessons ls;

	sign_up_process(st);
	getlessons_info_process(ls);
	

	ls.toJSON(st, ls);
	


	return 0;
}