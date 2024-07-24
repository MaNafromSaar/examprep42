#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
    int x;
    int y;
} t_point;

char    get_char(char **zone, t_point size, t_point point)
{
    if (point.x < 0 || point.y < 0 || point.x >= size.x || point.y >= size.y)
        exit (1);
    return zone[point.y][point.x];
}

void    flood_fill_wrapper(char **zone, t_point size, t_point begin, char target)
{
    char c = get_char(zone, size, begin);
    if (c == 'F' || c != target)
        return;
    zone[begin.y][begin.x] = 'F';
    flood_fill_wrapper(zone, size, (t_point){begin.x + 1, begin.y}, target);
    flood_fill_wrapper(zone, size, (t_point){begin.x - 1, begin.y}, target);
    flood_fill_wrapper(zone, size, (t_point){begin.x, begin.y + 1}, target);
    flood_fill_wrapper(zone, size, (t_point){begin.x, begin.y - 1}, target);
}

void flood_fill(char **zone, t_point size, t_point begin) 
{
    char target = get_char(zone, size, begin);
    flood_fill_wrapper(zone, size, begin, target);
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
