#include <fstream>
#include <string>
#include <iostream>

//Read file line by line from given filepath
void read_file_by_line(const std::string& filepath)
{
	std::ifstream file;
	file.open(filepath);

	if(file.is_open())
	{
		std::string line;
		while(std::getline(file, line))
		{
			std::cout << "Here is a line: " << line << std::endl;
		}
		file.close();
	}
}

//Read file word by word (selected by surrounded whitespace) from given filepath
void read_file_by_word(const std::string& filepath)
{
	std::ifstream file;
	file.open(filepath);

	if (file.is_open())
	{
		std::string word;
		while (file >> word)
		{
			std::cout << "Here is a word: " << word << std::endl;
		}
		file.close();
	}
}
