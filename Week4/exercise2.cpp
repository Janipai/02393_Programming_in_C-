#include <iostream>
#include <cmath>

using namespace std;

#define NROWS 100
#define NCOLS 100

typedef enum
{
    wood,
    stone
} material;
struct tile
{
    int x, y;
    bool isWall;
    material type;
};

void displayPlayground(int n, int m, int x_pos, int y_pos)
{
    tile playground[NROWS][NCOLS];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (n - 1) || (i == 0 && j != 3) || j == (m - 1));
            if ((playground[i][j].x == y_pos) && (playground[i][j].y == x_pos))
                cout << 'O';
            else if (playground[i][j].isWall)
            {
                cout << '*';
                playground[i][j].type = stone;
            }

            else
            {
                cout << ' ';
                playground[i][j].type = wood;
            }
        }
        cout << endl;
    }
}

int main()
{
    char dir;
    int x_pos, y_pos;
    int n, m;

    cin >> n;
    cin >> m;

    x_pos = floor(n / 2);
    y_pos = floor(m / 2);

    displayPlayground(n, m, x_pos, y_pos);

    cin >> dir;
    while (dir != 'q')
    {
        if ((dir == 'l') && (1 < y_pos) && (x_pos > 0))
            y_pos--;
        else if ((dir == 'r') && (x_pos < n - 1) && (m - y_pos > 2))
            y_pos++;
        else if ((dir == 'u') && (y_pos == 3) && (x_pos == 1))
            x_pos--;
        else if ((dir == 'u') && (1 < x_pos))
            x_pos--;
        else if ((dir == 'd') && (x_pos < n - 2))
            x_pos++;
        displayPlayground(n, m, x_pos, y_pos);
        cin >> dir;
    }
    return 0;
}