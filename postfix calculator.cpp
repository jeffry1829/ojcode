#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <optional>
#include <stack>
#include <string>
using namespace std;

bool isNumber(string& s) {
  if (s.empty()) return false;
  char* tmp;
  strtod(s.c_str(), &tmp);
  return (*tmp) == '\0';
}

vector<string> valid_operators = {"+", "-", "*", "/"};

vector<string> split_string(string s) {
  vector<string> input;
  string tmp = s;
  size_t space_idx;
  // split by spaces
  while ((space_idx = tmp.find(" ")) != string::npos) {
    string to_push = tmp.substr(0, space_idx);
    if (to_push == "" or to_push == " ") {
      tmp = tmp.substr(space_idx + 1);
      continue;
    }
    input.push_back(tmp.substr(0, space_idx));
    tmp = tmp.substr(space_idx + 1);
  }
  if (tmp != "" and tmp != " ") input.push_back(tmp);  // handle \n
  return input;
}

optional<double> calculate(string s) {
  vector<string> input = split_string(s);
  stack<double> expression_stack;
  bool break_to_next_input = false;
  for (int i = 0; i < (int)input.size(); i++) {
    if (isNumber(input[i])) {
      double number = stod(input[i]);
      // TODO: what's invalid operand?
      expression_stack.push(number);
    } else {
      string op = input[i];
      if (find(valid_operators.begin(), valid_operators.end(), op) == valid_operators.end()) {
        cout << "Invalid operator" << endl;
        break_to_next_input = true;
        break;
      }
      // no string switch in c++, I think it's more clear to just if else than assign it to number
      // Now, it's simple enough to add sqrt, pow... etc.
      // Notice that, the operand number for sqrt, pow... may not be 1, we need to take that into account
      // and fix the code
      // However, we can use some simple factory to encapsulate calculation details and make
      // the program extends easier.

      // TODO: make Operator class if time allows
      double a = 0., b = 0., result = 0.;
      if (expression_stack.size() < 2) {
        cout << "Not enough operands" << endl;
        break_to_next_input = true;
        break;
      }
      a = expression_stack.top();
      expression_stack.pop();
      b = expression_stack.top();
      expression_stack.pop();
      if (op == "+") {
        result = b + a;
      } else if (op == "-") {
        result = b - a;
      } else if (op == "*") {
        result = b * a;
      } else if (op == "/") {
        // TODO: divided by zero exception
        // now it will return inf
        result = b / a;
      } else {
        // should not happen
        cout << "This should not happen!" << endl;
        assert(false);
      }
      expression_stack.push(result);
    }
  }
  if (break_to_next_input) return nullopt;

  if (expression_stack.size() > 1) {
    cout << "Too many operands" << endl;
    return nullopt;
  }
  if ((int)expression_stack.size() < 1) {
    cout << "Empty Input" << endl;
    return nullopt;
  }
  // cout << expression_stack.top() << endl;
  double ans = expression_stack.top();
  expression_stack.pop();
  return ans;
}

void postfix_calculator() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  string inputtok = "";
  while (inputtok != "exit") {
    cout << "Please input the expression you want to calculate" << endl;
    string inputtok;
    getline(cin, inputtok);
    if (inputtok == "exit") break;

    optional<double> result = calculate(inputtok);
    if (result.has_value()) {
      cout << result.value() << endl;
    } else {
      continue;
    }
  }
}

bool test_double_eq(double a, double b, double eps = 1e-5) {
  if (fabs(a - b) < eps) {
    return true;
  } else {
    cout << "test_double_eq fail:\n";
    cout << "lhs: " << a << '\n';
    cout << "rhs: " << b << '\n';
    cout << "fabs(a - b): " << fabs(a - b) << endl;
    return false;
  }
}

void run_tests() {
  // We can test by piping stdin into this executable,
  // this way, we can easily test error message without
  // other framework or complex types

  // Or, we can test by these:
  assert(test_double_eq(calculate("  2        3 /     ").value(), 0.666667));
  assert(test_double_eq(calculate("2 3 /").value(), 0.666667));
  assert(test_double_eq(calculate("2.0 6 -").value(), -4));
  assert(test_double_eq(calculate("200.0 -5.0 *").value(), -1000));

  // Error tests:
  // Now it cannot check the error message
  assert(calculate("error").has_value() == false);
  assert(calculate("100 3 4 + 1").has_value() == false);
}

int main() {
  // comment this line or "exit" calculator to run the tests
  postfix_calculator();

  run_tests();
}