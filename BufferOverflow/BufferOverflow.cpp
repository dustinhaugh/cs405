// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.


  const int MAX_CHARACTERS = 20;  // created a constant int value for max characters at 20

  const std::string account_number = "CharlieBrown42";
  char user_input[MAX_CHARACTERS];
  std::cout << "Enter a value: ";
  std::cin >> setw(MAX_CHARACTERS) >> user_input;  // CS-405 SNHU Dustin Haugh ADDED setw(20) to limit the input to 20 characters

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
