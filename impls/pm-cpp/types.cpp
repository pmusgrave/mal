#include "types.hpp"

#include <string>

namespace MalType {

MalType::types MalType::classify(std::string token) {
  return MalType::SYMBOL;
}

}  // namespace MalType
