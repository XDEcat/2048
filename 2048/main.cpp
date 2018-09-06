//
//  main.cpp
//  2048
//
//  Created by 陈泰文 on 2018/9/6.
//  Copyright © 2018年 twchen. All rights reserved.
//

#include "Header.h"

int main()
{
    G2048 newgame;
    newgame.display();
    char choice;
    do
    {
        cin>>choice;
        switch (choice)
        {
            case 'W':
            case 'w':
                if (newgame.move_up())
                    newgame.get_newone();
                newgame.display();
                break;
            case 'S':
            case 's':
                if (newgame.move_down())
                    newgame.get_newone();
                newgame.display();
                break;
            case 'A':
            case 'a':
                if (newgame.move_left())
                    newgame.get_newone();
                newgame.display();
                break;
            case 'D':
            case 'd':
                if (newgame.move_right())
                    newgame.get_newone();
                newgame.display();
                break;
            default:
                break;
        }
    } while (choice != 'Q' && choice != 'q');
    //system("pause");
    return 0;
}
