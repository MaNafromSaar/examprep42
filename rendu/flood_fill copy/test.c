#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void  real_flood_fill(char **tab, t_point size, t_point begin, char c)
{
    char    f;
    t_point cursor;

    f = 'F';
    if (begin.x >= 0 && begin.y >= 0 && begin.x < size.x && begin.y < size.y && tab[begin.y][begin.x] == c)
    {
        tab[begin.y][begin.x] = f;
        cursor = (t_point){begin.x + 1, begin.y};
        real_flood_fill(tab, size, cursor, c);
        cursor = (t_point){begin.x - 1, begin.y};
        real_flood_fill(tab, size, cursor, c);
        cursor = (t_point){begin.x, begin.y + 1};
        real_flood_fill(tab, size, cursor, c);
        cursor = (t_point){begin.x, begin.y - 1};
        real_flood_fill(tab, size, cursor, c);
    }
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char    c;


    c = tab[begin.y][begin.x];
    real_flood_fill(tab, size, begin, c);
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

// $> gcc flood_fill.c test.c -o test; ./test
// 11111111
// 10001001
// 10010001
// 10110001
// 11100001

// FFFFFFFF
// F000F00F
// F00F000F
// F0FF000F
// FFF0000F