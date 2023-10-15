#include <ncurses.h>
#include <string>
#include <iostream>

// printw(string);        			/* Print on stdscr at present cursor position */
// mvprintw(y, x, string);			/* Move to (y, x) then print string */
// wprintw(win, string);  			/* Print on window win at present cursor position in the window */
// mvwprintw(win, y, x, string);  	/* Move to (y, x) relative to window co-ordinates and then print */

			// CLASSES OF OUTPUT FUNCTIONS //
// addch() class: 		Print single character with attributes
// printw() class: 		Print formatted output similar to printf()
// addstr() class: 		Print strings

			// CLASSES OF INPUT FUNCTIONS //
// getch() class: 		Get a character
// scanw() class: 		Get formatted input
// getstr() class: 		Get strings

void hello_world(){

    initscr();

    move(0, 0);
    printw("Hello World");

    move(1, 1);
    printw("This text has moved :)");

    refresh();

    getch();

    move(5, 5);
    printw("I'm here now");

    refresh();

    getch();

    endwin();
}

void init_test(){
    int ch;

	initscr();			/* Start curses mode 		*/
	raw();				/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();			/* Don't echo() while we do getch */

    	printw("Type any character to see it in bold\n");
	ch = getch();			/* If raw() hadn't been called
					 * we have to press enter before it
					 * gets to the program 		*/
	if(ch == KEY_F(1))		/* Without keypad enabled this will */
		printw("F1 Key pressed");/*  not get to us either	*/
					/* Without noecho() some ugly escape
					 * charachters might have been printed
					 * on screen			*/
	else
	{	printw("The pressed key is ");
		attron(A_BOLD);
		printw("%c", ch);
		attroff(A_BOLD);
	}
	refresh();			/* Print it on to the real screen */
    	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */
}

void scanf_test(){
	std::string mesg = "Enter a string: ";		/* message to be appeared on the screen */
	char str[80];
	int row, col;				/* to store the number of rows and *
					* the number of colums of the screen */
	initscr();				/* start the curses mode */
	getmaxyx(stdscr, row, col);		/* get the number of rows and columns */
	mvprintw(row/2, (col-mesg.length())/2, "%s", mesg.c_str());
							/* print the message at the center of the screen */
	getstr(str);
	mvprintw(LINES - 2, 0, "You Entered: %s", str);
	getch();
	endwin();
}

void window_test(){
	initscr();

	WINDOW *win1;

	win1 = newwin(6, 20, 1, 1);

	refresh();

	box(win1, 0, 0);

	wrefresh(win1);

	getch();

	endwin();
}

int main(){

	// Change this to the desired test function
    //window_test();

	initscr();

	char ch;

	while (ch != 't'){
		ch = getch();
		if (ch == 'p'){
			endwin();
			std::cout << "the program exited in while loop" << std::endl;
			return 0;
		}
	}

	endwin();

	std::cout << "the program exited out of while loop" << std::endl;
	return 0;
}