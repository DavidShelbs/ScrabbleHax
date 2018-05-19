#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>
#include<bits/stdc++.h>
using namespace std;

int point_distribution(string word);

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
      int total;
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
      total = point_distribution(word);
			if (format)
			{
				cout << word << " - " << total << endl;
			}

    }
  }

	ifil.close();
	return 0;
}

int point_distribution(string word)
{
  int total = 0;
  for (int i = 0; i < word.length(); i++)
  {
    if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o'
    || word[i] == 'n' || word[i] == 'r' || word[i] == 't' || word[i] == 'l'
    || word[i] == 's' || word[i] == 'u')
    {
      total += 1;
    }
    else if (word[i] == 'd' || word[i] == 'g')
    {
      total += 2;
    }
    else if (word[i] == 'b' || word[i] == 'c' || word[i] == 'm' || word[i] == 'p')
    {
      total += 3;
    }
    else if (word[i] == 'f' || word[i] == 'h' || word[i] == 'v' || word[i] == 'w' || word[i] == 'y')
    {
      total += 4;
    }
    else if (word[i] == 'k')
    {
      total += 5;
    }
    else if (word[i] == 'j' || word[i] == 'x')
    {
      total += 8;
    }
    else if (word[i] == 'q' || word[i] == 'z')
    {
      total += 10;
    }
  }
  return total;
}
