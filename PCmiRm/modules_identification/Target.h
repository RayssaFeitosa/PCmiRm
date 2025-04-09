#ifndef TARGET_H
#define TARGET_H
#include <string>
#include <map>
#include <stdlib.h>
class Target
{
    public:
        Target(std::string refseq, int id);
        //esse eh o id no vector de bitset
        int get_id() const;
        std::string get_refseq();
        void set_id(int id);
        void set_refseq(std::string refseq);
    private:
        std::string refseq;
        int id;
};

#endif // TARGET_H
