#include <concepts>
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
template <std::integral T>
auto f(T param) -> void {}

// AFTER
auto foo4(std::integral auto param) -> void {}

// *******************************************
// * Aggregates
// *******************************************

// BEFORE
template <typename...T>
auto fooVar(T...params) -> void{}

// AFTER
auto fooVarTerse(auto ...params) -> void{}

// *******************************************
// * Pointer of a pointer
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
