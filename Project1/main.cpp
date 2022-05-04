#include<fstream>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	setlocale(0, "");
	fstream file;
	string word;
	cout << "¬ведите искомое слово: ";
	getline(cin, word);
	file.open("text.txt", ios::in);
	if (file.is_open())
	{
		string tmp;
		int c = 0;
		while (getline(file, tmp))
		{
			int pos = -1;
			while (true) {
				pos = tmp.find(word, ++pos);
				if (pos != string::npos) {
					c++;
				}
				else break;
			}
		}
		cout << word <<" найдено: " << c;
		file.close();
	}
	else
	{
		cout << "Error" << endl;
	}

}