#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template <typename T>
void print(T x)
{
    std::cout<<x;
}

int main()
{
    std::vector<int> numbers {1,2,3,4};
    int sum = 0;

    // Pierwszy sposob
    for(int i = 0; i<numbers.size(); i++)
        sum += numbers[i];

    std::cout << sum << std::endl;
    // Drugi sposob
    sum = 0;
    for(int i = 0; i<numbers.size(); i++)
        sum += numbers.at(i);
    std::cout << sum << std::endl;
    sum = 0;
    //Trzeci sposob
    for (int number : numbers)
        sum += number;
    std::cout << sum << std::endl;
    sum = 0;
    //Czwarty sposob
    for (const auto& number: numbers)
        sum += number;
    std::cout << sum << std::endl;
    sum = 0;
    //Piaty sposob
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        sum += *it;
    std::cout << sum << std::endl;
        sum = 0;
    //Szosty sposob
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
        sum += *it;
    std::cout << sum << std::endl;
    sum = 0;
    //Siodmy sposob
    sum =  std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << sum << std::endl;
    return 0;

}
