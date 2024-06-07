/*
* Para a verificação de tipo ser feita de forma automatica, é necessario o cpp
* para usar o .hpp, é necessario incluir config-check.hpp no final do arquivo config.hpp
* Para ser feito a verificação do tipo.
*/

#include <type_traits>

#include "config.hpp"


static_assert(std::is_same<Scalar, float32_t>::value || std::is_same<Scalar, float64_t>::value,
	"Scalar must be float32_t or float64_t");
