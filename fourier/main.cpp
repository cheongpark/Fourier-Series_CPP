#include <iostream>
#include <math.h>
#include <Windows.h>
#include "graphics.h"

#define PI 3.141592
#define X 250
#define Y 500
#define CENTER 250
#define WAVE_C 1000
#define CIRCLE_N 100

using namespace std;

void circle_fourier();


int main()
{
    int gd = 0, gm;


    initwindow(1000, 1000, "");

    circle_fourier();

    getch();
    closegraph();
    return 0;
}

void circle_fourier()
{
    float abc = 0;
    int wave[WAVE_C] = {}; //원 큐로 시도해보기
    int count = 1;
    while (1)
    {
        int x = X, y = Y;
        cleardevice();
        for (int i = 0; i < CIRCLE_N; i++)
        {
            int prevx = x, prevy = y;
            int n = i * 2 + 1;
            int radius = 75 * (4 / (n * PI));

            x += radius * cos(n * abc);
            y += radius * sin(n * abc);

            setcolor(WHITE);
            circle(prevx, prevy, radius);

            setcolor(YELLOW);
            line(prevx, prevy, x, y);

            //setcolor(LIGHTRED);
            //circle(prevx, prevy, 5);
            
        }
        for(int i = count - 1;i>=0;i--)
            wave[i + 1] = wave[i];
        wave[0] = y;
        setcolor(LIGHTGREEN);
        line(x, y, X + CENTER, y);
        abc += 0.01;
        
        setcolor(LIGHTBLUE);
        for (int i = count; i > 0 ; i--)
            line(0 + (i + X + CENTER), wave[i], 0 + (i + X + CENTER + 1), wave[i]);

        cout << wave[count] << "\t" << wave[count] + X + CENTER << "\n";

        Sleep(1);

        count++;

        if (count == WAVE_C)
        {
            for (int i = 0; i < count; i++)
                wave[i] = 0;
            count = 0;
        }

    }
}