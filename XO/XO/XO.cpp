// XO.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <GL/freeglut.h>

int i = 0;
bool isFirst;
int *mass = new int[9];
int *round = new int[9];

void X_signal(int place_on_mass)
{
	int y_on_sq = place_on_mass / 3;
	int x_on_sq = place_on_mass % 3;

	int x_place = ((x_on_sq)* 145 + 40) + 20;
	int y_place = ((y_on_sq)* 145 + 40) + 20;

	glBegin(GL_LINES);

	glColor3f(1, 1, 1);

	glVertex2f(x_place, y_place + 95 - 6);
	glVertex2f(x_place + 95 - 6, y_place);
	glVertex2f(x_place + 6, y_place + 95);
	glVertex2f(x_place + 95, y_place + 6);

	glVertex2f(x_place + 95 - 6, y_place + 95);
	glVertex2f(x_place, y_place + 6);
	glVertex2f(x_place + 95, y_place + 95 - 6);
	glVertex2f(x_place + 6, y_place);

	glEnd();

	//glBegin(GL_QUADS);

	//glColor3f(1, 1, 1);

	//glVertex2f(x_place, y_place);
	//glVertex2f(x_place + 95, y_place);
	//glVertex2f(x_place + 95, y_place + 95);
	//glVertex2f(x_place, y_place + 95);

	//glEnd();
}

void O_signal(int place_on_mass)
{
	int y_on_sq = place_on_mass / 3;
	int x_on_sq = place_on_mass % 3;

	int x_place = ((x_on_sq)* 145 + 40) + 20;
	int y_place = ((y_on_sq)* 145 + 40) + 20;

	glBegin(GL_LINE_LOOP);

	glColor3f(1, 1, 1);

	// внешняя окружность
	glVertex2f(x_place + 48, y_place + 95);
	glVertex2f(x_place + 80, y_place + 80);
	glVertex2f(x_place + 95, y_place + 48);
	glVertex2f(x_place + 80, y_place + 15);
	glVertex2f(x_place + 47, y_place);
	glVertex2f(x_place + 15, y_place + 15);
	glVertex2f(x_place, y_place + 47);
	glVertex2f(x_place + 15, y_place + 80);

	glEnd();

	glBegin(GL_LINE_LOOP);

	// внутренняя окружность
	glVertex2f(x_place + 48, y_place + 85);
	glVertex2f(x_place + 72, y_place + 72);
	glVertex2f(x_place + 85, y_place + 48);
	glVertex2f(x_place + 72, y_place + 23);
	glVertex2f(x_place + 47, y_place + 10);
	glVertex2f(x_place + 23, y_place + 23);
	glVertex2f(x_place + 10, y_place + 47);
	glVertex2f(x_place + 23, y_place + 72);

	glEnd();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);

	glColor3f(1, 1, 1);
	// горизонтальные
	glVertex2f(175, 460);
	glVertex2f(175, 40);
	glVertex2f(185, 460);
	glVertex2f(185, 40);	
	glVertex2f(320, 460);
	glVertex2f(320, 40);
	glVertex2f(330, 460);
	glVertex2f(330, 40);
	// вертикальные
	glVertex2f(460, 175);
	glVertex2f(40, 175);
	glVertex2f(460, 185);
	glVertex2f(40, 185);
	glVertex2f(460, 320);
	glVertex2f(40, 320);
	glVertex2f(460, 330);
	glVertex2f(40, 330);

	glEnd();

	if (isFirst == false)
	{
		mass[6] = 1;
		round[0] = 6;
		if (mass[0] == 2)
		{
			round[1] = 0;
			mass[8] = 1;
			round[2] = 8;
			if (mass[1] == 2)
			{
				round[3] = 1;
				mass[7] = 1;
				round[4] = 7;
			}
			else if (mass[2] == 2)
			{
				round[3] = 2;
				mass[7] = 1;
				round[4] = 7;
			}
			else if (mass[3] == 2)
			{
				round[3] = 3;
				mass[7] = 1;
				round[4] = 7;
			}
			else if (mass[4] == 2)
			{
				round[3] = 4;
				mass[7] = 1;
				round[4] = 7;
			}
			else if (mass[5] == 2)
			{
				round[3] = 5;
				mass[7] = 1;
				round[4] = 7;
			}
			else if (mass[7] == 2)
			{
				round[3] = 7;
				if (mass[1] == 2)
				{
					round[4] = 1;
					mass[5] = 1;
					round[5] = 5;
				}
				else if (mass[3] == 2)
				{
					round[4] = 3;
					mass[5] = 1;
					round[5] = 5;
				}
				else if (mass[4] == 2)
				{
					round[4] = 4;
					mass[5] = 1;
					round[5] = 5;
				}
				else if (mass[5] == 2)
				{
					round[4] = 5;
					mass[4] = 1;
					round[5] = 4;
				}
			}
		}
		else if (mass[1] == 2)
		{
			round[1] = 1;
			mass[4] = 1;
			round[2] = 4;
			if (mass[0] == 2)
			{
				round[3] = 0;
				mass[2] = 1;
				round[4] = 2;
			}
			else if (mass[2] == 2)
			{
				round[3] = 2;
				mass[0] = 1;

				if (true)
				{

				}
			}
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (mass[j] == 1)
		{
			X_signal(j);
		}
		else if (mass[j] == 2)
		{
			O_signal(j);
		}
	}
	glFlush();
}

void timer(int = 0)
{
	Display();
	i++;
	glutTimerFunc(50, timer, 0);
}

void mouse_Click(int button, int state, int ax, int ay)
{
	if (button == GLUT_LEFT_BUTTON)
	{
		if ((ax > 40) && (ax <= 175))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((mass[0] != 1) && (mass[0] != 2))
				{
					mass[0] = 1;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((mass[3] != 1) && (mass[3] != 2))
				{
					mass[3] = 1;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((mass[6] != 1) && (mass[6] != 2))
				{
					mass[6] = 1;
				}
			}
		}
		else if ((ax > 185) && (ax <= 320))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((mass[1] != 1) && (mass[1] != 2))
				{
					mass[1] = 1;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((mass[4] != 1) && (mass[4] != 2))
				{
					mass[4] = 1;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((mass[7] != 1) && (mass[7] != 2))
				{
					mass[7] = 1;
				}
			}
		}
		else if ((ax > 330) && (ax <= 465))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((mass[2] != 1) && (mass[2] != 2))
				{
					mass[2] = 1;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((mass[5] != 1) && (mass[5] != 2))
				{
					mass[5] = 1;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((mass[8] != 1) && (mass[8] != 2))
				{
					mass[8] = 1;
				}
			}
		}
	}
}

//void myKeyboard(int key, int a, int c)
//{
//	switch (key)
//	{
//		case '100':
//			X_signal(0);
//		case '102':
//			X_signal(1);
//		case '103':
//			X_signal(2);
//		case '4':
//			X_signal(3);
//		case '5':
//			X_signal(4);
//		case '6':
//			X_signal(5);
//		case '7':
//			X_signal(6);
//		case '8':
//			X_signal(7);
//		case '9':
//			X_signal(8);
//	}
//}

int _tmain(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("test");

	glClearColor(0, 0, 0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);

	glutDisplayFunc(Display);
	glutTimerFunc(50, timer, 0);
	glutMouseFunc(mouse_Click);
	//glutSpecialFunc(myKeyboard);
	glutMainLoop();
}

