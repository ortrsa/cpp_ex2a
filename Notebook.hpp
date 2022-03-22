#include <string>
#include <string.h>
#include <iostream>
#include "Direction.hpp"

using namespace std;
namespace ariel{
    class Notebook
    {
    public:
        static int write(int p, int r, int c, Direction d, const string &s );
        static string read(int p, int r, int c, Direction d, int l ) ;
        static int erase(int p, int r, int c, Direction d, int l );
        static string show(int p);  
    };
}