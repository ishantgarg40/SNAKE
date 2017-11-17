#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
#include <ncurses.h>
using namespace std;
bool over;
const int width = 20;
const int height = 20;
int x,y,fx,fy,score;
int tailx[100],taily[100];
int ntail=0;
enum eDirection {STOP = 0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
void snake_setup(){
  over = false;
dir = STOP;
x = width/2;
y = height/2;
srand(time(NULL));
fx = rand()%width;
fy = rand()%height;
score = 0;
}
void Board(){
system("clear");//FOR MACHINES HAVING WINDOWS USE system("cls");
int i,j;
  for(i=0;i<width+2;++i){
    cout<<"@";
  }
cout<<endl;
for(i=0;i<height;++i){
  for(j=0;j<width;++j){
  if(j==0){
    cout<<"@";
   }
   if(i==y&&j==x){
     cout<<"O";
   }
  else if(i==fy&&j==fx){
    cout<<"*";
  }
else{
bool t = false;
  for(int k=0;k<ntail;++k){

    if(tailx[k]==j&&taily[k]==i){
      cout<<"o";
      t = true;
    }

  }
  if(!t){
    cout<<" ";
  }
}
  if(j==width-1){
    cout<<"@";
  }
  }
cout<<endl;
  }
for(i=0;i<width+2;++i){
  cout<<"@";
}
cout<<endl;
cout<<"Score:"<<score<<endl;
}

void command(){
//initscr();
//char c;
//cin>>c;
  switch(getchar()){
case 'a':
      dir = LEFT;
      break;
case 'd':
      dir = RIGHT;
      break;
case 'w':
       dir = UP;
        break;
case 's':
       dir = DOWN;
       break;
case 'q':
       over = true;
         break;
 }
if(x>width||x<0||y>height||y<0){
  over = true;
}
if(x==fx&&y==fy){
++ntail;
score+=10;
fx = rand()%width;
fy = rand()%height;
}
}
void snake(){
int px = tailx[0];
int py = taily[0];
int pxx,pyy;
tailx[0] = x;
taily[0] = y;
for(int i=1;i<ntail;++i){
  pxx = tailx[i];
  pyy = taily[i];
  tailx[i] = px;
  taily[i] = py;
  px = pxx;
  py = pyy;
}
switch(dir){
case LEFT:
      --x;
      break;
case RIGHT:
      ++x;
      break;
case UP:
      --y;
      break;
case DOWN:
      ++y;
      break;
default:
    break;


}
}
int main()
{
 snake_setup();
while(!over){
  board();
  command();
  snake();
usleep(100000);
}
return 0;
}
