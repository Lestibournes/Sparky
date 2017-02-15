key = getch();
next_key = getch();
flushinp();
ungetch(next_key);

if (key == KEY_DOWN && next_key == KEY_LEFT) {
	x = -1;
	y = 1;
}
else if (key == KEY_DOWN && next_key == KEY_RIGHT) {
	x = 1;
	y = 1;
}
else if (key == KEY_UP && next_key == KEY_LEFT) {
	x = -1;
	y = -1;
}
else if (key == KEY_UP && next_key == KEY_RIGHT) {
	x = 1;
	y = -1;
}
else if (next_key == KEY_DOWN && key == KEY_LEFT) {
	x = -1;
	y = 1;
}
else if (next_key == KEY_DOWN && key == KEY_RIGHT) {
	x = 1;
	y = 1;
}
else if (next_key == KEY_UP && key == KEY_LEFT) {
	x = -1;
	y = -1;
}
else if (next_key == KEY_UP && key == KEY_RIGHT) {
	x = 1;
	y = -1;
}
else if (key == KEY_DOWN && next_key == ERR) {
	x = 0;
	y = 1;
}
else if (key == KEY_UP && next_key == ERR) {
	x = 0;
	y = -1;
}
else if (key == KEY_LEFT && next_key == ERR) {
	x = -1;
	y = 0;
}
else if (key == KEY_RIGHT && next_key == ERR) {
	x = 1;
	y = 0;
}

player->advance(x, y);
