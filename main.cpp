#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

void print();

int numberCh {0};
std::string formatRow {};

void print() {
    std::cout << formatRow << std::endl;
}


int main()
{
    std::map<std::string, double> myMap;

    std::string nameOfCost {};
    std::string cost_str {};
    std::stringstream str_to_num {};
    double cost {0};
    int length_nameOfCost {0};
    int firstColWidth {0};

    while(nameOfCost !="end")
    {
        std::cout << "Enter name of fixed monthly cost: ";
        getline(std::cin,nameOfCost);
        length_nameOfCost = nameOfCost.size();
        if(length_nameOfCost > firstColWidth) {
                firstColWidth = length_nameOfCost;
            }
        if(nameOfCost=="end"){
            goto finish;
            } else {
        std::cout << "Enter value of " << nameOfCost << ": ";
        getline(std::cin, cost_str);
        std::stringstream str_to_num (cost_str);
        str_to_num >> cost;
        myMap.insert(std::pair<std::string, double>(nameOfCost, cost));
        }
    }
    finish:
    std::cout << std::endl;
    std::cout << std::setw(firstColWidth) << std::left << "nameOfCost"
              << std::setw(12) << std::right << "cost" << std::endl;

    double totalMonthlyCost {};

    std::cout << "numberCh=" << numberCh << "  formatRow is: " << formatRow
              << "  firstColWidth=" << firstColWidth << std::endl;

    numberCh = (firstColWidth + 12);

    std::cout << "numberCh=" << numberCh << "  formatRow is: " << formatRow
              << "  firstColWidth=" << firstColWidth << std::endl;

    std::string formatRow (numberCh, '-');
    print();

//    std::cout << "length_nameOfCost is " << length_nameOfCost << std::endl;
//    std::cout << "firstColWidth is " << firstColWidth << std::endl;

    for(auto itr=myMap.begin(); itr!=myMap.end(); itr++)
    {
        std::cout << std::setw(firstColWidth) << std::left << itr->first
                  << std::setw(12) << std::right << itr->second <<  std::endl;
        totalMonthlyCost += itr->second;
    }

    std::cout << std::endl;
    print();
    std::cout << "Total fixed costs per month: " << totalMonthlyCost << std::endl;
    print();

    std::cout << std::endl << std::endl;

    std::map<std::string, std::vector<double>> variousCosts;

    std::string nameOfGoods {};
    std::string buyPrice_str {};
    std::stringstream buyPrice_str_toNum {};
    double buyPrice {};
    std::string quantity_str {};
    std::stringstream quantity_str_toNum {};
    double quantity {};
    std::string sellPrice_str {};
    std::stringstream sellPrice_str_toNum {};
    double sellPrice {};
    double currentResult {};

    double grossProfit {};
    double currentProfit {};
    grossProfit=totalMonthlyCost;

    std::cout << "Enter some values for goods you want to sell.\n" << std::endl;

    firstColWidth = 0;

    while(currentProfit<grossProfit)
    {
        std::cout << "Enter name of goods: ";
        getline(std::cin, nameOfGoods);
        length_nameOfCost = nameOfGoods.size();
        if(length_nameOfCost > firstColWidth) {
            firstColWidth = length_nameOfCost;
        }
        std::cout << "\nEnter buy price of " << nameOfGoods << ": ";
        getline(std::cin, buyPrice_str);
        std::stringstream buyPrice_str_toNum (buyPrice_str);
        buyPrice_str_toNum >> buyPrice;
        std::cout << "\nEnter quantity of " << nameOfGoods << ": ";
        getline(std::cin, quantity_str);
        std::stringstream quantity_str_toNum (quantity_str);
        quantity_str_toNum >> quantity;
        std::cout << "\nEnter sell price of " << nameOfGoods << ": ";
        getline(std::cin, sellPrice_str);
        std::stringstream sellPrice_str_toNum (sellPrice_str);
        sellPrice_str_toNum >> sellPrice;

        variousCosts.insert(std::pair<std::string, std::vector<double>>(nameOfGoods, {buyPrice, quantity, sellPrice}));
        currentProfit += ((sellPrice-buyPrice)*quantity);
        if(currentProfit<=grossProfit)
        {
          std::cout << "numberCh=" << numberCh << "firstColWidth=" << firstColWidth << std::endl;
          print();
          std::cout << "\n\nCurrent result is loss. Amount is " << (totalMonthlyCost-currentProfit) << " \n\nYou need more sales to make profit!\n\n" << std::endl;
          std::cout << "numberCh=" << numberCh << "firstColWidth=" << firstColWidth << std::endl;
          print();
        }
    }

    formatRow = "abc";
    numberCh = (firstColWidth + 48);

    std::cout << "numberCh=" << numberCh << "  formatRow is: " << formatRow
              << "  firstColWidth=" << firstColWidth << std::endl;
    formatRow = (numberCh, '-');
    print();

    std::cout << std::setw(firstColWidth) << std::left << "name of the goods" << std::setw(12) << std::right
              << "buy price" << std::setw(12) << std::right << "quantity" << std::setw(12)
              << std::right << "sell price" << std::setw(12) << std::right << "profit"
              << std::endl;
    print();

    for(auto itr1=variousCosts.begin(); itr1!=variousCosts.end(); itr1++)
    {
        std::cout << std::setw(firstColWidth) << std::left << itr1->first;
        for(int i=0; i<3; i++)
        {
            std::cout << std::setw(12) << std::right << itr1->second[i];
        }
        std::cout << std::setw(12) << std::right <<((itr1->second[2]-itr1->second[0])*itr1->second[1]);
        std::cout << std::endl << std::endl << std::endl;
    }

    print();
    grossProfit=currentProfit-totalMonthlyCost;
    print();
    std::cout << "Total profit is " << grossProfit << std::endl;

    return 0;
}
