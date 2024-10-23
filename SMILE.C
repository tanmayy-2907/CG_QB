#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

int main(){

int i,gd = DETECT,gm;

  initgraph(&gd,&gm,"C://TURBOC3//BGI");

       setcolor(YELLOW);
       circle(300,300,50);
       setfillstyle(SOLID_FILL,YELLOW);
       floodfill(300,300,YELLOW);

       line(301,295,301,310);

       setcolor(0);
       setfillstyle(SOLID_FILL,0);

       arc(300,300,200,340,40);
       arc(301,300,200,340,40);

      while(!kbhit()){

    for(i = -10;i<10;i++){

       setcolor(YELLOW);
       setfillstyle(SOLID_FILL,YELLOW);
       fillellipse(280+i-1,285,3,6);
       fillellipse(325+i-1,285,3,6);

       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       fillellipse(280+i,285,3,6);
       fillellipse(325+i,285,3,6);


       delay(100);
    }

    for(i = 10; i>=-10; i--){
      setcolor(YELLOW);
       setfillstyle(SOLID_FILL,YELLOW);
       fillellipse(280+i+1,285,3,6);
       fillellipse(325+i+1,285,3,6);




       setcolor(BLACK);
       setfillstyle(SOLID_FILL,BLACK);
       fillellipse(280+i,285,3,6);
       fillellipse(325+i,285,3,6);



      delay(100);
    }




  }

  getch();
  closegraph();

  return 0;

}
