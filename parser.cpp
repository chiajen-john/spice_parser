#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <stdlib.h>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

#define MAX (1<<10)
#define verbose 1
/*
struct database {
    std::string name;
    std::string value;
    database(){};
    database(std::string name, std::string value) {
        this->name = name;
        this->value = value;
    }
};

struct database db[MAX];
int db_ind = 0;
*/

int parse(std::string filename, std::string netname) {
    float value = 0;
    std::ifstream file(filename);
    std::string str;
    std::string pat = "C(.*)";
    pat += netname;
    pat += "(.*)";
    std::regex e (pat);
    std::vector<std::string> v;
    while (std::getline(file, str))
    {
        if (std::regex_match(str, e)) {
            boost::split(v, str, boost::is_any_of(" \t"));
            if (verbose)  {
                std::cout << v[0]<<" "<<v[1]<<" "<<v[2]<<" "<< v[3] <<std::endl;
            }
            value += std::stof(v[3]);

            // db[db_ind] = database(v[0], v[3]);
            // std::cout << db[db_ind].name <<" "<< db[db_ind].value <<std::endl;
            // db_ind++;
        }
    }
    std::cout<<std::endl<<netname<<" total capacitance: "<<value<<std::endl;
    return value;
}


int main(int argc, char *argv[]) 
{ 
    if (argc != 3) {
        std::cout<<argc<<"\n";
        std::cout << "ARGS ERROR" << std::endl;
        return -1;
    }
    parse(argv[1], argv[2]);
    return 0;
}
