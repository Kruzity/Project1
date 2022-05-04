#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	fstream file;
	file.open("text.txt", ios::in);
	if (file.is_open())
	{
		string tmp;
		int points = 0, comas = 0;
		while (getline(file, tmp))
		{
			int point = -1, coma = -1;
			while (true) {
				point = tmp.find_first_of(".", ++point);
				if (point != string::npos) {
					points++;
				}
				else break;
			}
			while (true) {
				coma = tmp.find_first_of(",", ++coma);
				if (coma != string::npos) {
					comas++;
				}
				else break;
			}
		}
		cout << "Points: " << points <<"\nComas: "<<comas <<"\nTotal:"<<points+comas<< endl;
	}
}