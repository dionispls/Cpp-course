#include <iostream>
#include <iomanip>

int main() {
    std::string name, hasCashbac;
    int price, temperature;
    bool hasCashback;
    std::cout << "Product's name: ";
    std::cin >> name;
    std::cout << "Product's price: ";
    std::cin >> price;
    std::cout << "Is cash-back available for this product? (true/false) ";
    std::cin >> hasCashbac;
    if (hasCashbac == "true")
        hasCashback = 1;
    else
        hasCashback = 0;
    std::cout << "Maximum storing temperature: ";
    std::cin >> temperature;
    std::cout << '\n' << "*************** OUTPUT ***************" << "\n\n";
    std::cout << name << '\n';
    std::cout.unsetf(std::ios::dec);
    std::cout.setf(std::ios::hex | std::ios::uppercase);
    std::cout << "Price:..........." << std::setfill('0')<< std::  setw(8) << price << '\n';
    if (hasCashback == 1)
        std::cout << "Has cash-back:.......true" << "\n";
    else
        std::cout << "Has cash-back:......false" << "\n";
    std::cout.setf(std::ios::showpos);
    std::cout.unsetf(std::ios::hex);
    std::cout.setf(std::ios::dec);
    std::cout << "Max temperature:......" << std::setfill('0')<< std::setw(2) << temperature;
    return 0;
}
