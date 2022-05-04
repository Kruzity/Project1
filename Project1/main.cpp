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
		string tmp, alltext;
		
		while (getline(file, tmp))
		{
			alltext += tmp;
			alltext += '\n';
		}
		cout << alltext << endl;
		int n = alltext.length() - 1;
		for (int i = 0; i < (alltext.length() / 2); i++) 
		{	
			swap(alltext[i], alltext[n]);
			n = n - 1;
		}
		cout << alltext << endl;
		alltext.erase(alltext.begin());
		file2.open("output.txt", ios::out);
		if (file2.is_open())
			file2 << alltext;
	}
}