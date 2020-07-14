#ifndef TYPES_HPP_
#define TYPES_HPP_

#include <string>

namespace  MalType {

  class MalType {
  public:
    enum types { SYMBOL, NUMBER, LIST };
    static MalType::types classify(std::string token);
  };

}  // namespace MalType

#endif  // TYPES_HPP_
