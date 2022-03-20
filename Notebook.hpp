
#include "Direction.hpp"
#include <iostream>
namespace ariel
{
    class Notebook
    {
        public:
        void write(const unsigned int page, const unsigned int row,const unsigned int columun,const Direction d,const std::string s);
        std::string read(const unsigned int page,const unsigned int row,const unsigned int columun,const Direction d,const unsigned int l)const;
        void erase(const unsigned int page, const unsigned int row,const unsigned int columun,const Direction d,const unsigned int l);
        void show(unsigned int page)const;
    };

}