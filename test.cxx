#include <concepts>
#include <iostream>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;


// 1. TRANSFORM THIS:

template<typename  T>
void fConverted(T) requires std::integral<T> {}

// INTO THIS:

template<std::integral T>
void f(T) {}


// Some test code
template <typename T>
requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const &vec){
  const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
  return sum / vec.size();
}

template<typename T>
concept Foo = requires(T a) {
  { a.abc() } -> std::same_as<int>;
};

template<typename T>
void bar(T a) requires Foo<T> {
  a.abc();
}

template<Foo T>
void baz(T a) {
  a.abc();
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


