#include "MiRNA.h"
	MiRNA::MiRNA(std::string name, int id){
		this->name = name;
		this->id = id;
	}
		
	//esse eh o id no vector de bitset
	int MiRNA::get_id() const {
		return this->id;
	}
	const std::string MiRNA::get_name(){
		return this->name;
	}
	void MiRNA::set_id(int id){
		this->id = id;
	}
	void MiRNA::set_name(std::string name){
		this->name = name;
	}

