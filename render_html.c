#include <stdio.h>

extern int color_For(int f, int x, int y);

void print_Cell(int rgb)
{
	printf("<td style=\"background-color:#%06x;\"></td>", rgb);
}

void print_RubikRow(int f, int i)
{
	print_Cell(color_For(f, 0, i));
	print_Cell(color_For(f, 1, i));
	print_Cell(color_For(f, 2, i));
}

void print_Rubik()
{
	printf("<!DOCTYPE html><html><head><style>\
body{background-color:#000;}td{width:20px;height:20px;}</style></head>\
<body><table><tbody>");
	for (int i = 0; i < 3; i++) {
		printf("<tr>");
		printf("<td colspan=\"3\"></td>");
		print_RubikRow(0, i);
		printf("</tr>");
	}
	for (int i = 0; i < 3; i++) {
		printf("<tr>");
		print_RubikRow(1, i);
		print_RubikRow(2, i);
		print_RubikRow(3, i);
		print_RubikRow(4, i);
		printf("</tr>");
	}
	for (int i = 0; i < 3; i++) {
		printf("<tr>");
		printf("<td colspan=\"3\"></td>");
		print_RubikRow(5, i);
		printf("</tr>");
	}
	printf("</tbody></table></body></html>");
}
