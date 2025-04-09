#ifndef READFILES_H
#define READFILES_H
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include "MiRNATargetMap.h"
class ReadFiles{
    public:
        ReadFiles();
        void read_mirs(char * file, MiRNATargetMap * map);
        void read_genes(char * file, MiRNATargetMap * map);
        void read_interactions(char * file, MiRNATargetMap * map);
        void read_dados_simulados(char * file, std::string type, MiRNATargetMap * map);
};
#endif // READFILES_H
