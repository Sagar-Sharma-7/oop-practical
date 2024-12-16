#include <iostream>
#include <stack>
#include <string>
using namespace std;

class BinaryAdder{
    private:
        stack<int> stack1, stack2, resultStack;

        void pushToStack(const string& binary, stack<int>& s){
            for(char bit : binary){
                s.push(bit - '0');
            }
        }
    public:
        string add(const string& binary1, const string& binary2){
            pushToStack(binary1, stack1);
            pushToStack(binary2, stack2);

            int carry = 0;

            while(!stack1.empty() || !stack2.empty() || carry != 0){
                int bit1 = 0;
                int bit2 = 0;

                if(!stack1.empty()){
                    bit1 = stack1.top();
                    stack1.pop();
                }

                if(!stack2.empty()){
                    bit2 = stack2.top();
                    stack2.pop();
                }

                int sum = bit1 + bit2 + carry;
                resultStack.push(sum % 2);
                carry = sum / 2;
            }

            string result = "";
            while(!resultStack.empty()){
                result += to_string(resultStack.top());
                resultStack.pop();
            }

            return result;

        }
};

int main(){
    string binary1 , binary2;
    BinaryAdder adder;

    cout << "Enter the first binary number: ";
    cin >> binary1;
    cout << "Enter the second binary number: ";
    cin >> binary2;

    string result = adder.add(binary1, binary2);
    cout << "The sum of the binary numbers is: " << result << endl;

    return 0;
}