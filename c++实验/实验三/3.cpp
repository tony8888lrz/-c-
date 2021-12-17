#include <string>
#include "mystack.h"
#include <iostream>
int main()
{
    Stack<std::string> notes;
    notes.push("Tony");
    notes.push("is");
    notes.push("handsome");

    std::cout << notes.pop() << std::endl;
    std::cout << notes.pop() << std::endl;
    std::cout << notes.pop() << std::endl;
    return 0;
}