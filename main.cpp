// app.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream myfile;
	myfile.open("vstupnySubor.txt");
	string line;
	if (myfile.is_open()) {
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
	else {
		cout << "zadajte vstup z klavesnice" <<end
		cin >> line;
	}



	return 0;
}
