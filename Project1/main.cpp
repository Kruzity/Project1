#include<fstream>
#include<iostream>
#include<string>

using namespace std;


int main()
{
	fstream file, file2;
	file.open("text.txt", ios::in);
	if (file.is_open())
	{
		string tmp, alltext, finnal_text;

		while (getline(file, tmp))
		{
			alltext += tmp;
		}
		cout << alltext << endl;
		int pos = -1;
		int lenght_sentence;
		while (true) {
			tmp.clear();
			pos = alltext.find_first_of(".!?", ++pos);
			if (pos != string::npos) {
				for (int i = 0; i < pos+1; i++)
					tmp += alltext[i];
				alltext.erase(alltext.begin(), alltext.begin()+pos+1);
				cout << alltext << endl;
				lenght_sentence = tmp.length();
				for (int i = 0; i < lenght_sentence / 2; i++)
					swap(tmp[i], tmp[lenght_sentence - i - 1]);
				if (tmp[0] == '.' || tmp[0] == '!' || tmp[0] == '?')
				{
					tmp += tmp[0];
					tmp.erase(tmp.begin());
				}

				finnal_text += tmp;
				pos = 1;
			}
			else break;
		}
		
		

		file2.open("output.txt", ios::out);
		if (file2.is_open())
			file2 << finnal_text;
	}
}