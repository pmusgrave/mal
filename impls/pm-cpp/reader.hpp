#ifndef READER_HPP_
#define READER_HPP_

#include <string>
#include <vector>

namespace Reader {

class Reader {
public:
  Reader(std::vector<std::string>);
  ~Reader();
  std::string next();
  std::string peek();

private:
  std::vector<std::string> tokens;
  int position;
};

}  // namespace Reader

#endif  // READER_HPP_
