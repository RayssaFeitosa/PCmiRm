#include "Target.h"
	Target::Target(std::string refseq, int id){
		this->refseq = refseq;
		this->id = id;
	}
	//esse eh o id no vector de bitset
	int Target::get_id() const {
		return this->id;
	}
	std::string Target::get_refseq(){
		return this->refseq;
	}
	void Target::set_id(int id){
            this->id = id;
	}
	void Target::set_refseq(std::string refseq){
		this->refseq = refseq;
	}
