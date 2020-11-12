#include <iostream>
#include <ctime>
#include <tuple>

int sum(int a, int b, int c) {
    return a + b + c;
}

int product(int a, int b, int c) {
    return a * b * c;
}

std::tuple<int, int, int> generateRandomNumbers(int maxVal) {
    return std::make_tuple(
        rand() % maxVal + 1, 
        rand() % maxVal + 1, 
        rand() % maxVal + 1
    );
}

std::tuple<int, int> genProdSum(int a, int b, int c) {
    return std::make_tuple(product(a, b, c), sum(a, b, c));
}

void printIntroduction() {
    std::cout << "\n\nHello weary traveller!\n";
    std::cout << "To cross this bridge you see in front of thee, you must answer my puzzles with numbers three!\n";
    std::cout << "I'll giveth you their product and sum; return unto me the numbers that madeth them.\n";
    std::cout << "Five challenges I present, but three tries for each I'll provide since you are so pleasant.\n";
    std::cout << "Enter your guess with a space between, if you'd be so kind.  Otherwise, they will be declined!\n";
}

void printChallengeInfo(int currentLevel, int rProd, int rSum) {
    std::cout << "\n\n|-------------Challenge " << currentLevel << "-------------|\n";
    std::cout << " + The product of the numbers is " << rProd << "\n";
    std::cout << " + The sum of the numbers is " << rSum << "\n\n";

    // Explanation of inputs on first level
    if (currentLevel == 1) {
        std::cout << "Enter your guesses below. Separate each number by a space and then press Enter.\n\n";
    }
}

bool playLevel(int currentLevel) {
    // Generate random numbers, calculate Product and Sum
    int rA, rB, rC, rProd, rSum;
    std::tie(rA, rB, rC) = generateRandomNumbers(currentLevel + 2);
    std::tie(rProd, rSum) = genProdSum(rA, rB, rC);

    printChallengeInfo(currentLevel, rProd, rSum);
    
    int numberOfTries = 3;
    while (numberOfTries > 0) {
        // Initialize and collect guess values
        int gA, gB, gC;
        std::cout << "Guess: ";
        std::cin >> gA >> gB >> gC;

        // Calculate Product and Sum of guess values
        const int gProd = product(gA, gB, gC);
        const int gSum = sum(gA, gB, gC);

        // Resolve Guess
        if (gProd == rProd && gSum == rSum) {
            std::cout << "You got it!\n";
            return true;
        } else {
            std::cout << "Nope!\n";
            numberOfTries--;
        }
    }

    std::cout << "You have failed my test!  Begone!";
    return false;
}

int main() {
    printIntroduction();

    int currentLevel = 1;
    const int maxLevel = 5;

    while (currentLevel <= maxLevel) {
        if (playLevel(currentLevel)) {
            currentLevel++;
        } else {
            break;
        }

        std::cin.clear();
        std::cin.ignore();
    }

    
    if (currentLevel > maxLevel) {
        std::cout << "\n\nVery well, you have passed my test.  Carry on, and good luck on your little quest!";
    } else {
        std::cout << "\n\nNot worthy! Not worthy!";
    }
    
    return 0;
}