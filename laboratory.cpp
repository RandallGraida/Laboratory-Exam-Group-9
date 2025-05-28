#include <iostream>
#include <string>
#include <vector>

// Encapsulated code
class fruits{
public:
  // I have used void in order to avoid unecessary returns
  void fruitsFunction(){
    std::vector<std::string> fruitsArray;
    std::string fruit;
    bool foodIsTrue = true;

    std::cout << "Enter fruits (type 'done' to finish): " << std::endl;
    while (foodIsTrue = true) {
      std::cin >> fruit;
      if (fruit == "done") break;
      fruitsArray.push_back(fruit);
    }

    // this part sorts the fruits
    std::sort(fruitsArray.begin(), fruitsArray.end());

    // longest word of the fruit
    std::string longestFruit;
    for (const auto& fruit : fruitsArray) {
      if (fruit.length() > longestFruit.length()) {
      longestFruit = fruit;
      }
    }

    // count how many fruits
    std::cout << "Number of fruits: " << fruitsArray.size() << std::endl;

    // remove the fruit you want in the list 
    std::string toRemove;
    std::cout << "Enter fruit to remove: (Name of the fruit)";
    std::cin >> toRemove;
    fruitsArray.erase(
      std::remove(fruitsArray.begin(), fruitsArray.end(), toRemove),
      fruitsArray.end()
    );

    // Output results 
    std::cout << "Sorted fruits: ";
    for (const auto& f : fruitsArray) {
      std::cout << f << " ";
    }
    std::cout << std::endl;
    std::cout << "Longest fruit: " << longestFruit << std::endl;
  }
};

int main(){
  fruits func;
  func.fruitsFunction();
}