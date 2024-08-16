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
