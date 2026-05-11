#include <iostream>
#include <fstream> 
#include <string>

int main(int ac, char *av[])
{
	if (ac == 4)
	{
		//+ Open the file
		std::ifstream ogFile(av[1]);
		if (!ogFile.is_open())
		{
			std::cout << "Err: file not found" << std::endl;
			return (1);
		}

		//+ Create and open a text file
		std::string fileName;
		fileName.assign(av[1]);
		fileName.append(".replace");
		std::ofstream outputFile(fileName.c_str());
		std::string buff;
		std::string s1 = av[1];
		std::string s2 = av[2];

		//+ Populate the output file
		while (getline (ogFile, buff))
		{
			size_t pos;
			pos = buff.find(s1);
			while (pos != std::string::npos)
			{
				buff.erase(pos, s1.length());
				buff.insert(pos, s2);
			}
			outputFile << buff << "\n";
		}

		//+ Close the files and exit
		outputFile.close(); 
		ogFile.close();
		return (0);
	}
	std::cout << "Expected 2 agruments" << std::endl;
	std::cout << "Usage: ./sed [word] [replacement]" << std::endl;
	return (1);
}

//*NOTE: NOW GO INSIDE THE WHILE LOOP AND DO THIS:
/* 
ac == 4 check (filename, s1, s2)
s1.empty() check

ifstream ogFile(av[1])
ofstream newFile(av[1] + ".replace")
is_open() check both

while getline(ogFile, line):
    pos = line.find(s1)
    while pos != string::npos:
        line.erase(pos, s1.length())
        line.insert(pos, s2)
        pos = line.find(s1, pos + s2.length())
    newFile << line << "\n"

ogFile.close()
newFile.close() */