#include <iostream>

using namespace std;

#define NROWS 12
#define NCOLS 16

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

void displayPlayground(int x_pos, int y_pos)
{
    tile playground[NROWS][NCOLS];

    for (int i = 0; i < NROWS; i++)
    {
        for (int j = 0; j < NCOLS; j++)
        {
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j == 0 || i == (NROWS - 1) || (i == 0 && j != 3) || j == (NCOLS - 1));
            if ((playground[i][j].x == x_pos) && (playground[i][j].y == y_pos))
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
    int x_pos = 5;
    int y_pos = 5;
    
    displayPlayground(x_pos, y_pos);

    cin >> dir;
    while (dir != 'q')
    {
        if ((dir == 'l') && (1 < x_pos) && (y_pos > 0))
            x_pos--;
        else if ((dir == 'r') && (x_pos < 14) && (y_pos > 0))
            x_pos++;
        else if ((dir == 'u') && (1 < y_pos))
            y_pos--;
        else if ((dir == 'u') && (x_pos == 3) && (y_pos == 1))
            y_pos--;
        else if ((dir == 'd') && (y_pos < 10))
            y_pos++;
        displayPlayground(x_pos, y_pos);
        cin >> dir;
    }
    return 0;
}