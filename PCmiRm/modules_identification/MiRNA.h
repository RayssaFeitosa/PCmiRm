#ifndef MiRNA_H
#define MiRNA_H
#include <string>
#include <map>

class MiRNA
{
    public:
        MiRNA(std::string name, int id);
        int get_id() const;
        const std::string get_name();
        void set_id(int id);
        void set_name(std::string name);
    private:
        std::string name;
        int id;
};

#endif // MIRNA_H
