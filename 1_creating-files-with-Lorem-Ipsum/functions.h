#ifndef CREATING_FILES_WITH_LOREM_IPSUM__FUNCTIONS_H_
#define CREATING_FILES_WITH_LOREM_IPSUM__FUNCTIONS_H_

#include <cpr/cpr.h>
#include <map>

cpr::Response postLipsum(std::map<std::string, std::string>& arguments);

std::string parsTextXML(cpr::Response text);

bool saveText(std::string path, std::string text,  std::string idFile);

void incrementId(std::string& idFile);

#endif //CREATING_FILES_WITH_LOREM_IPSUM__FUNCTIONS_H_
