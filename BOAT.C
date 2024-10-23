
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

int main(){

  int i,j, gd = DETECT,gm;

 // int points[]={75,100,500,100,420,150,120,150,75,100};

 // int triangle[] = {130,100,150,50,170,100,130,100};

    initgraph(&gd,&gm,"C://TURBOC3//BGI");



   while(!kbhit()){
    for(j = 0; j<=1000; j +=5){
    cleardevice();
    line(75+j,100,500+j,100);
    line(500+j,100,420+j,150);
    line(420+j,150,120+j,150);
    line(120+j,150,75+j,100);

    line(130+j,100,150+j,50);
    line(150+j,50,170+j,100);

    delay(50);

    for(i = 0; i <=500; i++){
    if(i%20!=0){
    line(i+10,160,i+10,160);
    line(i+10,180,i+10,180);
    line(i+10,200,i+10,200);

    delay(5000);
    }


}
 }

}
  getch();
  closegraph();

  return 0;

}


