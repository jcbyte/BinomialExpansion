#include <iostream>
#include <string>

void SplitNumVar(std::string s, int* num, char** var)
{
	std::string numChars = "+-0123456789";

	std::string numString;
	std::string varString;
	bool endOfNum = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (endOfNum)
		{
			varString += s[i];
		}
		else
		{
			if (numChars.find(s[i]) != std::string::npos)
			{
				numString += s[i];
			}
			else
			{
				endOfNum = true;
				varString += s[i];
			}
		}
	}

	*num = std::stoi(numString);

	*var = new char[varString.length()];
	for (int i = 0; i < varString.length(); i++)
		(*var)[i] = varString[i];
}

int main(int argc, char** argv)
{
	std::cout << "(a+b)^n where n is an integer" << std::endl << std::endl;

	std::string a;
	std::cout << "a = "; std::cin >> a;
	std::string b;
	std::cout << "b = "; std::cin >> b;
	std::string n;
	std::cout << "n = "; std::cin >> n;

	int aNum;
	char* aVar = nullptr;
	SplitNumVar(a, &aNum, &aVar);
	int bNum;
	char* bVar = nullptr;
	SplitNumVar(b, &bNum, &bVar);
	int nNum = std::stoi(n);



	system("pause > nul");
	return 0;
}
