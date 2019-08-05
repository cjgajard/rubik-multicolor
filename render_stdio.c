#include <stdio.h>

extern int color_For(int f, int x, int y);

int rgbTo256(int rgb)
{
	int r, g, b;
	r = (rgb >> 16 & 0xFF) * 5 / 0xFF;
	g = (rgb >> 8 & 0xFF) * 5 / 0xFF;
	b = (rgb & 0xFF) * 5 / 0xFF;
	return 36 * r + 6 * g + b + 16;
}

void print_RubikRow(int f, int i)
{
	printf("\e[48;5;%dm  ", rgbTo256(color_For(f, 0, i)));
	printf("\e[48;5;%dm  ", rgbTo256(color_For(f, 1, i)));
	printf("\e[48;5;%dm  ", rgbTo256(color_For(f, 2, i)));
}

void print_Rubik()
{
	for (int i = 0; i < 3; i++) {
		printf("      ");
		print_RubikRow(0, i);
		printf("\e[0m\n");
	}
	for (int i = 0; i < 3; i++) {
		print_RubikRow(1, i);
		print_RubikRow(2, i);
		print_RubikRow(3, i);
		print_RubikRow(4, i);
		printf("\e[0m\n");
	}
	for (int i = 0; i < 3; i++) {
		printf("      ");
		print_RubikRow(5, i);
		printf("\e[0m\n");
	}
}
