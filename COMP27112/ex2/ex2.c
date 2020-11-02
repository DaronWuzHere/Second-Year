/*
==========================================================================
File:        ex2.c (skeleton)
Version:     5, 19/12/2017
Author:     Toby Howard
Edited by: Daron Mauricette
==========================================================================
*/

/* The following ratios are not to scale: */
/* Moon orbit : planet orbit */
/* Orbit radius : body radius */
/* Sun radius : planet radius */

#ifdef MACOS
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BODIES 25
#define TOP_VIEW 1
#define ECLIPTIC_VIEW 2
#define SHIP_VIEW 3
#define EARTH_VIEW 4
#define PI 3.141593
#define DEG_TO_RAD 0.01745329
#define ORBIT_POLY_SIDES 50
#define TIME_STEP 0.5   /* days per frame */
#define SPACESHIP_SPEED 2.0
#define SPACESHIP_ROT 2.0

typedef struct { 
  char    name[25];       /* name */
  GLfloat r,g,b;          /* colour */
  GLfloat orbital_radius; /* distance to parent body (km) */
  GLfloat orbital_tilt;   /* angle of orbit wrt ecliptic (deg) */
  GLfloat orbital_period; /* time taken to orbit (days) */
  GLfloat radius;         /* radius of body (km) */
  GLfloat axis_tilt;      /* tilt of axis wrt body's orbital plane (deg) */
  GLfloat rot_period;     /* body's period of rotation (days) */
  GLint   orbits_body;    /* identifier of parent body */
  GLfloat spin;           /* current spin value (deg) */
  GLfloat orbit;          /* current orbit value (deg) */
 } body;



GLfloat xEarth, yEarth, zEarth;
GLfloat xshipVel, yshipVel, zshipVel, shipPitch, shipRot, xship, yship, zship;

body  bodies[MAX_BODIES];
int   numBodies, current_view, draw_orbits, draw_labels, draw_starfield;
float  date;

int axis, movement;
int stars = 1000;
int fieldSize = 10000000000;
GLfloat star[1000][3];
/*****************************/

float myRand (void)
{
  /* return a random float in the range [0,1] */
  return (float) rand() / RAND_MAX;
} // My Rand

/*****************************/

void drawStarfield (void)
{

  int i = 0;
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(1.0);
  glBegin (GL_POINTS);

  for(i = 0; i < stars; i++) 
  {
    glVertex3f(star[i][0], star[i][1], star[i][2]);
  } // For

  glEnd();

}

/*****************************/

void readSystem(void)
{
  /* reads in the description of the solar system */

  FILE *f;
  int i;

  f= fopen("sys", "r");
  if (f == NULL) {
     printf("ex2.c: Couldn't open 'sys'\n");
     printf("To get this file, use the following command:\n");
     printf("  cp /opt/info/courses/COMP27112/ex2/sys .\n");
     exit(0);
  }
  fscanf(f, "%d", &numBodies);
  for (i= 0; i < numBodies; i++)
  {
    fscanf(f, "%s %f %f %f %f %f %f %f %f %f %d", 
      bodies[i].name,
      &bodies[i].r, &bodies[i].g, &bodies[i].b,
      &bodies[i].orbital_radius,
      &bodies[i].orbital_tilt,
      &bodies[i].orbital_period,
      &bodies[i].radius,
      &bodies[i].axis_tilt,
      &bodies[i].rot_period,
      &bodies[i].orbits_body);

    /* Initialise the body's state */
    bodies[i].spin= 0.0;
    bodies[i].orbit= myRand() * 360.0; /* Start each body's orbit at a
                                          random angle */
    bodies[i].radius*= 1000.0; /* Magnify the radii to make them visible */
  }
  fclose(f);
}

/*****************************/

void drawString (void *font, float x, float y, char *str)
{ /* Displays the string "str" at (x,y,0), using font "font" */

}  // Draw String

/*****************************/

void setView (void) {

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  switch (current_view) {
  case TOP_VIEW:
    gluLookAt(1.0, 600000000.0, 1.0, 
              0.0, 0.0, 0.0, 
              0.0, 0.0, -1.0 );
    break;  
  case ECLIPTIC_VIEW: 
     gluLookAt(1.0, 1.0, 800000000.0, 
               0.0, 0.0, 0.0, 
               0.0, 10.0, 0.0 );
    break;  
  case SHIP_VIEW:
    gluLookAt(xship, yship, zship,    
              xship + sin(shipRot * DEG_TO_RAD) * cos(shipPitch * DEG_TO_RAD),
              yship + sin(shipPitch * DEG_TO_RAD), 
              zship + cos(shipRot * DEG_TO_RAD) * cos(shipPitch * DEG_TO_RAD),
              0.0, 1.0, 0.0);
    break;  
  case EARTH_VIEW: 
    gluLookAt(xEarth, yEarth, zEarth, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0 );
    break;  
  }
 
}  // Set View

