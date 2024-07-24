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
        return 0;
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