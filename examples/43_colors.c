#include <ncurses.h>

int main()
{
	initscr();
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	attron(COLOR_PAIR(1));
	printw("Yellow text on black background\n");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(2));
	printw("Black text on green background\n");
	attroff(COLOR_PAIR(2));
	refresh();
	int ch;
	while ((ch = getch()) == KEY_RESIZE)
	{
		// KEY_RESIZE event usually appears when keyboard shows in Terminal on Android
	}
	endwin();
	return 0;
}