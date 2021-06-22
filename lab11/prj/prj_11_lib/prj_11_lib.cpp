#include "prj_11_lib.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>


std::map<std::string, int> readPhoneBook(const std::string fileName)
{
    std::map <std::string,int> mp;
    std::ifstream file(fileName);
    if (file.is_open()){
        std::string str ="";
        while(std::getline(file,str)){
            bool flag = false;
            std::string key ="", code = "";
            if(str.length()>6){
                for (int i = 0; i < int(str.length()); i++){


                    if(!flag && str[i] == '{'){
                        flag = true;
                        key.erase(key.length()-1,1);
                        continue;
                    }
                    if(flag){
                        if(str[i]=='}'){
                            break;
                        }
                        code+=str[i];
                    }else{
                        key+=str[i];
                    }

                }
                mp[key] = std::stoi(code);
            }
        }
        file.close();
    }


    return  mp;
}

void saveFile(std::map<std::string, int> &cityCode, const std::string fileName)
{
    std::ofstream file(fileName);
    if(file.is_open()){
        for (auto it=cityCode.begin(); it != cityCode.end(); it++)
        {
            file << it->first << " {" << it->second << "}"<< std::endl;
        }
        file.close();
    }
}

std::map<std::string, int> search(std::string key, std::map<std::string, int> cityCode)
{
    std::map<std::string, int> returnMap;
    for (auto it=cityCode.begin(); it != cityCode.end(); it++)
    {

        if(it->first.find(key) != std::string::npos){
            returnMap[it->first] = it->second;
        }
    }
    return returnMap;

}

std::map<std::string, int> search(int value, std::map<std::string, int> cityCode)
{
    std::map<std::string, int> returnMap;
    for (auto it=cityCode.begin(); it != cityCode.end(); it++)
    {
        if(it->second == value){
            returnMap[it->first] = it->second;
        }
    }
    return returnMap;
}
void showPhoneBookConcole(std::map<std::string,int> mp)
{

    std::cout <<std::left << std::setw( 55 ) << "МІСТО"  << std::setw( 5 ) << "КОД" << std::endl;
    std::cout << "_____________________________________________________________" << std::endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        std::cout <<std::left << std::setw( 55 ) << std::left << it->first <<  std::setw( 5 ) << it->second << std::endl;
        std::cout << "_____________________________________________________________" << std::endl;
    }

}

void showPhoneBookFile(std::string filename, std::map<std::string,int> mp)
{
    std::ofstream infile(filename);
    if (infile.is_open()){

        infile <<std::left << std::setw( 55 ) << "МІСТО"  << std::setw(5) << "КОД" << std::endl; ;
        infile << "_____________________________________________________________" << std::endl;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            infile <<std::left << std::setw( 55 ) << std::left << it->first  << std::setw( 5 ) << it->second  << std::endl;;
            infile << "_____________________________________________________________" << std::endl;
        }
        infile.close();
    }

}


void removeCity(std::string key, std::map<std::string, int> &cityCode)
{
    if (cityCode.count(key)>0){
        std::cout << "Записи знайдено. Триває видалення...\n"<<std::endl;
        while (cityCode.count(key)>0){

            cityCode.erase(key);
        }
    }else{
        std::cout << "Нажаль у телефонній книжці намає такого запису :( \n"<<std::endl;
    }
}
void addNewCIty(std::string key, int code,std::map<std::string, int> &cityCode){

    if (cityCode.count(key)>0){
        std::cout << "Такий запис вже існує у телефонній книжці!" << std::endl;
        cityCode.find(key);
    }else{

        cityCode[key] = code;
        std::cout << "Запис був успішно доданій у телефону книгу!" <<std::endl;
    }

}


void removeCity(int value, std::map<std::string, int> &cityCode)
{
    bool flag = true;
    for (auto it=cityCode.begin(); it != cityCode.end(); it++)
    {
        if(it->second == value){
            cityCode.erase(it);
            flag = false;
        }

    }
    if(flag){
        std::cout << "Нажаль у телефонній книжці намає такого запису :( \n"<<std::endl;
    }else{

        std::cout << "Записи знайдено. Триває видалення...\n"<<std::endl;
        std::cout << "Записи успішно видалено!!!\n"<<std::endl;

    }
}
