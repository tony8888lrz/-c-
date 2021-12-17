#include <iostream>
#include <fstream>
#include <string>
int main(void)
{
    // initialize
    std::ofstream fout;
    std::ifstream fin;
    //file output
    fout.open("cad.dat");
    fout <<  "C is a Computer Programming Language which is used worldwide, Everyone should learn how to use C !" << std::endl;

    //file input
	fin.open("cad.dat");
    std::string words;
    getline(fin,words);
	std::cout << words << std::endl;
 
    for(std::string::size_type pos = 0;
    (pos = words.find("C", pos)) != std::string::npos; // start find at pos
    pos += 3)  // skip "C++"
	{
		if(  == ' ')
    		words.replace(pos, 1, "C++");
	}

	std::cout << words;
}
