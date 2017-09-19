// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string option;
	string vstup;
	cout << "text-counter <option> [input.txt]" << endl;
	cout << "  -c  spocitanie znakov" << endl << "  -w  spocitanie slov" << endl << "  -l  spocitanie riadkov" << endl;
	cout << "zadajte option: ";
	cin >> option;
	cout << endl;
	cout << "zadajte vstup: ";
	cin >> vstup; 


	ifstream myfile;
	myfile.open(vstup);
	string line;
	int pocRiad = 0;
	int pocZnak = 0;
	int pocSlov = 0;
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			cout << line << "\n";
			if (option=="-l") {
				pocRiad++;
			}
			else if (option=="-c") {
				for (char& c : line) {
					if (isspace(c)==0) {
						pocZnak++;
					}
				}
			}
			else if (option=="-w") {
				if (line.find_first_not_of(' ') != std::string::npos) {
					const char *c = line.c_str();
					for (int i = 0; i < line.length(); i++) {
						if (isspace(c[i]) != 0) {
							pocSlov++;
							while (isspace(c[i]) != 0 && i + 1 < line.length()) {
								i++;
							}
						}
					}
					if (line.length() > 0) {
						pocSlov++;
					}
				}
			}
			else {
				cout << "bad option" << endl;
			}
		}
		myfile.close();
	}
	else {
		line = vstup;
		cout << vstup << endl;
		if (option == "-l") {
			pocRiad++;
		}
		else if (option == "-c") {
			for (char& c : line) {
				if (isspace(c) == 0) {
					pocZnak++;
				}
			}
		}
		else if (option == "-w") {
			if (line.find_first_not_of(' ') != std::string::npos) {
				const char *c = line.c_str();
				for (int i = 0; i < line.length(); i++) {
					if (isspace(c[i]) != 0) {
						pocSlov++;
						while (isspace(c[i]) != 0 && i + 1 < line.length()) {
							i++;
						}
					}
				}
				if (line.length() > 0) {
					pocSlov++;
				}
			}
		}
		else {
			cout << "bad option" << endl;
		}
	}


	if (option == "-l") {
		cout << pocRiad << endl;
	}
	else if (option == "-c") {
		cout << pocZnak << endl;
	}
	else if (option == "-w") {
		cout << pocSlov << endl;
	}

	return 0;
}
