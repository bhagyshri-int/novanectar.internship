
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <limits>

void showMenu()
 {
    std::cout << "Calculator Menu:\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Square Root\n";
    std::cout << "6. Exponentiation\n";
    std::cout << "7. Sine\n";
    std::cout << "8. Cosine\n";
    std::cout << "9. Tangent\n";
    std::cout << "0. Exit\n";
    std::cout << "Enter your choice: ";
}

double getNumber(const std::string& prompt)

{
    double num;
    while (true)
    {
        std::cout << prompt;
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number.\n";
        }
         else
        {
            return num;
        }
    }
}

int main()
{
    int choice;
    double num1, num2, result;

    while (true)
    {
        showMenu();
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 0)
        {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break;
        }

        try
        {
            switch (choice)
            {
                case 1: // Addition
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 + num2;
                    std::cout << "Result: " << result << "\n";
                    break;
                case 2: // Subtraction
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 - num2;
                    std::cout << "Result: " << result << "\n";
                    break;
                case 3: // Multiplication
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    result = num1 * num2;
                    std::cout << "Result: " << result << "\n";
                    break;
                case 4: // Division
                    num1 = getNumber("Enter first number: ");
                    num2 = getNumber("Enter second number: ");
                    if (num2 == 0)
                    {
                        throw std::invalid_argument("Division by zero is not allowed.");
                    }
                    result = num1 / num2;
                    std::cout << "Result: " << result << "\n";
                    break;
                case 5: // Square Root
                    num1 = getNumber("Enter the number: ");
                    if (num1 < 0)
                    {
                        throw std::invalid_argument("Square root of negative number is not allowed.");
                    }
                    result = sqrt(num1);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 6: // Exponentiation
                    num1 = getNumber("Enter the base: ");
                    num2 = getNumber("Enter the exponent: ");
                    result = pow(num1, num2);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 7: // Sine
                    num1 = getNumber("Enter the angle in radians: ");
                    result = sin(num1);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 8: // Cosine
                    num1 = getNumber("Enter the angle in radians: ");
                    result = cos(num1);
                    std::cout << "Result: " << result << "\n";
                    break;
                case 9: // Tangent
                    num1 = getNumber("Enter the angle in radians: ");
                    result = tan(num1);
                    std::cout << "Result: " << result << "\n";
                    break;
                default:
                    std::cerr << "Invalid choice. Please try again.\n";
                    break;
            }

        } catch (const std::invalid_argument& e)

        {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}


