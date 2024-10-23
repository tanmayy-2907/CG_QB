#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>

int main(){

   int i,gd = DETECT,gm;

   initgraph(&gd,&gm,"C://TURBOC3//BGI");

  while(!kbhit()){
    setcolor(WHITE);
    rectangle(100,100,150,300);
    //RED LIGHT

    setcolor(RED);
    circle(125,125,20);
    setfillstyle(SOLID_FILL,RED);
    floodfill(125,125,RED);

    //BORDER
    setcolor(WHITE);
    circle(125,125,21);


    delay(1000);
    cleardevice();

     setcolor(WHITE);
    rectangle(100,100,150,300);

    //YELLOW LIGHT


    setcolor(YELLOW);
    circle(125,195,20);
    setfillstyle(SOLID_FILL,YELLOW);
    floodfill(125,195,YELLOW);

    //BORDER
    setcolor(WHITE);
    circle(125,195,21);

    delay(1000);
    cleardevice();
     setcolor(WHITE);
    rectangle(100,100,150,300);

    //GREEN LIGHT
    setcolor(GREEN);
    circle(125,260,20);
    setfillstyle(SOLID_FILL,GREEN);
    floodfill(125,260,GREEN);

    //BORDER
    setcolor(WHITE);
    circle(125,260,21);

    delay(1000);

    cleardevice();
  }
   getch();
   closegraph();

return 0;

}