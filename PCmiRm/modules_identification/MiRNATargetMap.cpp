#include <string.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include "MiRNATargetMap.h"

	MiRNATargetMap::MiRNATargetMap (){
		//map = new std::bitset<MAX_GENES>[MAX_MIRS];
		//std::cout << "MAXGEN #" << MAX_GENES << "#" << std::endl;
		//std::cout << "MAXMIRS #" << MAX_MIRS << "#" << std::endl;
		//std::cout << std::flush;
	}

    //MiRNATargetMap::MiRNATargetMap (const MiRNATargetMap& x) : map(x.get_map()), mirs(x.get_miRNAs()), targets(x.get_targets()) {}

    /*MiRNATargetMap& MiRNATargetMap::operator=(const MiRNATargetMap& other){
        this->mirs = other.get_miRNAs();
        this->map = other.get_map();
        this->targets = other.get_targets();
        //std::cout << "Map_mirs #" << mirs << "#" << std::endl;
        //std::cout << "Map_targets #" << targets << "#" << std::endl;
        return *this;
    }

    //returns an array of MAX_MIRS positions, in which each position has a bitset with the MAX_GENES position
	std::bitset<MAX_GENES> * MiRNATargetMap::get_map() const{
		return map;
	}*/

	//returns a pair int/string (id and name)
	MiRNA MiRNATargetMap::get_mir (int id){
        if(id <= mirs.size())
       		return mirs[id];
       	else
       		return *new MiRNA("miR not found", -1);
	}

	//returns a pair int/string (id and refseq)
	Target MiRNATargetMap::get_target (int id){
        if(id <= targets.size())
        	return targets[id];
        else
        	return *new Target("target not found", -1);
	}

	//returns the array with all miRNAs
	std::vector<MiRNA> MiRNATargetMap::get_miRNAs () const{
		return mirs;
	}

	std::vector<Target> MiRNATargetMap::get_targets () const{
        return targets;
    }

	//add a miRNA
	void MiRNATargetMap::add_mir (std::string name, int id){
        mirs.push_back(*new MiRNA(name, id));
	//void MiRNATargetMap::add_mir (std::string mir_name, int id){
		//mirs.push_back(*new MiRNA(mir_name, id));
	}

	//add a target gene
	void MiRNATargetMap::add_target (std::string refseq, int id){
		targets.push_back(*new Target(refseq, id));
		//std::cout << "mitarMap_addintGEN1 #" << refseq << "#" << std::endl;
	}

	//add an interaction - insert an 1 in the bitset at the position of the id-Target overlapping the position of the id-mir 
	void MiRNATargetMap::add_interaction (std::string mir_name, std::string refseq){
        //std::ofstream f;
        //std::cout << "mitarMap_addintGEN2 #" << refseq << "#" << std::endl;
        int id_mir = -1, id_target = -1;
        std::vector<MiRNA>::iterator itM;
        std::vector<Target>::iterator itT;
        //std::cout << "mitarMap_addintGEN3 #" << refseq << "#" << std::endl;
        //std::cout << "mitarMap_addintMIR #" << mir_name << "#" << std::endl;

        for(itT = targets.begin(); itT!=targets.end(); itT++){
      		if(itT->get_refseq()==refseq){
                id_target = itT->get_id();
                break;
            }
        }

        for(itM = mirs.begin(); itM!=mirs.end(); itM++){
			if(itM->get_name()==mir_name){
                id_mir = itM->get_id();
                break;

            }
        }

        if(id_mir == -1 || id_target == -1){
            if(id_target == -1)
                std::cout << "target not found! " << refseq << " ";
            if(id_mir == -1)
                std::cout << "miRNA not found! " << mir_name;
            std::cout << std::endl;
            return;
        }

        add_interaction(id_mir, id_target);
    }

    void MiRNATargetMap::add_interaction (int id_mir, int id_target){
    	//if(!map[id_mir][(MAX_GENES-1) - id_target])
          	map[id_mir].set((MAX_GENES-1) - id_target, true);
    }

	/*returns a array with the mirna_id target genes 
	/*allocates an array with the number of target genes (which is obtained using the count() method from the bitset)
	/*look for the target gene in the class target array. ((max_genes-1)-1 because the bitset stores it
	/*the backwards bit
	*/
	std::vector<Target> MiRNATargetMap::get_targets_of_a_miRNA(int mirna_id){
		int i;
		int last = 0;
		std::vector<Target> aux;
		for (i = 0; i < MAX_GENES; i++){
			if(map[mirna_id][i] == 1){
				aux.push_back(targets[(MAX_GENES-1)-i]);
                    last = last + 1;

			}
			//break the loop if the miRNA have no targets
			if(last > map[mirna_id].count())
				break;
		}
		return aux;
	}
