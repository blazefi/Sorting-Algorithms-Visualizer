
#include<GL/glut.h>
#include<bits/stdc++.h>
#include<unistd.h>

// defining global variables
const int N=400;
int vec[N],compares,exchanges;
std::string sortName;

void display();
void visual(int* arr);
void drawBitmapString(float x,float y,std::string s);

#include"sort.h"

int main(int argc,char** argv){

  // Generating random array within the range of N
  srand((unsigned)time(0));
  for(int i=0;i<N;i++){
    vec[i] = (rand()%600);
  }

  glutInit(&argc,argv);// initializing glut
  glutInitWindowSize(1736,864);// size of the window
  glutCreateWindow("Sorting Visualization");// name of window
  glutInitWindowPosition(0,100); // your screen cordinate at which window will appear
  glutDisplayFunc(display); // call back function
  glClearColor(0.0f,0.0f,0.0f,1.0f); //initiaze
  gluOrtho2D(0,1736,0,864); // transforming clipping area to Viewport area
  glutMainLoop(); // infinite processing loop
  return 0;
}

void display(){
  visual(vec);
  int arr[N];

  compares = 0, exchanges = 0;
  sortName = "Heap Sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  heapSort (arr,N);
  sleep(5);

  compares = 0,exchanges = 0;
  sortName = "quick sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  quickSort (arr,N);
  sleep(5);

  compares = 0,exchanges = 0;
  sortName = "merge sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  mergeSort (arr,N);
  sleep(5);

  compares = 0, exchanges = 0;
  sortName = "insertion sort";
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  insertionSort (arr,N);
  sleep(5);

  sortName = "selection sort";
  compares = 0,exchanges = 0;
  for(int i=0;i<N;i++)
    arr[i] = vec[i];
  selectionSort (arr,N);
  sleep(5);
}


void visual(int* arr){
  glClear(GL_COLOR_BUFFER_BIT); // sets the previous background with the current background
  drawBitmapString(700,770,sortName);
  drawBitmapString(700,750,"Number of Compares:"+std::to_string(compares));
  drawBitmapString(700,730,"Number of Exchanges:"+std::to_string(exchanges));
  glColor3f(1.0f,0.0f,0.0f); //red
  // drawing bars on the screen by diagonal coordinates
  for(int i=0;i<N;i++){
    glRecti(4*i,100,4*i+3,100+arr[i]);
  }
  glFlush();
  usleep(50);
}

void drawBitmapString(float x,float y,std::string s)
{
  glColor3f(1.0f,1.0f,1.0f); // sets color of the text
  glRasterPos2f(x, y);// screen coordinate at which text will appear
  
  int length = s.size();
  
  // writing charater by charater on the screen
  for(int i=0;i<length;i++){
     glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, s[i]);
  }
}
