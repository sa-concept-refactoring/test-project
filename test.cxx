#include <concepts>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

template<typename T>
concept Foo = requires(T a) {
  { a.abc() } -> std::same_as<int>;
};

// ---

// 1. TRANSFORM THIS:
template <typename T>
void f(T) requires std::integral<T> 
{}

// INTO THIS:
// template <std::integral T>
// void f(T) {}

// ---

// 2. TRANSFORM THIS:
template<typename T> 
requires std::integral<T>
void f(T) {}

// INTO THIS:
// void f(std::integral<T> auto x) {}

// ---

// 3. TRANSFORM THIS:
template<typename T>
void bar(T a) requires Foo<T> {
  a.abc();
}

// INTO THIS:
// template<Foo T>
// void bar(T a) {
//   a.abc();
// }

// ---

// Example with multiple requires clauses => no conversion possible
template <typename T>
requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const &vec){
  const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
  return sum / vec.size();
}

int main() {
  int number;

  cout << "Enter an integer: ";
  cin >> number;

  if (number > 5) {
    cout << "Foo ";
  } else {
    cout << "Bar ";
  }

  cout << "You entered " << number;

  cout << "Enter some integers to calculate the average (stop input by typing any char):";
  std::vector<int> ints;
  while (cin >> number)
    ints.push_back(number);

  cout << "Your average: " << Average(ints);

  return 0;
}


