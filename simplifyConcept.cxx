#include <list>
#include <vector>

using namespace std;


// *******************************************
// * Standard case
// *******************************************

// BEFORE
template <typename T>
auto foo1(T param) {}

// AFTER
auto foo2(auto param) {}

// ******************************************

// BEFORE
template <std::integral Tpl>
auto f(Tpl) -> void {}

// AFTER
auto foo4(auto Tpl) -> void {}

// *******************************************
// * Aggregates
// *******************************************

// BEFORE
template <typename...ArgTypes>
auto fooVar(ArgTypes...parameters) -> void{}

// AFTER
auto fooVarTerse(auto ...parameters) -> void{}

// *******************************************
// * Type of type?
// *******************************************

// BEFORE
template<std::integral T>
auto foo5(T Tpl) -> void {}

// AFTER
auto foo6(std::integral auto T) -> void {}

// *******************************************

// BEFORE
template<std::integral T>
auto foo7(T const ** Tpl) -> void {}

// AFTER
auto foo8(std::integral auto const ** Values) -> void {}

// *******************************************
// * [Not Possible] Collections
// *******************************************

template<typename T>
auto foo9(vector<T> param) -> void {}

template<typename T>
auto foo10(list<T> param) -> void {}

template<class T, size_t N>
auto foo11(T (&a)[N], int size) -> void {}
