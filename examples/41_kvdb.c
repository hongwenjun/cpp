#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

int main()
{
	sqlite3 *db;
	sqlite3_open(":memory:", &db);
	sqlite3_exec(db, "CREATE TABLE kvdb(id TEXT PRIMARY KEY,val TEXT)", 0, 0, 0);
	printf("Welcome to the simplest key-value database\n");
	while (1)
	{
		char tmp[1024];
		printf("What do you want to do?\n");
		printf("Enter P to [P]ut, G to [G]et or L to [L]ist\n");
		printf("Or enter Q to [Q]uit\n");
		gets(tmp);
		if (!strcmp(tmp, "P"))
		{
			char key[1024];
			char data[1024];
			printf("Enter key: ");
			gets(key);
			printf("Enter data: ");
			gets(data);
			sqlite3_stmt *ins;
			sqlite3_prepare_v2(db, "INSERT OR REPLACE INTO kvdb VALUES (?,?)", -1, &ins, NULL);
			sqlite3_bind_text(ins, 1, key, -1, SQLITE_STATIC);
			sqlite3_bind_text(ins, 2, data, -1, SQLITE_STATIC);
			sqlite3_step(ins);
			sqlite3_finalize(ins);
			continue;
		}
		if (!strcmp(tmp, "G"))
		{
			char key[1024];
			printf("Enter key: ");
			gets(key);
			sqlite3_stmt *res;
			sqlite3_prepare_v2(db, "SELECT val FROM kvdb WHERE id=?", -1, &res, NULL);
			sqlite3_bind_text(res, 1, key, -1, SQLITE_STATIC);
			int rc = sqlite3_step(res);
			if (rc != SQLITE_DONE)
			{
				printf("Your data: %s\n", sqlite3_column_text(res, 0));
			}
			else
				printf("No such key\n");
			sqlite3_finalize(res);
			continue;
		}
		if (!strcmp(tmp, "L"))
		{
			sqlite3_stmt *res;
			sqlite3_prepare_v2(db, "SELECT * FROM kvdb", -1, &res, NULL);
			printf("DB contents:\n");
			int rc = sqlite3_step(res);
			while (rc != SQLITE_DONE)
			{
				printf("%s: %s\n", sqlite3_column_text(res, 0), sqlite3_column_text(res, 1));
				rc = sqlite3_step(res);
			}
			sqlite3_finalize(res);
			continue;
		}
		if (!strcmp(tmp, "Q"))
		{
			printf("Bye\n");
			break;
		}
	}
	sqlite3_close(db);
	return 0;
}