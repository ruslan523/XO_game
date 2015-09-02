// XO.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <GL/freeglut.h>

int i = 0;
bool isFirst = false;
//int *mass = new int[9];
enum points { X, O, N };
points *point = new points[9];
int *round = new int[9];
int counter;
int cntr;

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
		if (((point[0] == X) && (point[1] == X) && (point[2] == X))
			|| ((point[3] == X) && (point[4] == X) && (point[5] == X))
			|| ((point[6] == X) && (point[7] == X) && (point[8] == X))
			|| ((point[0] == X) && (point[3] == X) && (point[6] == X))
			|| ((point[1] == X) && (point[4] == X) && (point[7] == X))
			|| ((point[2] == X) && (point[5] == X) && (point[8] == X))
			|| ((point[0] == X) && (point[3] == X) && (point[6] == X))
			|| ((point[0] == X) && (point[4] == X) && (point[8] == X))
			|| ((point[2] == X) && (point[4] == X) && (point[6] == X)))
		{
			for (int cnt = 0; cnt < 9; cnt++)
			{
				round[cnt] = 10;
				point[cnt] = X;
			}
		}
		round[0] = 6;
		point[6] = X;
		counter = 1;
		if (round[1] == 0)
		{
			point[0] = O;
			round[2] = 8;
			point[8] = X;
			counter = 3;
			if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 4)
			{
				point[4] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 2;
				point[2] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 5;
					point[5] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 5;
					point[5] = X;
				}
				else if (round[5] == 4)
				{
					point[4] = O;
					round[6] = 5;
					point[5] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 4;
					point[4] = X;
				}
			}
		}
		else if (round[1] == 1)
		{
			point[1] = O;
			round[2] = 4;
			point[4] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 0;
				point[0] = X;
				counter = 5;
				if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 3;
					point[3] = X;
				}
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 8)
			{
				point[8] = O;
				round[4] = 2;
				point[2] = X;
			}
		}
		else if (round[1] == 2)
		{
			point[2] = O;
			round[2] = 8;
			point[8] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 4)
			{
				point[4] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 7;
				point[7] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 0;
				point[0] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 4;
					point[4] = X;
				}
				else if (round[5] == 4)
				{
					point[4] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 3;
					point[3] = X;
				}
			}
		}
		else if (round[1] == 3)
		{
			point[3] = O;
			round[2] = 4;
			point[4] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 8;
				point[8] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 0;
					point[0] = X;
				}
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 8)
			{
				point[8] = O;
				round[4] = 2;
				point[2] = X;
			}
		}
		else if (round[1] == 4)
		{
			point[4] = O;
			round[2] = 2;
			point[2] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 8;
				point[8] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 5;
					point[5] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 5;
					point[5] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 5;
					point[5] = X;
				}
			}
			else if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 7;
				point[7] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 0;
					point[0] = X;
					counter = 7;
					if (round[7] == 3)
					{
						point[3] = O;
						round[8] = 5;
						point[5] = X;
					}
					else if (round[7] == 5)
					{
						point[5] = O;
						round[8] = 3;
						point[3] = X;
					}
				}
			}
			else if (round[3] == 3)
			{
				point[5] = O;
				round[4] = 5;
				point[5] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 0;
					point[0] = X;
					counter = 7;
					if (round[7] == 1)
					{
						point[1] = O;
						round[8] = 7;
						point[7] = X;
					}
					else if (round[1] == 7)
					{
						point[7] = O;
						round[8] = 1;
						point[1] = X;
					}
				}
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 3;
				point[3] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 8;
					point[8] = X;
					counter = 7;
					if (round[7] == 1)
					{
						point[1] = O;
						round[8] = 7;
						point[7] = X;
					}
					else if (round[7] == 7)
					{
						point[7] = O;
						round[8] = 1;
						point[1] = X;
					}
				}
				else if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 0;
					point[0] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 0;
					point[0] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 0;
					point[0] = X;
				}
			}
			if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 1;
				point[1] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 8;
					point[8] = X;
					counter = 7;
					if (round[7] == 3)
					{
						point[3] = O;
						round[8] = 5;
						point[5] = X;
					}
					else if (round[7] == 5)
					{
						point[5] = O;
						round[8] = 3;
						point[3] = X;
					}
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 0;
					point[0] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 0;
					point[0] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 0;
					point[0] = X;
				}
			}
			if (round[3] == 8)
			{
				point[8] = O;
				round[4] = 0;
				point[0] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 1;
					point[1] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 1;
					point[5] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 3;
					point[3] = X;
				}
			}
		}
		else if (round[1] == 5)
		{
			point[5] = O;
			round[2] = 4;
			point[4] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 8;
				point[8] = X;
				counter = 5;
				if (round[5] == 0)
				{
					point[0] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 7;
					point[7] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 0;
					point[0] = X;
				}
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 8)
			{
				point[8] = O;
				round[4] = 2;
				point[2] = X;
			}
		}
		else if (round[1] == 7)
		{
			point[7] = O;
			round[2] = 4;
			point[4] = X;
			counter = 3;
			if (round[3] == 0)
			{
				point[0] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 0;
				point[0] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 3)
				{
					point[3] = O;
					round[6] = 8;
					point[8] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 3;
					point[3] = X;
				}
				else if (round[5] == 8)
				{
					point[8] = O;
					round[6] = 3;
					point[7] = X;
				}
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 2;
				point[2] = X;
			}
			else if (round[3] == 8)
			{
				point[8] = O;
				round[4] = 2;
				point[2] = X;
			}
		}
		else if (round[1] == 8)
		{
			point[8] = O;
			round[2] = 0;
			point[0] = X;
			counter = 3;
			if (round[3] == 1)
			{
				point[1] = O;
				round[4] = 3;
				point[3] = X;
			}
			else if (round[3] == 2)
			{
				point[2] = O;
				round[4] = 3;
				point[3] = X;
			}
			else if (round[3] == 3)
			{
				point[3] = O;
				round[4] = 2;
				point[2] = X;
				counter = 5;
				if (round[5] == 1)
				{
					point[1] = O;
					round[6] = 4;
					point[4] = X;
				}
				else if (round[5] == 4)
				{
					point[4] = O;
					round[6] = 1;
					point[1] = X;
				}
				else if (round[5] == 5)
				{
					point[5] = O;
					round[6] = 1;
					point[1] = X;
				}
				else if (round[5] == 7)
				{
					point[7] = O;
					round[6] = 1;
					point[1] = X;
				}
			}
			else if (round[3] == 4)
			{
				point[4] = O;
				round[4] = 3;
				point[3] = X;
			}
			else if (round[3] == 5)
			{
				point[5] = O;
				round[4] = 3;
				point[3] = X;
			}
			else if (round[3] == 7)
			{
				point[7] = O;
				round[4] = 3;
				point[3] = X;
			}
		}
	}
	for (int j = 0; j < 9; j++)
	{
		if (point[j] == X)
		{
			X_signal(j);
		}
		else if (point[j] == O)
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
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if ((ax > 40) && (ax <= 175))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((point[0] != X) && (point[0] != O))
				{
					point[0] = O;
					round[counter] = 0;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((point[3] != X) && (point[3] != O))
				{
					point[3] = O;
					round[counter] = 3;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((point[6] != X) && (point[6] != O))
				{
					point[6] = O;
					round[counter] = 6;
				}
			}
		}
		else if ((ax > 185) && (ax <= 320))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((point[1] != X) && (point[1] != O))
				{
					point[1] = O;
					round[counter] = 1;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((point[4] != X) && (point[4] != O))
				{
					point[4] = O;
					round[counter] = 4;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((point[7] != X) && (point[7] != O))
				{
					point[7] = O;
					round[counter] = 7;
				}
			}
		}
		else if ((ax > 330) && (ax <= 465))
		{
			if ((ay > 330) && (ay <= 465))
			{
				if ((point[2] != X) && (point[2] != O))
				{
					point[2] = O;
					round[counter] = 2;
				}
			}
			else if ((ay > 185) && (ay <= 320))
			{
				if ((point[5] != X) && (point[5] != O))
				{
					point[5] = O;
					round[counter] = 5;
				}
			}
			else if ((ay > 40) && (ay <= 175))
			{
				if ((point[8] != X) && (point[8] != O))
				{
					point[8] = O;
					round[counter] = 8;
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

