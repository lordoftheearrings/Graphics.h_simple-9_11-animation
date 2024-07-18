#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>


void drawTwinTowers(int x, int y) {
    
    setcolor(WHITE);
    rectangle(x, y, x + 40, y - 200);  
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 20, y - 100, WHITE);

    
    setcolor(WHITE);
    rectangle(x + 60, y, x + 100, y - 200); 
    setfillstyle(SOLID_FILL, WHITE);
    floodfill(x + 80, y - 100, WHITE);

    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            setcolor(BLACK);
            rectangle(x + 5 + j * 20, y - 20 - i * 20, x + 15 + j * 20, y - 30 - i * 20);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(x + 10 + j * 20, y - 25 - i * 20, BLACK);
        }
    }

   
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            setcolor(BLACK);
            rectangle(x + 65 + j * 20, y - 20 - i * 20, x + 75 + j * 20, y - 30 - i * 20);
            setfillstyle(SOLID_FILL, BLACK);
            floodfill(x + 70 + j * 20, y - 25 - i * 20, BLACK);
        }
    }
}

void drawSky() {
    setfillstyle(SOLID_FILL, CYAN);
    floodfill(0, 0, CYAN);
}

void drawGround(int y) {
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL, DARKGRAY);
    bar(0, y, getmaxx(), getmaxy()); 
}

void drawSmallBuildings(int groundY) {
    setcolor(LIGHTGRAY);
    setfillstyle(SOLID_FILL, LIGHTGRAY);

    rectangle(50, groundY - 40, 100, groundY);  
    floodfill(75, groundY - 20, LIGHTGRAY);     
    line(50, groundY - 40, 75, groundY - 60);   
    line(100, groundY - 40, 75, groundY - 60);  

    
    rectangle(160, groundY - 40, 210, groundY);  
    floodfill(185, groundY - 20, LIGHTGRAY);     
    line(160, groundY - 40, 185, groundY - 60);  
    line(210, groundY - 40, 185, groundY - 60);  


    
    rectangle(380, groundY - 40, 430, groundY);  
    floodfill(405, groundY - 20, LIGHTGRAY);     
    line(380, groundY - 40, 405, groundY - 60);  
    line(430, groundY - 40, 405, groundY - 60);  

    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);

    rectangle(60, groundY - 30, 80, groundY - 20);
    floodfill(70, groundY - 25, CYAN);

    rectangle(170, groundY - 30, 190, groundY - 20);
    floodfill(180, groundY - 25, CYAN);

    rectangle(390, groundY - 30, 410, groundY - 20);
    floodfill(400, groundY - 25, CYAN);
}
void drawSun() {
    int sunX = 100, sunY = 50;
    int sunRadius = 30;

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(sunX, sunY, sunRadius, sunRadius);
}

void drawCloud1() {
    int cloud1X = 250, cloud1Y = 100;
    int cloud1Radius = 20;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(cloud1X, cloud1Y, cloud1Radius, cloud1Radius);
    fillellipse(cloud1X - 20, cloud1Y - 20, cloud1Radius, cloud1Radius);
    fillellipse(cloud1X + 20, cloud1Y - 20, cloud1Radius, cloud1Radius);
    fillellipse(cloud1X - 40, cloud1Y, cloud1Radius, cloud1Radius);
    fillellipse(cloud1X + 40, cloud1Y, cloud1Radius, cloud1Radius);
}

void drawCloud2() {
    int cloud2X = 500, cloud2Y = 120;
    int cloud2Radius = 20;

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(cloud2X, cloud2Y, cloud2Radius, cloud2Radius);
    fillellipse(cloud2X - 20, cloud2Y - 20, cloud2Radius, cloud2Radius);
    fillellipse(cloud2X + 20, cloud2Y - 20, cloud2Radius, cloud2Radius);
    fillellipse(cloud2X - 40, cloud2Y, cloud2Radius, cloud2Radius);
    fillellipse(cloud2X + 40, cloud2Y, cloud2Radius, cloud2Radius);
}
void drawPlane(int x, int y, bool fromLeft) {
    setcolor(WHITE);
    if (fromLeft) {
        rectangle(x, y, x + 50, y + 20);  
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x + 25, y + 10, WHITE);

        line(x + 50, y, x + 60, y + 10);  
        line(x + 60, y + 10, x + 50, y + 20);  

        line(x, y + 10, x - 10, y);  
        line(x, y + 10, x - 10, y + 20);  
    } else {
        rectangle(x - 50, y, x, y + 20); 
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(x - 25, y + 10, WHITE);

        line(x - 50, y, x - 60, y + 10); 
        line(x - 60, y + 10, x - 50, y + 20);  

        line(x, y + 10, x + 10, y);  
        line(x, y + 10, x + 10, y + 20);  
    }
}

