//
// Created by magupov on 29.08.18.
//

#ifndef ELF_EXPLORER_ANALYSER_H
#define ELF_EXPLORER_ANALYSER_H

#include <string>
#include <vector>

class Analyser {
public:
    Analyser(const std::string &fileName);
    virtual ~Analyser();

    virtual std::string getHeaderList(std::vector<std::string> &headerList) = 0;

protected:
    std::string file_name;
};


#endif //ELF_EXPLORER_ANALYSER_H
