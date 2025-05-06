#include <iostream>
#include <string>
#include <vector>

class StringsLibrary {
public:
    // String Library and Methods
    void stringLibraryAndMethods(std::string inputString){
        // Testing of the initial c++ working condition
        inputString = "Hello AI!";
        std::string stringOutput = inputString;

        std::cout << stringOutput << std::endl;

        // Initialize five letter 'a' characters
        std::string str5(5, 'a');
        std::cout << str5 << std::endl;

        // Assignment operator
        std::string str1 = "Hello";
        std::string str2 = "Huang";

        str1.assign(str2);
        std::cout << str1 << std::endl;

        /*
            * Concatenation Operator 
                - Adds to strings or integers 
        */ 
        std::string str3 = "Welcome";
        std::string str4 = "Huang!";
        std::string str6 = str3 + " " + str4;

        std::cout << str6 << std::endl;

        // Convert string into interger
        std::string x = "95";
        std::string y = "100";
        
        int z = stoi(x) + stoi(y);
        std::cout << z << std::endl;

        // String Length/Size 
        std::string str7 = "Nvidia";

        // The length and size do the same output
        int length1 = str7.length();
        int length2 = str7.size();

        std::cout << length1 << " " << length2 << std::endl;

        // Access string characters
        std::string str8 = "RTX 5090";

            // Display the last character or the string literal
        std::cout << str8.at(str1.size() - 1) << std::endl;
    }
    
    // String Methods/Functions
    void stringMethodsAndFunctions(std::string inputString){
        inputString = "Hello World!";

        /*
            empty() - checks string if empty
                * 0 if not empty, 1 if emptyy
        */
        std::string str1 = "Welcome";
        std::cout << str1.empty() << std::endl;

        /*
            Concatenates two strings
                * append()
        */ 
        std::string str2 = "Hello";
        std::string str3 = " AI";

        std::cout << str2.append(str3) << std::endl;
        std::cout << str2.append("Jensen Huang the GOAT!");

        /*
            Inserts characters or substrings into a string at a specific position
                * insert()
                    * For detailed insert - str4.insert(position, string, 2nd string position, position)
                    * For iterating characters - (position, number of iterations, "string to iterate")
        */ 

        std::string str4 = "Battlefield ";
        std::string str5 = "Electronic Arts Games";

        std::cout << str4.insert(12, "2042 ") << std::endl;
        std::cout << str4.insert(16, str5, 0, 21) << std::endl;
        std::cout << str4.insert(5, 5, 'C') << std::endl;

        // Replace with another string or character
        // replace() - (starting position, number of characters to remove, string)
        std::string str6 = "AI Factory";
        std::string str7 = " Future";

        std::cout << str6.replace(10, 0, str7) << std::endl;
    }
};

int main(){
    StringsLibrary func;
    func.stringMethodsAndFunctions("Initial value");
}