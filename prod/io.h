#ifndef PROD_IO_H
#define PROD_IO_H

#include <string>
#include <vector>

class IO {
public:
    static void Input(std::vector<std::string> &in);
    static void InputFromFile(std::vector<std::string> &in);
    static void Output(std::vector<std::string> &out);
    static void ToDelete(std::vector<std::string> &d);
    static void Change(std::vector<std::string> &d);
};


#endif //PROD_IO_H