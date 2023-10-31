#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <limits>
#include <cmath> // Include for exponentiation

typedef std::vector<std::string> Tokens;

// Define a mapping of operator strings to corresponding functions
std::unordered_map<std::string, std::function<int(std::vector<int>)>> customOperators = {
        {"+", [](std::vector<int> operands) {
            int result = 0;
            for (int operand : operands) {
                result += operand;
            }
            return result;
        }},
        {"*", [](std::vector<int> operands) {
            int result = 1;
            for (int operand : operands) {
                result *= operand;
            }
            return result;
        }},
        {"-", [](std::vector<int> operands) {
            if (operands.size() < 2) {
                return 0; // Handle the case where there are not enough operands
            }
            int result = operands[0];
            for (size_t i = 1; i < operands.size(); ++i) {
                result -= operands[i];
            }
            return result;
        }},
        {"/", [](std::vector<int> operands) {
            if (operands.size() < 2) {
                return 0; // Handle the case where there are not enough operands
            }
            int result = operands[0];
            for (size_t i = 1; i < operands.size(); ++i) {
                result /= operands[i];
            }
            return result;
        }},
        {"^", [](std::vector<int> operands) {
            if (operands.size() < 2) {
                return 0; // Handle the case where there are not enough operands
            }
            int result = std::pow(operands[0], operands[1]);
            return result;
        }},
        {"%", [](std::vector<int> operands) {
            if (operands.size() < 2) {
                return 0; // Handle the case where there are not enough operands
            }
            int result = operands[0] % operands[1];
            return result;
        }},
        // Add more custom operators here
};

Tokens tokenize(const std::string& input) {
    Tokens tokens;
    std::string token;
    std::istringstream stream(input);

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

int evaluate(Tokens& tokens) {
    std::stack<int> stack;

    for (const std::string& token : tokens) {
        if (customOperators.find(token) != customOperators.end()) {
            std::vector<int> operands;
            while (!stack.empty()) {
                operands.push_back(stack.top());
                stack.pop();
            }
            std::reverse(operands.begin(), operands.end());
            int result = customOperators[token](operands);
            stack.push(result);
        } else {
            stack.push(std::stoi(token));
        }
    }

    return stack.top();
}

int main() {
    std::string input;
    std::getline(std::cin, input);
    Tokens tokens = tokenize(input);
    std::cout << evaluate(tokens) << std::endl;
    return 0;
}
