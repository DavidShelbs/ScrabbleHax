#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
	// if(argc != 2)
	// {
	// 	cout << "Incorrect number of arguments given." << endl;
	// 	cout << "\nFormat should be:\n\t./[executable] [filename]" << endl;
	// 	return 0;
	// }

	fstream ifil;
	ifil.open ("wordlist.txt");
  if (!ifil.is_open())
  {
    cout << "Error opening file.\nPlease check that the filename was typed correctly or that the path is correct." << endl;
		return 0;
  }
	else
	{
    while (ifil.good())
    {
      string word;
      ifil >> word;
			bool format = true;
			if (word.length() > 7 || word.length() < 3)
			{
				format = false;
			}

      for (int i = 0; i < word.length(); i++)
			{
				if (word[i] == '-')
				{
					format = false;
				}
			}

			if (format)
			{
				cout << word << endl;
			}

    }
  }

	ifil.close();
	return 0;
}
