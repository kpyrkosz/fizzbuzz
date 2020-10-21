#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static void
var4(int i, std::ostream& o)
{
  std::string result;
  if (i % 3 == 0)
    result += "Fizz";
  if (i % 5 == 0)
    result += "Buzz";
  if (result.empty())
    o << i << '\n';
  else
    o << result << '\n';
}

static void
var3(int i, std::ostream& o)
{
  if (i % 15 == 0)
    o << "FizzBuzz\n";
  else if (i % 5 == 0)
    o << "Buzz\n";
  else if (i % 3 == 0)
    o << "Fizz\n";
  else
    o << i << '\n';
}

static void
var2(int i, std::ostream& o)
{
  char bitmask = 0;
  if (i % 3 == 0)
    bitmask |= 1;
  if (i % 5 == 0)
    bitmask |= 2;
  switch (bitmask)
  {
    case 0:
      o << i << '\n';
      break;
    case 1:
      o << "Fizz\n";
      break;
    case 2:
      o << "Buzz\n";
      break;
    case 3:
      o << "FizzBuzz\n";
      break;
  }
}

static void
var1(int i, std::ostream& o)
{
  bool found = false;
  if (i % 3 == 0)
  {
    found = true;
    o << "Fizz";
  }
  if (i % 5 == 0)
  {
    found = true;
    o << "Buzz";
  }
  if (!found)
    o << i;
  o << '\n';
}

#define run_variant(variant_id)                                                                    \
  []() -> std::string {                                                                            \
    std::stringstream ss;                                                                          \
    for (int i = 1; i <= 100; ++i)                                                                 \
      var##variant_id(i, ss);                                                                      \
    return ss.str();                                                                               \
  }()

int
main()
{
  std::vector<std::string> results{run_variant(1), run_variant(2), run_variant(3), run_variant(4)};
  return !std::all_of(
    begin(results), end(results), [&results](const auto& elem) { return elem == results.front(); });
}