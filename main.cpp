#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

int main() {

	std::cout << std::setw(30) << std::left << "Student";
	std::cout << "Score" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	
	std::ifstream in_file;
	in_file.open("responses.txt");
	if(!in_file) {
	
		std::cerr << "Error opening file." << std::endl;
		return 1;
	}	

	return 0;
}
