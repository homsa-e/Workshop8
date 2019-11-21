#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

// parse csv example (from the previous Workshop problem)

int main (int argc, char **argv)
{
  if (argc != 3)
  {
      return 0;
  }
  std::ifstream in (argv[1]);
  std::string line;
  size_t column_number = static_cast<size_t> (atoi (argv[2]));

  std::map <std::string, int> frequencies;
  while (!in.eof() && in.good ())
  {
    std::getline (in, line);
    std::cout << line << std::endl;

    std::vector<std::string> tokens;
    std::stringstream ss(line);
    std::string token;
    while (!ss.eof () && ss.good ())
    {
        std::getline (ss, token, ',');
        std::cout << token << std::endl;
        tokens.push_back (token);
    }

    if (column_number >= tokens.size ())
        continue;

    if (frequencies.find (tokens[column_number]) != frequencies.end ())
    {
        frequencies[tokens[column_number]] += 1;
    }
    else
    {
        frequencies[tokens[column_number]] = 0;
    }
  }

  return 0;

}
