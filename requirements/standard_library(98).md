# allowed headers from the standard library (```-std=c++98```)

<iomanip>
<ostream>
<streambuf>
<bitset>
<ios>
<locale>
<string>
<complex>
<iosfwd>
<typeinfo>
<iostream>
<memory>
<sstream>
<utility>
<exception>
<istream>
<new>
<valarray>
<fstream>
<numeric>
<stdexcept>
<functional>
<limits>

# the following are not allowed in c++ modules (except for STL containers in CPP08 nad CPP09)

## algorithm:
<algorithm>

## STL (Standard Template Library) containers:
<vector>
<list>
<map>
<set>
<queue>
<deque> (double ended queue)
<stack>

## iterators (designed to work with STL containers):
<iterator>
