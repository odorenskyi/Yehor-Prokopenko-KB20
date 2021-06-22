#ifndef PRJ_11_LIB_H
#define PRJ_11_LIB_H
#include <map>
#include <string>

std::map<std::string,int> readPhoneBook(const std::string fileName = "telephone_number_code.bmtp_11");
void saveFile(std::map<std::string,int> &cityCode,const std::string fileName = "telephone_number_code.bmtp_11" );
std::map<std::string,int> search(std::string key,std::map<std::string,int> cityCode);
std::map<std::string,int> search(int value,std::map<std::string,int> cityCode);
void showPhoneBookConcole(std::map<std::string,int> mp);
void showPhoneBookFile(std::string filename, std::map<std::string,int> mp);
void removeCity(std::string key,std::map<std::string,int> &cityCode);
void removeCity(int value,std::map<std::string,int> &cityCode);
void addNewCIty(std::string key, int code,std::map<std::string, int> &cityCode);
#endif // PRJ_11_LIB_H
