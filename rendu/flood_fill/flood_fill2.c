#include "flood_fill.h"

void    fill(char **tab, t_point size, t_point begin, char c)
{
    t_point cur;

    cur.x = begin.x;
    cur.y = begin.y;

    if(cur.y < 0 || cur.x < 0 || cur.x >= size.x || cur.y >= size.y || tab[cur.y][cur.x] != c)
        return;
    tab[cur.y][cur.x] = 'F';
    fill(tab, size, (t_point){cur.x+1, cur.y}, c);
    fill(tab, size, (t_point){cur.x-1, cur.y}, c);
    fill(tab, size, (t_point){cur.x, cur.y+1}, c);
    fill(tab, size, (t_point){cur.x, cur.y-1}, c);
        
    


}


void  flood_fill(char **tab, t_point size, t_point begin)
{
    char    c;

    c = tab[begin.y][begin.x];
    fill(tab, size, begin, c);
}