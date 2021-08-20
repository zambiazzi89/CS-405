// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
  std::cout << "Buffer Overflow Example" << std::endl;

  // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
  //  even though it is a constant and the compiler buffer overflow checks are on.
  //  You need to modify this method to prevent buffer overflow without changing the account_order
  //  varaible, and its position in the declaration. It must always be directly before the variable used for input.

  const std::string account_number = "CharlieBrown42";
  char user_input[20];
  std::cout << "Enter a value: ";
  
  /* ==================== First approach (simpler) ====================
  * This approach limits the size of the input buffer:
  * std::cin.width(20);
  * std::cin >> user_input;
  */
  
  /* ==================== Second approach (dynamic) ====================
  * Allows user to try multiple input values:
  * 
  * std::cin.getline(user_input, 20);
  * 
  * while (std::cin.fail()) {
  *   std::cout << "Buffer overflow prevented, input should be shorter than 20 characters." << std::endl;
  *   std::cin.clear(std::cin.goodbit);
  *   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  *   std::cout << "Enter a value: ";
  *   std::cin.getline(user_input, 20);
  * }
  */

  /* ========== Third approach (error message, not dynamic) ==========
  * Prints message when buffer overflow occurs:
  */
  std::cin.getline(user_input, 20);

  if (std::cin.fail()) {
	std::cout << "Buffer overflow prevented, input should be shorter than 20 characters." << std::endl;
  }

  std::cout << "You entered: " << user_input << std::endl;
  std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
