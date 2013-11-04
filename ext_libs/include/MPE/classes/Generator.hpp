#ifndef GENERATOR_TL9DCTRC
#define GENERATOR_TL9DCTRC

#include <random>
#include <functional>
#include <MPE/Config.hpp>

namespace mpe
{

template<typename T>
class Generator
{
public:
   Generator();
   Generator(T theNumber);
   Generator(T theMin, T theMax);
   T operator()() const;

   static Generator<T> create(T theMin,T theMax);

private:
   std::function<T()> mGenerator;
};
} /* mpe */

#endif /* end of include guard: GENERATOR_TL9DCTRC */
