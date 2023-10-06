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

template <std::integral T>
void f(T) requires {}

// INTO THIS:

template <std::integral T>
void fConverted(T) {}

// ---

template<typename T>
void bar(T a) requires Foo<T> {
  a.abc();
}

template<Foo T>
void baConverted(T a) {
  a.abc();
}

// ---

// Some test code
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


