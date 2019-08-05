
/* define */

extern void print_Rubik();

int facecolor[6] = {
	0xFFFFFF,
	0xFF8000,
	0x00FF00,
	0xFF0000,
	0x0000FF,
	0xFFFF00
};

int hrotation[6][2] = {
	{1, 3},
	{4, 2},
	{1, 3},
	{2, 4},
	{3, 1},
	{1, 3},
};

int vrotation[6][2] = {
	{4, 2},
	{0, 5},
	{0, 5},
	{0, 5},
	{0, 5},
	{2, 4},
};

/* public */

int main()
{
	print_Rubik();
	return 0;
}

/* private */

int rof(int rgb)
{
	return rgb >> 16 & 0xFF;
}

int gof(int rgb) {
	return rgb >> 8 & 0xFF;
}

int bof(int rgb)
{
	return rgb & 0xFF;
}

int mix2(int c1, int c2)
{
	int r = (3 * rof(c1) + rof(c2)) / 4;
	int g = (3 * gof(c1) + gof(c2)) / 4;
	int b = (3 * bof(c1) + bof(c2)) / 4;
	return (r << 16 & 0xFF0000) + (g << 8 & 0xFF00) + b;
}

int mix3(int c1, int c2, int c3)
{
	int r = (3 * rof(c1) + rof(c2) + rof(c3)) / 5;
	int g = (3 * gof(c1) + gof(c2) + gof(c3)) / 5;
	int b = (3 * bof(c1) + bof(c2) + bof(c3)) / 5;
	return (r << 16 & 0xFF0000) + (g << 8 & 0xFF00) + b;
}

int color_For(int f, int x, int y)
{
	int rgb;
	if (x == 1 && y == 1) {
		rgb = facecolor[f];
	}
	else if (x == 1 || y == 1) {
		int f2;
		if (x == 1) {
			f2 = vrotation[f][y / 2];
		} else {
			f2 = hrotation[f][x / 2];
		}
		rgb = mix2(facecolor[f], facecolor[f2]);
	}
	else {
		int f2 = vrotation[f][y / 2];
		int f3 = hrotation[f][x / 2];
		rgb = mix3(facecolor[f], facecolor[f2], facecolor[f3]);
	}
	return rgb;
}
