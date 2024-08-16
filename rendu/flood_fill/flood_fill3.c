#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point begin, char c)
{
    if (begin.x < 0 || begin.y < 0 || begin.x >= size.x || begin.y >= size.y || tab[begin.y][begin.x] != c)
        return;
    tab[begin.y][begin.x] = 'F';
    fill(tab, size, (t_point){begin.x + 1, begin.y}, c);
    fill(tab, size, (t_point){begin.x - 1, begin.y}, c);
    fill(tab, size, (t_point){begin.x, begin.y + 1}, c);
    fill(tab, size, (t_point){begin.x, begin.y - 1}, c);
}


void  flood_fill(char **tab, t_point size, t_point begin)
{
    char    c;

    c = tab[begin.y][begin.x];
    fill(tab, size, begin, c);
}