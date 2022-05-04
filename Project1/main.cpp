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
		int c = 0;
		while (getline(file,tmp))
		{
			int pos = -1;
			while (true) {
				pos = tmp.find_first_of(".?!", ++pos);
				if (pos != string::npos) {
					c++;
				}
				else break;
			}
		}
		cout << "Sentences: " << c << endl;
	}
}