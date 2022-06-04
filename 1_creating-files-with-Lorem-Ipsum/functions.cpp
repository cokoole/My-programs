#include <iostream>
#include <algorithm>
#include <filesystem>
//
#include "functions.h"

cpr::Response postLipsum(std::map<std::string, std::string>& arguments) {
  cpr::Response response;
  std::vector<cpr::Pair> post_arr;

  for (auto it = arguments.begin(); it != arguments.end(); it++) {
    post_arr.emplace_back(it->first, it->second);
  }

  response = cpr::Post(cpr::Url("http://lipsum.com/feed/xml"),
                       cpr::Payload(post_arr.begin(), post_arr.end())
  );

  return response;
}

std::string parsTextXML(cpr::Response response) {
  std::string result = "";

  int start = response.text.find("<lipsum>") + 8;
  int finish = response.text.find("</lipsum>");

  for (int i = start; i < finish; ++i) {
    result += response.text[i];
  }

  std::transform(result.begin(), result.end(), result.begin(), ::tolower);

  for (auto& it: result)
    if (it == '.' || it == ',' || it == '\n')
      it = ' ';

  return result;
}

bool saveText(std::string path, std::string text, std::string idFile) {
  std::filesystem::path dir_path(path);

  if (std::filesystem::is_regular_file(path)) {
    std::cout << "Invalid path\n";
    return false;
  }

  std::filesystem::create_directories(dir_path);


  std::ofstream file(path + "/file" + idFile + ".txt");

  if (file.is_open()) {
    file << text;
    file.close();
  }

  return true;
}

void incrementId(std::string& idFile) {
  for (int i = idFile.size() -1; i > 0; --i) {
    if (++idFile[i] <= '9') {
      break;
    }
    idFile[i] = '0';
  }
}