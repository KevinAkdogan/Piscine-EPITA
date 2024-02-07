#include <stddef.h>

int connect4(char *game[], size_t columns, size_t lines)
{
    int winner_player = -1;
    for (size_t i = 0; i < lines; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            char player = game[i][j];
            if (player == '-')
            {
                continue;
            }

            if (j + 3 < columns && player == game[i][j + 1]
                && player == game[i][j + 2] && player == game[i][j + 3])
            {
                winner_player = winner_player < 0 ? player : 0;
            }

            if (i + 3 < lines && player == game[i + 1][j]
                && player == game[i + 2][j] && player == game[i + 3][j])
            {
                winner_player = winner_player < 0 ? player : 0;
            }

            if (j + 3 < columns && i + 3 < lines && player == game[i + 1][j + 1]
                && player == game[i + 2][j + 2] && player == game[i + 3][j + 3])
            {
                winner_player = winner_player < 0 ? player : 0;
            }

            if (i + 3 < lines && j >= 3 && player == game[i + 1][j - 1]
                && player == game[i + 2][j - 2] && player == game[i + 3][j - 3])
            {
                winner_player = winner_player < 0 ? player : 0;
            }
        }
    }
    if (winner_player < 1)
    {
        return 0;
    }
    else
    {
        return winner_player == 88 ? 1 : 2;
    }
}
