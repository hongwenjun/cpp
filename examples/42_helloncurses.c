#include <ncurses.h>

int main()
{
	initscr();
	printw("Hello, ncurses!\n");
	refresh();
	int ch;
	while ((ch = getch()) == KEY_RESIZE)
	{
		// KEY_RESIZE event usually appears when keyboard shows in Terminal on Android
	}
	endwin();
	return 0;
}