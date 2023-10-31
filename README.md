# tinylisp

else if (token == "min") {
                int result = std::numeric_limits<int>::max();

                while (!stack.empty()) {
                    int value = stack.top();
                    stack.pop();
                    result = std::min(result, value);
                }

                stack.push(result);
            } else if (token == "max") {
                int result = std::numeric_limits<int>::min();

                while (!stack.empty()) {
                    int value = stack.top();
                    stack.pop();
                    result = std::max(result, value);
                }

                stack.push(result);
