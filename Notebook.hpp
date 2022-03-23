
#include "Direction.hpp"
#include <iostream>
namespace ariel
{
    class Notebook
    {
        public:
        void write(const int page, const int row,const int columun,const Direction d,const std::string s);
        std::string read(const int page,const int row,const int columun,const Direction d,const int l)const;
        void erase(const int page, const int row,const int columun,const Direction d,const int l);
        void show(int page)const;
    };

}