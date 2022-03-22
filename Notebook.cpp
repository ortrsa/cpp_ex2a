
#include <string>
#include <string.h>
#include <iostream>
#include "Direction.hpp"
#include "Notebook.hpp"

using namespace std;
namespace ariel{
    
        int Notebook::write(int p, int r, int c, Direction d, const string &s ){
            return 0;
        }
        string Notebook::read(int p, int r, int c, Direction d, int l ){
            return " ";
        }
        int Notebook::erase(int p, int r, int c, Direction d, int l ){
            return 0;
        }
        string Notebook::show(int p){
            return " ";
        }
}