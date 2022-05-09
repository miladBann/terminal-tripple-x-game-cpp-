#include <iostream>
#include <ctime>

bool PlayGame(int diffeculity) {

	std::cout << "\nyou are trying to hack server number 310 in level " << diffeculity << std::endl;
	std::cout << "there are 10 servers total and you need to hack them all to grant full access." << std::endl;
	std::cout << "in order to gain access you need to enter a code.\n" << std::endl;

	std::cout << "your computer is telling you the following info:" << std::endl;
	std::cout << "[+] the code consists of 3 numbers." << std::endl;

	
	int codeA =(1 + rand() % diffeculity), codeB = (1 + rand() % diffeculity), codeC = (1 + rand() % diffeculity);
	int codeSum = codeA + codeB + codeC;
	int codeProduct = codeA * codeB * codeC;

	std::cout << "[+] the sum of the 3 numbers is " << codeSum << std::endl;
	std::cout << "[+] the product of the 3 numbers is " << codeProduct << "\n" << std::endl;

	std::cout << "enter your guess: ";
	int guessA, guessB, guessC;
	std::cin >> guessA;
	std::cin >> guessB;
	std::cin >> guessC;

	int guessSum = guessA + guessB + guessC;
	int guessProduct = guessA * guessB * guessC;

	if (guessSum == codeSum && guessProduct == codeProduct) {
		std::cout << "Access granted to serevr " << diffeculity << "! keep going." << std::endl;
		std::cout << "_____________________________________________________" << std::endl;
		return true;
	}
	else {
		std::cout << "Access denaied to server " << diffeculity << "! try again." << std::endl;
		std::cout << "_____________________________________________________" << std::endl;
		return false;
	}

}

int main() {

	srand(time(NULL));

	int levelDiffeculity = 1;
	const int maxDiffeculity = 10;
	int numbersDiffeculity = 1;

	while (levelDiffeculity <= maxDiffeculity)
	{
		bool levelCompleted = PlayGame(levelDiffeculity);
		std::cin.clear(); // clears any error
		std::cin.ignore(); // discards the buffer

		if (levelCompleted) {
			++levelDiffeculity;
		}
	}

	std::cout << "Damn boyy!!\nYou were able to hack all 10 levels" << std::endl;

	return 0;
}