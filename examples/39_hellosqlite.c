#include <sqlite3.h>
#include <stdio.h>

int main(void)
{
	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_open(":memory:", &db);
	sqlite3_prepare_v2(db, "SELECT \"Hello, SQLite3!\"", -1, &res, NULL);
	sqlite3_step(res);
	printf("%s\n", sqlite3_column_text(res, 0));
	sqlite3_finalize(res);
	sqlite3_close(db);
	return 0;
}