#include "ReadFiles.h"

ReadFiles::ReadFiles(){}
    //nao consegui trocar td pra string pq ele nao deixa fazer a atribuicao mirs[id] = aux dps. tem alguma coisa a ver com const
    //abre o arquivo, le linha por linha, criando uma stream pra cada pra poder "simular" string tokenizer

void ReadFiles::read_dados_simulados(char * file, std::string type, MiRNATargetMap * map){
	 std::ifstream myfile (file);
     std::string line;
     int cont = 0;

     if(myfile.good()){
     	while(std::getline(myfile, line).good()){
     		if(type == "mir")
     			map->add_mir(line, cont);
     		else
     			map->add_target(line, cont);
     		cont++;
     	}
     }
     else std::cout << "Unable to open file";

}

void ReadFiles::read_mirs(char * file, MiRNATargetMap * map){
        std::ifstream myfile (file);
        int cont = 0;
        std::string line;
        //std::cout << "read_mirs #" << std::endl;
        //char * name;
        if (myfile.good()){
            while( std::getline(myfile, line ).good() ){
               std::stringstream ss(line);
               std::getline(ss, line,' ');
               //std::cout << "read_mirs1 #" << line << "#" << cont << std::endl;
               //line.erase(line.begin());
               //std::cout << "read_mirs2 #" << line << "#" << cont << std::endl;
               map->add_mir(line, cont);
               cont++;
            }
            myfile.close();
        }
        else std::cout << "Unable to open file";
    }

    void ReadFiles::read_genes(char * file, MiRNATargetMap * map){
            std::ifstream myfile (file);
            int cont = 0;
            //int ids = 0;
            std::string line;
            //char * name;
            if (myfile.good()){
                while(std::getline(myfile, line).good()){
                std::stringstream ss(line);
                //std::cout << "read_genes1 #" << line << "#" << cont << std::endl;
                std::getline(ss, line,' ');
                //line.erase(line.begin());
                //std::cout << "read_genes2 #" << line << "#" << cont << std::endl;
                map->add_target(line, cont);
                cont++;
             }
             myfile.close();
         }
         else std::cout << "Unable to open file";
    }
                    //line.erase(line.begin());
                    //std::stringstream ss(line);
                    //while(std::getline(ss, line,'|').good()){
                        //if(cont == 3){
                            //map->add_target(line, ids);
                            //ids++;
                        //}
                    //cont++;
                    //}
                //cont = 0;
                //}
                //myfile.close();
            //}
//
            //else std::cout << "Unable to open file";
    //}

    void ReadFiles::read_interactions(char * file, MiRNATargetMap * map){
        std::ifstream myfile (file);
        int cont = 0;
        int i = 0;
        std::string line, substr, mir_name, refseq;
        if (myfile.good()){
            while( std::getline(myfile, line ).good() ){
				std::stringstream ss(line);
				//std::cout << "read_int1 #" << line << "#" << cont << std::endl;
				while(std::getline(ss,substr,',')){
                    //std::cout << "read_intmir1 #" << mir_name << "#" << cont << std::endl;
                    //std::cout << "read_intgen1 #" << refseq << "#" << cont << std::endl;
                    if(cont == 0)
                        refseq = substr;
                    else{
                        mir_name = substr;
                        cont = -1;
					}
					cont++;
					//std::cout << "read_intmir2 #" << mir_name << "#" << cont << std::endl;
					//std::cout << "read_intref #" << refseq << "#" << cont << std::endl;
                }
                //if(mir_name.size() > 0 && mir_name[0] == '['){
                    //mir_name.erase(0,1);
                    //mir_name.erase(mir_name.size()-1);
                //}
                map->add_interaction(mir_name, refseq);
                //std::cout << "read_intmap #" << map << "#" << i << std::endl;
                i++;
           	}
            myfile.close();
        }

        else std::cout << "Unable to open file";
    }
