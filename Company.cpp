#include <iostream>
#include <string>
#include <map>
#include <vector>

//using namespace std;

int main()
{
    std::map<std::string, double> myMap;

    std::string nameOfCost="";
    double cost=0;

    while(nameOfCost !="end")
    {
        std::cout << "Enter name of fixed monthly cost: ";
        std::cin >> nameOfCost;
        if(nameOfCost=="end"){
            goto finish;
        } else {
        std::cout << "Enter value of " << nameOfCost << ": ";
        std::cin >> cost;
        myMap.insert(std::pair<std::string, double>(nameOfCost, cost));
        }
    }
    finish:
    std::cout << std::endl;
    std::cout << "nameOfCost" << "\t\t" << "cost" << std::endl;

    double totalMonthlyCost=0;

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    for(auto itr=myMap.begin(); itr!=myMap.end(); itr++)
    {
        std::cout << itr->first << "\t\t\t" << itr->second <<  std::endl;
        totalMonthlyCost += itr->second;
    }

    std::cout << std::endl;
    std::cout << "------------------------------------------------------------------------------\n\n" << std::endl;
    std::cout << "Total fixed costs per month: " << totalMonthlyCost << std::endl;
    std::cout << "------------------------------------------------------------------------------\n\n" << std::endl;

    std::map<std::string, std::vector<double>> variousCosts;

    std::string nameOfGoods;
    double buyPrice;
    double quantity;
    double sellPrice;
    double currentResult;


    double grossProfit = 0;
    double currentProfit = 0;
    grossProfit=totalMonthlyCost;

    std::cout << "Enter some values for goods you want to sell.\n" << std::endl;

    while(currentProfit<grossProfit)
    {
        std::cout << "Enter name of goods: ";
        std::cin >> nameOfGoods;
        std::cout << "\nEnter buy price of " << nameOfGoods << ": ";
        std::cin >> buyPrice;
        std::cout << "\nEnter quantity of " << nameOfGoods << ": ";
        std::cin >> quantity;
        std::cout << "\nEnter sell price of " << nameOfGoods << ": ";
        std::cin >> sellPrice;

        variousCosts.insert(std::pair<std::string, std::vector<double>>(nameOfGoods, {buyPrice, quantity, sellPrice}));
        currentProfit += ((sellPrice-buyPrice)*quantity);
        if(currentProfit<=grossProfit)
        {
          std::cout << "------------------------------------------------------------------------------" << std::endl;
          std::cout << "\n\nCurrent result is loss. Amount is " << (totalMonthlyCost-currentProfit) << " \n\nYou need more sales to make profit!\n\n" << std::endl;
          std::cout << "------------------------------------------------------------------------------" << std::endl;
        }
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    std::cout << "name" << "\t\t" << "buy" << "\t\t" << "quantity" << "\t" << "sell"
    << "\t\t" << "profit" << std::endl;
    std::cout << "of" << "\t\t" << "Price" << "\t\t" << "        " << "\t" << "Price"
    << "\t\t" << "of these" << std::endl;
    std::cout << "goods" << "\t\t" << "    " << "\t\t" << "        " << "\t" << "    "
    << "\t\t" << "goods" << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    for(auto itr1=variousCosts.begin(); itr1!=variousCosts.end(); itr1++)
    {
        std::cout << itr1->first << "\t\t";
        for(int i=0; i<3; i++)
        {
            std::cout << itr1->second[i] << "\t\t";
        }
        std::cout << ((itr1->second[2]-itr1->second[0])*itr1->second[1]);
        std::cout << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    grossProfit=currentProfit-totalMonthlyCost;
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "Total profit is " << grossProfit << std::endl;

    return 0;
}