/*****************************/

void menu (int menuentry) {
  switch (menuentry) {
  case 1: current_view= TOP_VIEW;
          break;
  case 2: current_view= ECLIPTIC_VIEW;
          break;
  case 3: current_view= SHIP_VIEW;
          break;
  case 4: current_view= EARTH_VIEW;
          break;
  case 5: draw_labels= !draw_labels;
          break;
  case 6: draw_orbits= !draw_orbits;
          break;
  case 7: draw_starfield= !draw_starfield;
          break;
  case 8: exit(0);
  }
}

/*****************************/

void init(void)
{
  /* Define background colour */
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glutCreateMenu (menu);
  glutAddMenuEntry ("Top view", 1);
  glutAddMenuEntry ("Ecliptic view", 2);
  glutAddMenuEntry ("Spaceship view", 3);
  glutAddMenuEntry ("Earth view", 4);
  glutAddMenuEntry ("", 999);
  glutAddMenuEntry ("Toggle labels", 5);
  glutAddMenuEntry ("Toggle orbits", 6);
  glutAddMenuEntry ("Toggle starfield", 7);
  glutAddMenuEntry ("", 999);
  glutAddMenuEntry ("Quit", 8);
  glutAttachMenu (GLUT_RIGHT_BUTTON);

  current_view= TOP_VIEW;
  draw_labels= 1;
  draw_orbits= 1;
  draw_starfield= 1;
  

  int i;
  for(i = 0; i < stars; i++)
  { 
    star[i][0] = (myRand() * fieldSize) - (fieldSize / 2);
    star[i][1] = (myRand() * fieldSize) - (fieldSize / 2);
    star[i][2] = (myRand() * fieldSize) - (fieldSize / 2);    
  } // For

}  // Init

/*****************************/

void animate(void)
{

  int i;

    date+= TIME_STEP;

    for (i= 0; i < numBodies; i++)  {
      bodies[i].spin += 360.0 * TIME_STEP / bodies[i].rot_period;
      bodies[i].orbit += 360.0 * TIME_STEP / bodies[i].orbital_period;
      glutPostRedisplay();
    } // For
    
    GLfloat xnewShipVel = sin(shipRot * DEG_TO_RAD)+cos(shipPitch * DEG_TO_RAD);
    GLfloat ynewShipVel = sin(shipPitch * DEG_TO_RAD);
    GLfloat znewShipVel = cos(shipRot * DEG_TO_RAD)+cos(shipPitch * DEG_TO_RAD);

    xnewShipVel = xnewShipVel * SPACESHIP_SPEED;
    ynewShipVel = ynewShipVel * SPACESHIP_SPEED;
    znewShipVel = znewShipVel * SPACESHIP_SPEED;

    if(movement)
    {
      xshipVel = xshipVel + xnewShipVel;
      yshipVel = yshipVel + ynewShipVel;
      zshipVel = zshipVel + znewShipVel;
      movement = 0;
    } // If
   

}  //Animate

/*****************************/

void drawOrbit (int n)
{ /* Draws a polygon to approximate the circular
     orbit of body "n" */
  double position;
  double drawLine = 100;
  int i;
  
  
  glTranslatef(sin(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) *  
               bodies[bodies[n].orbits_body].orbital_radius,
               sin(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) *  
               bodies[bodies[n].orbits_body].orbital_radius *
               tan(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbital_tilt),
               cos(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) *  
               bodies[bodies[n].orbits_body].orbital_radius);
  
  glColor3f(1.0, 1.0, 1.0);

  glBegin(GL_LINE_LOOP);
  for(i = 0; i < drawLine; i++)
  {
    position = (i * 360)  / drawLine;
    glVertex3f(sin(DEG_TO_RAD * position) * 
               bodies[n].orbital_radius,
               sin(DEG_TO_RAD * position) * 
               bodies[n].orbital_radius *
               tan(DEG_TO_RAD * bodies[n].orbital_tilt),
               cos(DEG_TO_RAD * position) * 
               bodies[n].orbital_radius);
  } // For

  glEnd();
}  // Draw Orbit

/*****************************/

void drawLabel(int n)
{ /* Draws the name of body "n" */

    /* This is for you to complete. */
}

/*****************************/

