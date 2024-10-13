#include <iostream>
#include "Vector3D.h"

bool goAgain();

int main()
{
    Vector3D myVec(2.3, 4.5, 7.891);

    myVec /= 3;

    Vector3D otherVec = {1,1,1};
    myVec = myVec + otherVec;

    std::cout << myVec;

    Vector3D inputVec;

    do{
        std::cout << "\nEnter new values for the vec: ";
        std::cin >> inputVec;

        std::cout << "New input vector = " << inputVec;
    } while (goAgain());

    std::cout << "\nThe cross product:\n";
    std::cout << myVec << " x " << inputVec << " = " << myVec.crossProduct(inputVec) << std::endl;

    std::cout << "\nThe dot product:\n";
    std::cout << myVec << " * " << inputVec << " = " << myVec * inputVec << std::endl;

    std::cout << "\nAdding:\n";
    std::cout << myVec << " + " << inputVec << " = " << myVec + inputVec << std::endl;

    std::cout << "\nSubtracting:\n";
    std::cout << myVec << " - " << inputVec << " = " << myVec - inputVec << std::endl;

    std::cout << "\nDivide by scalar:\n";
    std::cout << inputVec << " / 3 = " << inputVec / 3 << std::endl;

    return 0;
}

bool goAgain() {
    std::string input;

    do {
        std::cout << "\nDo you want to go again? Please type \"yes\" or \"no\": ";

        std::getline(std::cin, input);

        // Convert input to lowercase for case-insensitive comparison
        std::transform(input.begin(), input.end(), input.end(), ::tolower);

        if (input == "yes")
            return true;
        if (input == "no")
            return false;

        std::cout << "Invalid input, please try again.\n";
    } while (true);
}
