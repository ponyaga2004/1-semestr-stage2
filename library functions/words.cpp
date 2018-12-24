#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::vector<std::string> get_words(std::string s) {
	std::istringstream iss(s);
	std::vector<std::string> result;
	for(std::string word; iss >> word; ) {
		result.push_back(word);
	}
	return result;
}

int main() {
	std::ifstream ifs("data.DAT", std::ifstream::in);
	
	std::vector<std::string> lines;

	std::string str;
	while(std::getline(ifs, str)) {
		lines.push_back(str);
	}

	for(int i = 0; i < lines.size(); i++) {
		std::cout << i << ": " << lines[i] << std::endl;
	}

	std::string** words = new std::string*[lines.size()];
	int *words_count = new int[lines.size()];
	for(int i = 0; i < lines.size(); i++) {
		std::vector<std::string> words_vector = get_words(lines[i]);

		words[i] = new std::string[words_vector.size()];
		for (int j = 0; j < words_vector.size(); j++) {
			words[i][j] = words_vector[j];
		}
		words_count[i] = words_vector.size();
	}

	std::string pattern;
	std::cout << "Enter word: ";
	std::cin >> pattern;
	std::cout << "Look up for " << pattern << std::endl;

	for(int i = 0; i < lines.size(); i++) {
		for(int j = 0; j < words_count[i]; j++) {

			if (pattern == words[i][j]) {

				std::string show;
				for(int k = 0; k < words_count[i]; k++) {
					if (k == j) {
						show = show + ">>>" + words[i][k] + "<<< ";
					} else {
						show = show + words[i][k] + " ";
					}
				}

				std::cout << i << ": " << show << std::endl; 

				std::string c;
				getline(std::cin, c);
			}
		}
	}


}

