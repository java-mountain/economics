#include <iostream>
#include <string>
#include <map>
#include <vector>

int main()
{
    std::map<std::string, double> myMap;  // map for fixed costs

    std::string nameOfCost="", costString;
    double cost=0;

    while(nameOfCost !="end")         // inputing data until word "end" to stop
    {
        std::cout << "Enter name of fixed monthly cost: ";
        std::getline(std::cin, nameOfCost);     // inputing name of monthly fixed cost
         if(nameOfCost=="end"){
            goto finish;        // going out of loop if input word "end"
        } else {
        std::cout << "Enter value of " << nameOfCost << ": ";
        std::getline(std::cin, costString);     // inputing value of monthly fixed cost
        cost=stod(costString);      // parsing data from string to double
        myMap.insert(std::pair<std::string, double>(nameOfCost, cost)); // inserting data into map with fixed costs
        std::cout << std::endl;
        }
    }
    finish:  // point refer to going out of loop if entered word "end"
    std::cout << std::endl;
    std::cout << "nameOfCost" << "\t\t" << "cost" << std::endl;  // table header

    double totalMonthlyCost=0;  //declaring total monthly costs

    std::cout << "------------------------------------------------------------------------------" << std::endl; // format

    for(auto itr=myMap.begin(); itr!=myMap.end(); itr++)  // loop with iterator for making table of monthly fixed costs
    {
        std::cout << itr->first << "\t\t\t" << itr->second <<  std::endl;
        totalMonthlyCost += itr->second;
    }

    std::cout << std::endl;
    std::cout << "------------------------------------------------------------------------------\n\n" << std::endl;
    std::cout << "Total fixed costs per month: " << totalMonthlyCost << std::endl;
    std::cout << "------------------------------------------------------------------------------\n\n" << std::endl;

    std::map<std::string, std::vector<double>> variousCosts; // map for variable monthly costs

    // declaring purchaseCostStr, quantityStr, sellingPriceStr as string because of using getline
    // and then parsing them to double
    std::string nameOfGoods, purchaseCostStr, quantityStr, sellingPriceStr;

    double purchaseCost;
    double quantity;
    double sellingPrice;
    double currentResult;


    double grossProfit = 0;
    double currentProfit = 0;
    grossProfit=totalMonthlyCost;

    std::cout << "Enter some values for goods you want to sell.\n" << std::endl;

    while(currentProfit<grossProfit) // using while loop until profit going above zero
    {
        std::cout << "Enter name of goods: ";  // inputing name of goods using getline
        std::getline(std::cin, nameOfGoods);
        std::cout << "\nEnter purchase cost of " << nameOfGoods << ": ";
        std::getline(std::cin, purchaseCostStr); // inputing value as string and then parsing to double
        purchaseCost=stod(purchaseCostStr);
        std::cout << "\nEnter quantity of " << nameOfGoods << ": ";
        std::getline(std::cin, quantityStr); // inputing value as string and then parsing to double
        quantity=stod(quantityStr);
        std::cout << "\nEnter selling price of " << nameOfGoods << ": ";
        std::getline(std::cin, sellingPriceStr); // inputing value as string and then parsing to double
        sellingPrice=stod(sellingPriceStr);

        // inputing data into map - on each line - one string for name of goods and three values
        variousCosts.insert(std::pair<std::string, std::vector<double>>(nameOfGoods, {purchaseCost, quantity, sellingPrice}));
        currentProfit += ((sellingPrice-purchaseCost)*quantity);
        if(currentProfit<=grossProfit) //checking whether profit is positive
        {
          std::cout << "------------------------------------------------------------------------------" << std::endl;
          std::cout << "\n\nCurrent profit is " << (currentProfit-totalMonthlyCost) << " BGN.\n\nYou need " <<
          "more sales to increase profit!\n\n" << std::endl;
          std::cout << "------------------------------------------------------------------------------" << std::endl;
        }
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;

    // table with data of goods - one string and four double
    std::cout << "name" << "\t\t" << "purchase" << "\t\t" << "quantity" << "\t" << "selling" // table header
    << "\t\t" << "profit" << std::endl;
    std::cout << "of" << "\t\t" << "cost" << "\t\t" << "        " << "\t" << "price"
    << "\t\t" << "of these" << std::endl;
    std::cout << "goods" << "\t\t" << "    " << "\t\t" << "        " << "\t" << "    "
    << "\t\t" << "goods" << std::endl;
    std::cout << "------------------------------------------------------------------------------" << std::endl;

    for(auto itr1=variousCosts.begin(); itr1!=variousCosts.end(); itr1++) //loop with iterator for displayng data of goods
    {
        std::cout << itr1->first << "\t\t"; // displaying name of the goods
        for(int i=0; i<3; i++)  // inner loop for displaying data from vector with three data values
        {
            std::cout << itr1->second[i] << "\t\t";
        }
        std::cout << ((itr1->second[2]-itr1->second[0])*itr1->second[1]); // displaying values of vector
        std::cout << std::endl;
    }

    std::cout << "------------------------------------------------------------------------------" << std::endl;
    grossProfit=currentProfit-totalMonthlyCost; //result is grossProfit
    std::cout << "------------------------------------------------------------------------------" << std::endl;
    std::cout << "Total profit is " << grossProfit << std::endl;

    return 0;
}
