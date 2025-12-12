#include "PMergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: " << argv[0] << " <number1> <number2> ... <numberN>" << std::endl;
        std::cout << "Example: " << argv[0] << " 30 49 60 1 31 29 42 46 13 8 5" << std::endl;
        return 1;
    }
    std::vector<int> numbers;
    std::deque<int> d_numbers;
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || !iss.eof())
        {
            std::cerr << "Error: '" << argv[i] << "' is not a valid integer" << std::endl;
            return 1;
        }
        if (num < 0)
        {
            std::cerr << "Error: Negative numbers are not allowed: " << num << std::endl;
            return 1;
        }
        numbers.push_back(num);
        d_numbers.push_back(num);
    }

    if (numbers.empty() || d_numbers.empty())
    {
        std::cout << "No numbers to sort" << std::endl;
        return 0;
    }

    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i];
        if (i < numbers.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    clock_t start_vec = clock();
    std::vector<int> sorted = fjSort(numbers);
    clock_t end_vec = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < sorted.size(); ++i)
    {
        std::cout << sorted[i];
        if (i < sorted.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << numbers.size()
              << " elements with std::vector : "
              << std::fixed << ((double)(end_vec - start_vec) / CLOCKS_PER_SEC * 1e6)
              << " us" << std::endl;

    std::cout << "Before: ";
    for (size_t i = 0; i < d_numbers.size(); ++i)
    {
        std::cout << d_numbers[i];
        if (i < d_numbers.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;

    clock_t start_deque = clock();
    std::deque<int> d_sorted = fjSort_2(d_numbers);
    clock_t end_deque = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < d_sorted.size(); ++i)
    {
        std::cout << d_sorted[i];
        if (i < d_sorted.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << d_numbers.size()
              << " elements with std::deque : "
              << std::fixed << ((double)(end_deque - start_deque) / CLOCKS_PER_SEC * 1e6)
              << " us" << std::endl;

    return 0;
}