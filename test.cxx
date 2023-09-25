#include <concepts>
#include <iostream>
using namespace std;

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

  return 0;
}
