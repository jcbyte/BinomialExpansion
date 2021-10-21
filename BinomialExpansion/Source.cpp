#include <iostream>
#include <string>
#include <math.h>

void SplitNumVar(std::string s, int* num, char** var, int* varlength = nullptr)
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

	if (!numString.empty())
		*num = std::stoi(numString);
	else
		*num = 0;

	*varlength = varString.length();
	*var = new char[*varlength];
	for (int i = 0; i < varString.length(); i++)
		(*var)[i] = varString[i];
}

int factorial(int n)
{
	return tgamma(n + 1);
}

int ncr(int n, int r)
{
	return factorial(n) / (factorial(r) * factorial(n - r));
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
	char* aVars = nullptr;
	int aVarLength;
	SplitNumVar(a, &aNum, &aVars, &aVarLength);
	int bNum;
	char* bVars = nullptr;
	int bVarLength;
	SplitNumVar(b, &bNum, &bVars, &bVarLength);
	int nNum = std::stoi(n);

	std::string result = "";
	for (int i = 0; i <= nNum; i++)
	{
		int aPow = nNum - i;
		int bPow = i;

		int finalNum = ncr(nNum, i) * pow(aNum, aPow) * pow(bNum, bPow);
		
		if (i != 0 && finalNum >= 0)
			result += '+';

		std::string finalVars;
		for (int j = 0; j < aVarLength; j++)
			if (aPow != 0)
				finalVars += std::string(1, aVars[j]) + "^" + std::to_string(aPow);
		for (int j = 0; j < bVarLength; j++)
			if (bPow != 0)
				finalVars += std::string(1, bVars[j]) + "^" + std::to_string(bPow);

		result += std::to_string(finalNum) + finalVars;
	}

	std::cout << std::endl << result << std::endl;

	system("pause > nul");
	return 0;
}
