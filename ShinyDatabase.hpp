#ifndef SHINYDATABASE_HPP
#define SHINYDATABASE_HPP

#include "Database.hpp"

class ShinyDatabase : public Database
{
public:
    ShinyDatabase(const char* dbName);
    void createTable();
    void insertData(const char* target, const int count);
    int getCount(const char* target);
};

#endif /* SHINYDATABASE_HPP */
