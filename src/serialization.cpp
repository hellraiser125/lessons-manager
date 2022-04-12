#include"includesXdefines.h"


rapidjson::Document lessons::toJSON(student& st, lessons& ls) {

	rapidjson::Value json_val;
	rapidjson::Document doc;
	auto& allocator = doc.GetAllocator();

	doc.SetObject();

	json_val.SetString(st.getEmail().c_str(), allocator);
	doc.AddMember("email", json_val, allocator);

	json_val.SetString(st.getName().c_str(), allocator);
	doc.AddMember("name", json_val, allocator);

	json_val.SetString(st.getSurname().c_str(), allocator);
	doc.AddMember("surname", json_val, allocator);

	json_val.SetString(st.getPassword().c_str(), allocator);
	doc.AddMember("password", json_val, allocator);

	json_val.SetUint64(st.getUser_token());
	doc.AddMember("user_token", json_val, allocator);

	json_val.SetString(ls.getLesson().c_str(), allocator);
	doc.AddMember("lesson", json_val, allocator);

	json_val.SetString(ls.getDay().c_str(), allocator);
	doc.AddMember("day", json_val, allocator);

	//time start
	json_val.SetUint64(ls.getStart_time_hour());
	doc.AddMember("start_hour", json_val, allocator);

	json_val.SetUint64(ls.getStart_time_minute());
	doc.AddMember("start_min", json_val, allocator);

	//time end
	json_val.SetUint64(ls.getend_time_hour());
	doc.AddMember("end_hour", json_val, allocator);

	json_val.SetUint64(ls.getend_time_minute());
	doc.AddMember("end_min", json_val, allocator);

	typedef rapidjson::GenericStringBuffer<rapidjson::UTF8<>, rapidjson::MemoryPoolAllocator<>> StringBuffer;
	StringBuffer buf (&allocator);
	rapidjson::Writer<StringBuffer> writer (buf);
	doc.Accept(writer);
	std::string json(buf.GetString(), buf.GetSize());

	std::ofstream of("data.json", std::ios_base::app);
	
	if (!of.good()) throw std::runtime_error("Can't write the JSON string to the file!");
	else of << json << "\n";

}


static lessons fromJSON(const rapidjson::Value& doc) {

	if (!doc.IsObject())
		throw std::runtime_error("document should be an object");

	static const char* members[] = { "email", "name", "surname", "password", "user_token", 
		"lesson", "day", "start_hour", "start_min", "end_hour", "end_min"};

	for (size_t i = 0; i < sizeof(members) / sizeof(members[0]); i++)
		if (!doc.HasMember(members[i]))
			throw std::runtime_error("missing fields");

	//get st data
	uint64_t token = doc["user_token"].GetUint64();
	std::string name = doc["name"].GetString();
	std::string surname = doc["surname"].GetString();
	std::string email = doc["email"].GetString();
	std::string password = doc["password"].GetString();

	std::string lesson = doc["lesson"].GetString();
	std::string day = doc["day"].GetString();

	uint64_t start_h = doc["start_hour"].GetUint64();
	uint64_t start_m = doc["start_min"].GetUint64();
	uint64_t end_h = doc["end_hour"].GetUint64();
	uint64_t end_m = doc["end_min"].GetUint64();

}





