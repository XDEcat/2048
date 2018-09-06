//
//  Header.h
//  2048
//
//  Created by 陈泰文 on 2018/9/6.
//  Copyright © 2018年 twchen. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>

using namespace std;

class G2048
{
public:
    G2048();
    void display();
    bool move_up();
    bool move_down();
    bool move_left();
    bool move_right();
    void get_newone();
private:
    int get_score();
    bool is_gameover();
    void up_swap(size_t, size_t, bool&);
    void down_swap(size_t, size_t, bool&);
    void left_swap(size_t, size_t, bool&);
    void right_swap(size_t, size_t, bool&);
    void up_add(bool&);
    void down_add(bool&);
    void left_add(bool&);
    void right_add(bool&);
private:
    int game[4][4];
};

G2048::G2048()
{
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
            game[i][j] = 0;
    }
    get_newone();
}

void G2048::display()
{
    //system("cls");
    cout << "Game 2048 :\nUse 'W'(up), 'S'(down), 'A'(left) and\n'D'(right) to move numbers! 'Q' to quit!\n\n";
    for (int i = 0; i < 4; ++i)
    {
        cout << "+-------+-------+-------+-------+"<< endl;
        for (int j = 0; j < 4; ++j)
        {
            if (game[i][j] == 0)
            {
                cout <<"|\t \t";
            }
            else
            {
                cout <<"|\t" << game[i][j] << "\t";
            }
        }
        cout << "|" << endl;
    }
    cout << "+-------+-------+-------+-------+"<< endl;
}

int G2048::get_score()
{
    int score = 0;
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            int n = game[i][j];
            if (n >= 2048)
                score += n * 4;
            else if (n >= 512)
                score += n * 3;
            else if (n >= 128)
                score += n * 2;
            else
                score += n;
        }
    }
    return score;
}

bool G2048::is_gameover()
{
    for (size_t i = 0; i != 3; ++i)
        for (size_t j = 0; j != 3; ++j)
            if (game[i][j] == 0)
                return false;
    return true;
}

void G2048::get_newone()
{
    if (is_gameover())
    {
        cout << "Game OVER!";
        return;
    }
    size_t i = rand() % 4;
    size_t j = rand() % 4;
    int n = rand() % 4;
    if (!game[i][j])
        game[i][j] = n ? 2 : 4;
    else
        get_newone();
}

void G2048::up_swap(size_t x, size_t y, bool& moved)
{
    auto n = x;
    while (n < 4)
    {
        ++n;
        if (game[n][y] != 0 && n < 4)
        {
            swap(game[x][y], game[n][y]);
            moved = true;
            return;
        }
    }
}

void G2048::up_add(bool& moved)
{
    for (size_t j = 0; j < 4; ++j)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            if (game[i][j] != 0 && game[i][j] == game[i + 1][j])
            {
                game[i][j] += game[i + 1][j];
                game[i + 1][j] = 0;
                up_swap(i + 1, j, moved);
            }
        }
    }
}

bool G2048::move_up()
{
    bool moved = false;
    for (size_t j = 0; j < 4; ++j)
    {
        for (size_t i = 0; i < 4; ++i)
        {
            if (!game[i][j])
                up_swap(i, j, moved);
        }
    }
    up_add(moved);
    return moved;
}

void G2048::down_swap(size_t x, size_t y, bool& moved)
{
    auto n = x;
    while (n < 4)
    {
        --n;
        if (game[n][y] != 0 && n < 4)
        {
            swap(game[x][y], game[n][y]);
            moved = true;
            return;
        }
    }
}

void G2048::down_add(bool& moved)
{
    for (size_t j = 0; j < 4; ++j)
    {
        for (size_t i = 3; i < 4 && i >= 0; --i)
        {
            if (game[i][j] != 0 && game[i][j] == game[i - 1][j])
            {
                game[i][j] += game[i - 1][j];
                game[i - 1][j] = 0;
                down_swap(i - 1, j, moved);
            }
        }
    }
}

bool G2048::move_down()
{
    bool moved = false;
    for (size_t j = 0; j < 4; ++j)
    {
        for (size_t i = 3; i < 4 && i >= 0; --i)
        {
            if (!game[i][j])
                down_swap(i, j, moved);
        }
    }
    down_add(moved);
    return moved;
}

void G2048::left_swap(size_t x, size_t y, bool& moved)
{
    auto n = y;
    while (n < 4)
    {
        ++n;
        if (game[x][n] != 0 && n < 4)
        {
            swap(game[x][y], game[x][n]);
            moved = true;
            return;
        }
    }
}

void G2048::left_add(bool& moved)
{
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            if (game[i][j] != 0 && game[i][j] == game[i][j + 1])
            {
                game[i][j] += game[i][j + 1];
                game[i][j + 1] = 0;
                left_swap(i, j + 1, moved);
            }
        }
    }
}

bool G2048::move_left()
{
    bool moved = false;
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 0; j < 4; ++j)
        {
            if (!game[i][j])
                left_swap(i, j, moved);
        }
    }
    left_add(moved);
    return moved;
}

void G2048::right_swap(size_t x, size_t y, bool& moved)
{
    auto n = y;
    while (n < 4)
    {
        --n;
        if (game[x][n] != 0 && n < 4)
        {
            swap(game[x][y], game[x][n]);
            moved = true;
            return;
        }
    }
}

void G2048::right_add(bool& moved)
{
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 3; j < 4 && j >= 0; --j)
        {
            if (game[i][j] != 0 && game[i][j] == game[i][j - 1])
            {
                game[i][j] += game[i][j - 1];
                game[i][j - 1] = 0;
                right_swap(i, j - 1, moved);
            }
        }
    }
}

bool G2048::move_right()
{
    bool moved = false;
    for (size_t i = 0; i < 4; ++i)
    {
        for (size_t j = 3; j < 4 && j >= 0; --j)
        {
            if (!game[i][j])
                right_swap(i, j, moved);
        }
    }
    right_add(moved);
    return moved;
}

#endif /* Header_h */
