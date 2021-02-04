#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

void print();

void print() {
    std::cout << "------------------------------------------------------------------------------" << std::endl;
}


int main()
{
    std::map<std::string, double> myMap;

    std::string nameOfCost {};
    std::string cost_str {};
    std::stringstream str_to_num {};
    double cost {};

    while(nameOfCost !="end")
    {
        std::cout << "Enter name of fixed monthly cost: ";
        getline(std::cin,nameOfCost);
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
    std::cout << "nameOfCost" << "\t\t" << "cost" << std::endl;

    double totalMonthlyCost {};

    print();

    for(auto itr=myMap.begin(); itr!=myMap.end(); itr++)
    {
        std::cout << itr->first << "\t\t\t" << itr->second <<  std::endl;
        totalMonthlyCost += itr->second;
    }

    std::cout << std::endl;
    print();
    std::cout << "Total fixed costs per month: " << totalMonthlyCost << std::endl;
    print();

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

    while(currentProfit<grossProfit)
    {
        std::cout << "Enter name of goods: ";
        getline(std::cin, nameOfGoods);
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
          print();
          std::cout << "\n\nCurrent result is loss. Amount is " << (totalMonthlyCost-currentProfit) << " \n\nYou need more sales to make profit!\n\n" << std::endl;
          print();
        }
    }

    print();

    std::cout << std::setw(35) << std::left << "name of the goods" << std::setw(12) << std::right
              << "buy price" << std::setw(12) << std::right << "quantity" << std::setw(12)
              << std::right << "sell price" << std::setw(12) << std::right << "profit"
              << std::endl;
//    std::cout << "of" << "\t\t" << "Price" << "\t\t" << "        " << "\t" << "Price"
//    << "\t\t" << "of these" << std::endl;
//    std::cout << "goods" << "\t\t" << "    " << "\t\t" << "        " << "\t" << "    "
//    << "\t\t" << "goods" << std::endl;
    print();

    for(auto itr1=variousCosts.begin(); itr1!=variousCosts.end(); itr1++)
    {
        std::cout << std::setw(35) << std::left << itr1->first;
        for(int i=0; i<3; i++)
        {
            std::cout << std::setw(12) << std::right << itr1->second[i];
        }
        std::cout << std::setw(12) << std::right <<((itr1->second[2]-itr1->second[0])*itr1->second[1]);
        std::cout << std::endl;
    }

    print();
    grossProfit=currentProfit-totalMonthlyCost;
    print();
    std::cout << "Total profit is " << grossProfit << std::endl;

    return 0;
}
