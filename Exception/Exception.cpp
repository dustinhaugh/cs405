// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>


// Custom exception class derived from std::exception
class MyCustomException : public std::exception {
public:
    MyCustomException(const char* message) : msg(message) {}

    // Override the what() method to provide a custom error message
    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};



bool do_even_more_custom_application_logic()
{
    // TODO: Throw any standard exception   DONE


    try {
        throw std::runtime_error("This is a standard runtime error");
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}





void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()    ***************************************
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;


    try {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "do_custom_application_logic: Error message from exception: " << exception.what() << std::endl;
    }


    // TODO: Throw a custom exception derived from std::exception     ***************************************
    //  and catch it explictly in main

    std::cout << "Leaving Custom Application Logic." << std::endl;

}


// Done with TODO
float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    
    // Dustin Haugh:  This is a standard exception that will give us an exception error message

   if (den == 0) {
        throw std::runtime_error("Divide by zero error");

    }
    
    return (num / den);
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;
    
    // Dustin Haugh: created double result;
    double result;

    // Dustin Haugh: try to divide by zero
    try { result = divide(numerator, denominator); }

    // Dustin Haugh: capture only the exception thrown by the divide function and not catch any other exceptions that might occur
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
     std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
}




int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception
    //  that wraps the whole main function, and displays a message to the console.




    // Dustin Haugh, nested try and catch allows for me to catch any exception missed. 


    try {
        try {
            // Code that may throw a custom exception
            do_division();
            do_custom_application_logic();
            throw MyCustomException("This is a custom exception message");
        }
        catch (const MyCustomException& ce) {
            std::cerr << "Caught custom exception: " << ce.what() << std::endl;
            // You can handle or rethrow the custom exception here if needed.
        }

        try {
            // Code that may throw an std::exception
            throw std::runtime_error("std::exception occurred");
        }
        catch (const std::exception& se) {
            std::cerr << "Caught std::exception: " << se.what() << std::endl;
            // You can handle or rethrow the std::exception here if needed.
        }

        // Code that may throw other exceptions

    }
    catch (...) {
        std::cerr << "Caught an uncaught exception" << std::endl;
        // Handle or log the uncaught exception here.
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
