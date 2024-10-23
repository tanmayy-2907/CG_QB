#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main(){

  int i, gd = DETECT,gm;

    initgraph(&gd,&gm,"C://TURBOC3//BGI");


 while(!kbhit()){
   for(i = 0; i<= 50; i++){
     cleardevice();

     setcolor(RED);
     setfillstyle(SOLID_FILL,RED);
     fillellipse(100+i-1,100+i-1,25,50);


     //BORDER
     setcolor(WHITE);
     ellipse(100+i,100+i,0,360,26,51);


     //ROPES
     ellipse(90+i,150+i,270,360,12,50);
     ellipse(90+i,250+i,90,180,12,50);


     setcolor(YELLOW);
     setfillstyle(SOLID_FILL,YELLOW);
     fillellipse(200+i,100+i,25,50);


     //BORDER
     setcolor(WHITE);
     ellipse(200+i,100+i,0,360,26,51);


     //ROPES
     ellipse(190+i,150+i,270,360,12,50);
     ellipse(190+i,250+i,90,180,12,50);


     setcolor(GREEN);
     setfillstyle(SOLID_FILL,GREEN);
     fillellipse(300+i,100+i,25,50);

     //BORDER
     setcolor(WHITE);
     ellipse(300+i,100+i,0,360,26,51);


     //ROPES
     ellipse(290+i,150+i,270,360,12,50);
     ellipse(290+i,250+i,90,180,12,50);



   delay(100);
  }

 }
  getch();
  closegraph();

  return 0;

}