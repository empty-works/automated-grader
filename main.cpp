#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

size_t get_score(const std::string &, const std::string &);

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
	
	std::string line {};
	std::string correct_answer {};
	bool correct_answer_saved = false;
	size_t index {0};
	while(std::getline(in_file, line)) {
	
		if(!correct_answer_saved) {
		
			correct_answer = line;
			correct_answer_saved = true;
		}		
		else {
			size_t score = get_score(correct_answer, line);	
		}
		index++;
	}

	return 0;
}

size_t get_score(const std::string &correct_answer, const std::string &student_answer) {

	size_t num_matches {0};
	for(size_t i {0}; i < correct_answer.length(); i++) {
	
		if(correct_answer[i] == student_answer[i]) {
		
			num_matches++;
		}
	}
	return num_matches;
}
