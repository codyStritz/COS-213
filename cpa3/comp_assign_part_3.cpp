// Cody Stritz
// Comprehensive Programming Assignment
// Problem 3
// 2022FEB
// C++ Programming
// COS-213 

#include <iostream> 
#include <iomanip> 
using namespace std;

// Represents a revenue stream with a demand, price, and calculated value
class Revenue {
  private:     
    int demand;
    int price;
  
  public:
    Revenue(int demand, int price)      // Constructor
      : demand(demand), price(price) {}

    int RevenueValue() {      // Calculates & returns revenue value
      return demand * price;
    }
  
    int GetDemand() {   // Getters for private data members
      return demand;
    }
    int GetPrice() {
      return price;
    }
};

// Begins program execution
int main()
{
  Revenue revenue = Revenue(2000, 2);   // Instantiate Revenue

  // Print formatted statment with revenue price, demand, and value
  printf("The Revenue Value for the current income source with a price of "
         "%d and a market value demand of %d is currently %d.\n", 
         revenue.GetPrice(), revenue.GetDemand(), revenue.RevenueValue());

  system("pause");  // Pause command window
  return 0;
}
