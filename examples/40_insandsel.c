#include <sqlite3.h>
#include <stdio.h>

int main()
{
	sqlite3 *db;
	sqlite3_stmt *res;
	sqlite3_open(":memory:", &db);
	sqlite3_exec(db, "CREATE TABLE strings(s TEXT)", 0, 0, 0);
	for (int i = 0; i < 10; i++)
	{
		char tmp[1024];
		sprintf(tmp, "INSERT INTO strings VALUES ('string%d')", i);
		sqlite3_exec(db, tmp, 0, 0, 0);
	}
	sqlite3_prepare_v2(db, "SELECT * FROM strings", -1, &res, NULL);
	printf("Database contents:\n");
	int rc = sqlite3_step(res);
	while (rc != SQLITE_DONE)
	{
		printf("%s\n", sqlite3_column_text(res, 0));
		rc = sqlite3_step(res);
	}
	sqlite3_finalize(res);
	sqlite3_close(db);
	return 0;
}