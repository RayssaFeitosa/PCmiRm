#ifndef MIRNATARGETMAP_H
#define MIRNATARGETMAP_H
#include <vector>
#include <bitset>
#include <string>
#include "MiRNA.h"
#include "Target.h"
//#define MAX_GENES 18810
#define MAX_GENES 3328
#define MAX_MIRS 217
class MiRNATargetMap{
    public:
        MiRNATargetMap ();
       // MiRNATargetMap (const MiRNATargetMap& other);
        MiRNATargetMap& operator= (const MiRNATargetMap& other);
        MiRNA get_mir (int id);
        Target get_target (int id);
        std::bitset<MAX_GENES> * get_map() const;
        std::vector<MiRNA> get_miRNAs () const;
        std::vector<Target> get_targets ()const;
        std::vector<Target> get_targets_of_a_miRNA(int mirna_id);
        void add_mir (std::string name, int id);
        void add_target (std::string refseq, int id);
        void add_interaction (std::string mir_name, std::string refseq);
        void add_interaction (int id_mir, int id_target);


    /*
     * os valores no bitset ficam na ordem contrária, ex: se eu tiver um bitset de 3 pos e colocar o bit 1 = 1 vai ficar 010
     * para acessar a pos x no vetor: mirs.at(x)
     * para acessar a pos y no bitset da pos x no vetor: mirs.at(x)[y] 
     */
    //private:
        //std::bitset<MAX_GENES> * map;
        std::bitset<MAX_GENES> map[MAX_MIRS];
        std::vector<MiRNA> mirs;
        std::vector<Target> targets;
};
#endif // MIRNATARGETMAP_H
