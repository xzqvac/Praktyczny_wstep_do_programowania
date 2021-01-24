#include <iostream>
#include <cstddef>
#include <string>

bool isPalindrome(const std::string& str)
{
    std::size_t len = str.length();

    for (std::size_t i = 0; i < len / 2; ++i)
        if (str.at(i) != str.at(len - i - 1))
            return false;

    return true;
}


int main()
{

    std::string palindrome;
    std::cout << "Podaj wyraz" << std::endl;
    std::cin >> palindrome;

    if (isPalindrome(palindrome))
        std::cout << "Wyraz " << palindrome << " jest palindromem" << std::endl;
    else
        std::cout << "Wyraz " << palindrome << " nie jest palindromem" << std::endl;

    return 0;
}