void clearPlane(int x, int y, bool fromLeft) {
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    if (fromLeft) {
        bar(x - 10, y - 10, x + 80, y + 30);
    } else {
        bar(x - 80, y - 10, x + 20, y + 30);
    }
}

void drawExplosion(int x, int y) {
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    fillellipse(x, y, 50, 50);

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL, YELLOW);
    fillellipse(x, y, 30, 30);

    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    fillellipse(x, y, 10, 10);
}

void clearUpperPart(int x, int y, int width, int height) {
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    bar(x, y +20- height, x + width+20, y); 
}

void clearExplosionArea(int x, int y) {
    setcolor(CYAN);
    setfillstyle(SOLID_FILL, CYAN);
    bar(x - 50, y - 50, x + 50, y + 50);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    setcolor(CYAN);
    drawSky();

    drawSun();

    drawCloud1();

    drawCloud2();

    drawTwinTowers(200, 400);

    drawGround(400); 
    drawSmallBuildings(400);

    setcolor(GREEN);
    settextstyle(BOLD_FONT, HORIZ_DIR, 1);
    outtextxy(40, 405, const_cast<char*>("9/11 In the memory of TWIN TOWERS"));
    outtextxy(40, 430, const_cast<char*>("SIDDHANTA SHRESTHA(079), SHUVAM MAHAT(078)"));
    outtextxy(40, 450, const_cast<char*>("SUGAM SHARMA(084), RACHANA ADHIKARI(062)"));

    int x1 = 10, y1 = 200;  
    int speed1 = 4;
    bool explosion1 = false;
    bool soundPlayed1 = false;

    while (!explosion1) {
        if (x1 >= 200 - 70 - speed1 * 15 && !soundPlayed1) { 
            PlaySound(TEXT("sounds\\Allahu Akbar.wav"), NULL, SND_FILENAME | SND_ASYNC);
            soundPlayed1 = true;
        }

        if (x1 >= 200 - 70) { 
            explosion1 = true;
            
            drawExplosion(220, y1 + 10); 
            clearPlane(x1, y1, true);
        } else {
            clearPlane(x1, y1, true);
            x1 += speed1;
            drawPlane(x1, y1, true);
            delay(50);
        }
    }

    delay(1000);

    clearUpperPart(200, y1 + 10, 40, 100);
    clearExplosionArea(220, y1 + 10);

    int x2 = getmaxx() - 50, y2 = 250;  
    bool explosion2 = false;
    bool soundPlayed2 = false;
    int speed2 = 5;
    
    while (!explosion2) {
        if (x2 <= 260 + 100 + speed2 * 15 && !soundPlayed2) { 
            PlaySound(TEXT("sounds\\Allahu Akbar.wav"), NULL, SND_FILENAME | SND_ASYNC);
            soundPlayed2 = true;
        }

        if (x2 <= 260 + 100) { 
            explosion2 = true;
            
            drawExplosion(280, y2 + 10); 
            clearPlane(x2, y2, false); 
        } else {
            clearPlane(x2, y2, false); 
            x2 -= speed2;
            drawPlane(x2, y2, false);
            delay(50);
        }
    }

    delay(1000);

    clearUpperPart(260, y2 + 10, 40, 100);
    clearExplosionArea(280, y2 + 10);
    
    PlaySound(TEXT("sounds\\Alhamdulillah meme.wav"), NULL, SND_FILENAME | SND_ASYNC);

    getch();
    closegraph();
    return 0;
}