void drawBody(int n)
{
  /* Draws body "n" */
  glBegin(GL_LINE);
    glVertex3f(0.0, bodies[n].radius + 1000, 0.0);
    glVertex3f(0.0, -bodies[n].radius - 1000, 0.0);
  glEnd();

  // Colours, red, blue, green
  glColor3f(bodies[n].r, bodies[n].g, bodies[n].b);
  
  glTranslatef(sin(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) * 
              bodies[bodies[n].orbits_body].orbital_radius,
              sin(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) * 
              bodies[bodies[n].orbits_body].orbital_radius *
              tan(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbital_tilt),
              cos(DEG_TO_RAD * bodies[bodies[n].orbits_body].orbit) *
              bodies[bodies[n].orbits_body].orbital_radius);
  
  glTranslatef(sin(DEG_TO_RAD * bodies[n].orbit) * bodies[n].orbital_radius,
               sin(DEG_TO_RAD * bodies[n].orbit) * bodies[n].orbital_radius * 
               tan(DEG_TO_RAD * bodies[n].orbital_tilt),
               cos(DEG_TO_RAD * bodies[n].orbit) * bodies[n].orbital_radius);
   

   if(strcmp(bodies[n].name,"Earth") == 0)
   {
     int planetOffset = 10000000;
     xEarth = sin(DEG_TO_RAD*bodies[n].orbit) * bodies[n].orbital_radius + 
              planetOffset;
     yEarth = sin(DEG_TO_RAD*bodies[n].orbit) * bodies[n].orbital_radius *
              tan(DEG_TO_RAD * bodies[n].orbital_tilt) + planetOffset;
     zEarth = cos(DEG_TO_RAD*bodies[n].orbit) * bodies[n].orbital_radius + 
              planetOffset;
   } // If


   glRotatef(bodies[n].axis_tilt, 1.0, 0.0, 0.0);
   glRotatef(bodies[n].spin, 0.0, 1.0, 0.0);
   glRotatef(90.0, 1.0, 0.0, 0.0);

   glutWireSphere(bodies[n].radius, 16, 16);
} // Draw Body

/*****************************/

void display(void)
{
  int i;

  glClear(GL_COLOR_BUFFER_BIT);

  /* set the camera */
  setView();
  

  if (draw_starfield) drawStarfield();

  for (i= 0; i < numBodies; i++)
  {
    glPushMatrix();
      drawBody(i);
    glPopMatrix();
    if(draw_orbits)  
    {
      glPushMatrix();  
      drawOrbit(i);
      glPopMatrix();
    } 
    drawAxes();
    glutSwapBuffers();
  }

  glutSwapBuffers();
}

/*****************************/
void drawAxes(void)
{
  /*Draws the axes of Solar System*/

  if(axis)
  {
    float length = 10000000.0;

    glLineWidth(5.0);
    glBegin(GL_LINES);

    // Red
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, length, 0.0);
   
    //Blue
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, length, 0.0);

    //Green
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, length, 0.0);
 
    glEnd();

    glLineWidth(1.0);

  } // If
} // Draw Axes

/*****************************/

void reshape(int w, int h)
{
  glViewport(0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective (48.0, (GLfloat)w/(GLfloat)h,  10000.0, 800000000.0);
}
  
/*****************************/

void keyboard(unsigned char key, int x, int y)
{
  switch(key)
  {
    case 27:  /* Escape key */
      exit(0);
      break;
    case 119:  /* Move the Spaceship up, w */
      shipPitch = shipPitch + SPACESHIP_ROT;
      break;
    case 115:  /* Move the Spaceship down, s */
      shipPitch = shipPitch - SPACESHIP_ROT;
      break;
    case 100:  /* Move the Spaceship right, d  */
      shipRot = shipRot - SPACESHIP_ROT;
      break;
    case 97:  /* Move the Spaceship left, a */
      shipRot = shipRot + SPACESHIP_ROT;
      break;
    case 44:  /* Move the Spaceship forward, comma */ 
      yship = yship + yshipVel;
      zship = zship + zshipVel;
      break;
   // case 46:  /* Move the Spaceship back, period */
   //   movement = 0;
   //   break;    
   
  }
} 

/*****************************/

int main(int argc, char** argv)
{
  glutInit (&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutCreateWindow ("COMP27112 Exercise 2");
  //glutFullScreen();
  init();
  glutDisplayFunc (display); 
  glutReshapeFunc (reshape);
  glutKeyboardFunc (keyboard);
  glutIdleFunc (animate);
  readSystem();
  glutMainLoop();
  return 0;
}
/* end of ex2.c */
