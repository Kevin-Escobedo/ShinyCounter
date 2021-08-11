#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <stdio.h>
#include <sqlite3.h>
#include <ctime>
#include <vector>
#include <string.h>

class Database
{
protected:
    sqlite3* db;
    int rc;
    char* zErrMsg = nullptr;
    bool isOpen = false;
    inline static std::vector<std::string*> results;

public:
    Database(const char* databaseName);
    Database(const Database& d);
    Database& operator =(const Database& d);
    ~Database();
    int length(const char* tableName);
    void clearMemory();
    void close();

protected:
    static int callback(void* NotUsed, int argc, char** argv, char** azColName);
    const char* currentTime();
};

#endif /* DATABASE_HPP */
