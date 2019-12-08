#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

int main (int argc, char **argv)
{
  for (int i = 0; i < argc; ++i)
  {
      //out << argv[i] << std::endl;
  }

  if (argc > 3){
      std::cout << "Too many arguments" << std::endl;
      return 0;
  }
  std::ifstream in (argv[1]);
  std::string line;
  //std::ofstream out (argv[2]);
  //size_t k = 0;
  size_t column = std::stoi(argv[2]), i = 0;
  std::vector<std::vector <std::string> > tokens(12);
  std::map <std::string, unsigned short> freq;
  std::map <std::string, unsigned short> ::iterator it;
  std::map <unsigned short, std::vector <std::string> > ans;
  std::map <unsigned short, std::vector <std::string> > :: iterator it1;
  std::getline(in, line);
  while (!in.eof() && in.good ())
  {
    std::getline (in, line);
    std::stringstream ss(line);
    std::string token;
    //out << line << std::endl;
    while (!ss.eof () && ss.good ())
    {
        std::getline (ss, token, ',');
        tokens[i].push_back(token);
        i = (i + 1) % 12;
    }
  }
  std::vector <std::string> &x = tokens[column];
  for (i = 0; i < x.size(); i++)
  {
      if (freq.count(x[i]) > 0)
          freq[x[i]]++;
      else
          freq[x[i]] = 1;
  }
  for (it = freq.begin(); it != freq.end(); ++it){
      if (ans.find(it->second) != ans.end()){
          ans[it->second].push_back(it->first);
      }
      else
          ans[it->second] = {it->first};
  }
  it1 = ans.end();
  --it1;
  for (it1; it1 != ans.begin(); --it1)
  {
      std::vector <std::string> &y = it1->second;
      for (std::string val : y){
          std::cout << val << ':' << it1->first << std::endl;
      }
  }
  it1 = ans.begin();
  std::vector <std::string> &y = it1->second;
  for (std::string val : y){
      std::cout << val << ':' << it1->first << std::endl;
  }
}
