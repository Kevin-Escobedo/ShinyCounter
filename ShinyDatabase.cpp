#include "ShinyDatabase.hpp"

ShinyDatabase::ShinyDatabase(const char* dbName) : Database(dbName)
{

}

void ShinyDatabase::createTable()
{
    const char* command = "CREATE TABLE IF NOT EXISTS HUNTS(" \
                "TARGET TEXT PRIMARY KEY NOT NULL, "\
				"COUNT INT NOT NULL );";

	rc = sqlite3_exec(db, command, callback, nullptr, &zErrMsg);

	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL Error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
}

void ShinyDatabase::insertData(const char* target, const int count)
{
    char values[64];
	sprintf(values, "VALUES('%s', %d);", target, count);
	std::string dataValues(values);
	std::string sqlCommand = "INSERT INTO HUNTS(TARGET, COUNT) ";
	std::string tempCommand = sqlCommand + dataValues;
	const char* command = tempCommand.c_str();

	rc = sqlite3_exec(db, command, callback, nullptr, &zErrMsg);

	if(rc != SQLITE_OK)
	{
		if(strcmp(zErrMsg, "UNIQUE constraint failed: HUNTS.TARGET") == 0)
		{
			sqlite3_free(zErrMsg);
			char updateValues[64];
			sprintf(updateValues, "UPDATE HUNTS SET COUNT=%d WHERE TARGET='%s';", count, target);
			rc = sqlite3_exec(db, updateValues, callback, nullptr, &zErrMsg);

			if(rc != SQLITE_OK)
			{
				fprintf(stderr, "SQL Error: %s\n", zErrMsg);
				sqlite3_free(zErrMsg);
			}
		}

		else
		{
			fprintf(stderr, "SQL Error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
	}
}

int ShinyDatabase::getCount(const char* target)
{
    results.clear();
	char command[64];
	sprintf(command, "SELECT * FROM HUNTS WHERE TARGET='%s'", target);
	std::string tempCommand(command);
	const char* sqlCommand = tempCommand.c_str();

	rc = sqlite3_exec(db, sqlCommand, callback, nullptr, &zErrMsg);

	if(rc != SQLITE_OK)
	{
		char errMessage[32];
		sprintf(errMessage, "no such table: %s", "HUNTS");
		bool noTable = strcmp(zErrMsg, errMessage) == 0;

		if(!noTable)
		{
			fprintf(stderr, "SQL Error: %s\n", zErrMsg);
			sqlite3_free(zErrMsg);
			return 0;
		}

		sqlite3_free(zErrMsg);
		return 0;
	}

	else
	{
		std::string* data = results[0];
		const int currentCount = std::stoi(data[1]);
		delete[] data;

		return currentCount;
	}
}
