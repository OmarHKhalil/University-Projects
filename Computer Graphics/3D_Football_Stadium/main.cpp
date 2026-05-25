#include <GL/glut.h>
#include <math.h>

GLUquadricObj* a = gluNewQuadric();
GLfloat position=0.0f;
GLfloat position1=0.0f;
float CX = 0;
float CZ = 0;
double xxx=0;
float EX = 0;
float EZ = 0;
float EY = 0;
double th = 0;
int right = 0;
bool opensurf=false;
bool closesurf=false;
double xx=0;
double xy =350;
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_ESCAPE: /* Escape key */
		exit(0);
		break;
	case 'w':EX   = EX + 20 * cos(th);
		EZ = EZ +  3 * sin(th);
		break;
    case 'a': th -= 0.2;
		break;
	case 's': EX = EX - 20 * cos(th);
		EZ = EZ - 3 * sin(th);
		break;
	case 'd':th += 0.2;
		break;
	case 'o':
		glEnable(GL_LIGHTING);
		break;
	case 'f':
		glDisable(GL_LIGHTING);
		break;
	case 'g':
		opensurf = !opensurf;
		break;
    case 'h':
		closesurf = !closesurf;
		break;
	default:
		break;
	}
}
void Timer3(int)
{
    position += 1.0f;
    position1 += 1.0f;
    if (position > 750 || position1 >380) {
        position = 0;
        position1 = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(10, Timer3, 0);
}
void special(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		EY += 4.5;
		break;
	case GLUT_KEY_RIGHT:
		EY -= 4.5;
		break;
		case GLUT_KEY_DOWN:
		EY -= 4.5;
		break;

	default:
		break;
	}
}
//classes//
class lines
{
public:
    lines(double x1, double x2, double y1, double y2, double z1, double z2) {
        //front
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x1, y2, z1);
        glVertex3d(x2, y2, z1);
        glVertex3d(x2, y1, z1);
        glEnd();
        //back
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z2);
        glVertex3d(x1, y2, z2);
        glVertex3d(x2, y2, z2);
        glVertex3d(x2, y1, z2);
        glEnd();
        //left
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x1, y2, z1);
        glVertex3d(x1, y2, z2);
        glVertex3d(x1, y1, z2);
        glEnd();
        //right
        glBegin(GL_QUADS);
        glVertex3d(x2, y1, z1);
        glVertex3d(x2, y2, z1);
        glVertex3d(x2, y2, z2);
        glVertex3d(x2, y1, z2);
        glEnd();
        //up
        glBegin(GL_QUADS);
        glVertex3d(x1, y2, z1);
        glVertex3d(x1, y2, z2);
        glVertex3d(x2, y2, z2);
        glVertex3d(x2, y2, z1);
        glEnd();
        //down
        glBegin(GL_QUADS);
        glVertex3d(x1, y1, z1);
        glVertex3d(x1, y1, z2);
        glVertex3d(x2, y1, z2);
        glVertex3d(x2, y1, z1);
        glEnd();
    }
};

    class goal
    {
         public:goal(int m)
         {
             //الاغوال//
             {
                 //الغول اليمين//
                 {
                     //crossbar//
                     glPushMatrix();
                     GLUquadricObj* d;
                     d = gluNewQuadric();
                     glColor3d(1, 1, 1);
                     glRotated(90, 0, 1, 0);
                     //glRotated(90, 1, 0, 0);
                     glTranslated(0, 0, -40);//x//
                     glTranslated(399, 0, 0);//z//
                     glTranslated(0, 11.05, 0);//y//
                     gluCylinder(d, 1, 1, 80, 100, 50);
                     glPopMatrix();

                     //العارضة الاولى//
                     glPushMatrix();
                     GLUquadricObj* a;
                     a = gluNewQuadric();
                     glColor3d(1, 1, 1);
                     glRotated(90, 0, 1, 0);
                     glRotated(90, 1, 0, 0);
                     glTranslated(0, 0, -11.95);
                     glTranslated(399, 0, 0);
                     glTranslated(0, 41, 0);
                     gluCylinder(a, 1, 1, 50, 100, 50);
                     glPopMatrix();

                     //العارضة الثانية//
                     glPushMatrix();
                     GLUquadricObj* b;
                     b = gluNewQuadric();
                     glColor3d(1, 1, 1);
                     glRotated(90, 0, 1, 0);
                     glRotated(90, 1, 0, 0);
                     glTranslated(0, 0, -11.95);
                     glTranslated(399, 0, 0);
                     glTranslated(0, -41, 0);
                     gluCylinder(b, 1, 1, 50, 100, 50);
                     glPopMatrix();

                     //الشبكة//
                     //الشبك اليسار//
                     {
                         //خطوط العرض//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s1(-41, -41.2, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s2(-41, -41.2, 8.76, 8.96, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s3(-41, -41.2, 6.32, 6.52, -399, -423.4);
                         glPopMatrix();
                         glPus
                         hMatrix();
                         glColor3d(1, 1, 1);
                         lines s4(-41, -41.2, 3.88, 4.08, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s5(-41, -41.2, 1.44, 1.64, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s6(-41, -41.2, -1, -0.8, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s7(-41, -41.2, -3.44, -3.24, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s8(-41, -41.2, -5.88, -5.68, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s9(-41, -41.2, -8.32, -8.12, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s10(-41, -41.2, -10.77, -10.57, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s11(-41, -41.2, -13.2, -13, -399, -423.4);
                         glPopMatrix();
                         //

                         //خطوط الطول//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s12(-41, -41.2, -13.2, 11.2, -401.44, -401.24);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s13(-41, -41.2, -13.2, 11.2, -403.88, -403.68);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s14(-41, -41.2, -13.2, 11.2, -406.32, -406.12);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s15(-41, -41.2, -13.2, 11.2, -408.76, -408.56);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s16(-41, -41.2, -13.2, 11.2, -411.2, -411);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s17(-41, -41.2, -13.2, 11.2, -413.64, -413.44);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s18(-41, -41.2, -13.2, 11.2, -416.08, -415.88);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s19(-41, -41.2, -13.2, 11.2, -418.52, -418.32);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s20(-41, -41.2, -13.2, 11.2, -420.96, -420.76);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s21(-41, -41.2, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();
                     }

                     //الشبك اليمين//
                     {
                         //خطوط العرض//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s1(41, 41.2, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s2(41, 41.2, 8.76, 8.96, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s3(41, 41.2, 6.32, 6.52, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s4(41, 41.2, 3.88, 4.08, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s5(41, 41.2, 1.44, 1.64, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s6(41, 41.2, -1, -0.8, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s7(41, 41.2, -3.44, -3.24, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s8(41, 41.2, -5.88, -5.68, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s9(41, 41.2, -8.33, -8.12, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s10(41, 41.2, -10.77, -10.57, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s11(41, 41.2, -13.2, -13, -399, -423.4);
                         glPopMatrix();
                         //

                         //خطوط الطول//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s12(41, 41.2, -13.2, 11.2, -401.44, -401.24);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s13(41, 41.2, -13.2, 11.2, -403.88, -403.68);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s14(41, 41.2, -13.2, 11.2, -406.32, -406.12);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s15(41, 41.2, -13.2, 11.2, -408.76, -408.56);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s16(41, 41.2, -13.2, 11.2, -411.2, -411);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s17(41, 41.2, -13.2, 11.2, -413.64, -413.44);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s18(41, 41.2, -13.2, 11.2, -416.08, -415.88);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s19(41, 41.2, -13.2, 11.2, -418.52, -418.32);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s20(41, 41.2, -13.2, 11.2, -420.96, -420.76);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s21(41, 41.2, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();
                         //
                     }

                     //شبك السقف//
                     {
                         //خطوط العرض//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s1(-41, 41, 11.2, 11.4, -401.44, -401.24);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s2(-41, 41, 11.2, 11.4, -403.88, -403.68);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s3(-41, 41, 11.2, 11.4, -406.32, -406.12);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s4(-41, 41, 11.2, 11.4, -408.76, -408.56);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s5(-41, 41, 11.2, 11.4, -411.2, -411);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s6(-41, 41, 11.2, 11.4, -413.64, -413.44);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s7(-41, 41, 11.2, 11.4, -416.08, -415.88);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s8(-41, 41, 11.2, 11.4, -418.52, -418.32);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s9(-41, 41, 11.2, 11.4, -420.96, -420.76);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s10(-41, 41, 11.22, 11.4, -423.4, -423.2);
                         glPopMatrix();
                         //

                         //خطوط الطول//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s11(-38.51515152, -38.31515152, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s12(-36.03030304, -35.83030304, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s13(-33.54545456, -33.34545456, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s14(-31.06060607, -30.86060607, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s15(-28.57575759, -28.37575759, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s16(-26.0909091, -25.8909091, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s17(-23.60606062, -23.40606062, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s18(-21.12121213, -20.92121213, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s19(-18.63636365, -18.43636365, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s20(-16.15151516, -15.95151516, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s21(-13.66666668, -13.46666668, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s23(-11.18181819, -10.98181819, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s24(-8.696969705, -8.496969705, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s25(-6.21212122, -6.01212122, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s26(-3.727272735, -3.527272735, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s27(-1.24242425, -1.04242425, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s28(1.242424235, 1.442424235, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s29(3.72727272, 3.92727272, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s30(6.212121205, 6.412121205, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s31(8.69696969, 8.89696969, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s32(11.18181818, 11.38181818, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s33(13.66666666, 13.86666666, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s34(16.15151515, 16.35151515, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s35(18.63636363, 18.83636363, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s36(21.12121212, 21.32121212, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s37(23.60606060, 23.80606060, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s38(26.09090909, 26.29090909, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s39(28.57575757, 28.77575757, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s40(31.06060606, 31.26060606, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s41(33.54545454, 33.74545454, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s42(36.03030303, 36.23030303, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s43(38.51515151, 38.71515151, 11.2, 11.4, -399, -423.4);
                         glPopMatrix();
                         //
                     }

                     //الشبك الخلفي//
                     {
                         //خطوط العرض//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s1(-41, 41, 8.76, 8.96, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s2(-41, 41, 6.32, 6.52, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s3(-41, 41, 3.88, 4.08, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s4(-41, 41, 1.44, 1.64, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s5(-41, 41, -1, -0.8, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s6(-41, 41, -3.44, -3.24, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s7(-41, 41, -5.88, -5.68, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s8(-41, 41, -8.32, -8.12, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s9(-41, 41, -10.76, -10.56, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s10(-41, 41, -13.2, -13, -423.4, -423.2);
                         glPopMatrix();
                         //

                         //خطوط الطول//
                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s11(-38.51515152, -38.31515152, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s12(-36.03030304, -35.83030304, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s13(-33.54545456, -33.34545456, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s14(-31.06060607, -30.86060607, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s15(-28.57575759, -28.37575759, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s16(-26.0909091, -25.8909091, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s17(-23.60606062, -23.40606062, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s18(-21.12121213, -20.92121213, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s19(-18.63636365, -18.43636365, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s20(-16.15151516, -15.95151516, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s21(-13.66666668, -13.46666668, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s23(-11.18181819, -10.98181819, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s24(-8.696969705, -8.496969705, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s25(-6.21212122, -6.01212122, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s26(-3.727272735, -3.527272735, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s27(-1.24242425, -1.04242425, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s28(1.242424235, 1.442424235, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s29(3.72727272, 3.92727272, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s30(6.212121205, 6.412121205, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s31(8.69696969, 8.89696969, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s32(11.18181818, 11.38181818, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s33(13.66666666, 13.86666666, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s34(16.15151515, 16.35151515, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s35(18.63636363, 18.83636363, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s36(21.12121212, 21.32121212, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s37(23.60606060, 23.80606060, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s38(26.09090909, 26.29090909, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s39(28.57575757, 28.77575757, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s40(31.06060606, 31.26060606, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s41(33.54545454, 33.74545454, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s42(36.03030303, 36.23030303, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();

                         glPushMatrix();
                         glColor3d(1, 1, 1);
                         lines s43(38.51515151, 38.71515151, -13.2, 11.2, -423.4, -423.2);
                         glPopMatrix();
                         //
                     }
                 }
             }
         }
};

class team_patch
{
public:team_patch(int bbb)
{
    glPushMatrix();
    glColor3d(1, 0, 0);
    lines t1(-25, -20, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    lines t2(-20, -15, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    lines t3(-15, -10, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    lines t4(-10, -5, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    lines t5(-5, 0, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    lines t6(0, 5, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    lines t7(5, 10, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    lines t8(10, 15, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(1, 0, 0);
    lines t9(15, 20, -13.2, -13.199, -445, -470);
    glPopMatrix();

    glPushMatrix();
    glColor3d(0, 0, 1);
    lines t10(20, 25, -13.2, -13.199, -445, -470);
    glPopMatrix();
}
};
//end classes//

void InitGL(void)
{
    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);				// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
    glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations


glNewList(1, GL_COMPILE);
  //كرسي
  glPushMatrix();
  glColor3f(0.7, 0.7, 0.7);
  glScaled(0.2, 0.3, 0.8);
  glTranslated(12.7, 5.2, 1.7);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1,0,0);
  glScaled(0.15, 1.1, 0.9);
  glTranslated(17, 0.2, 1.5);
  glutSolidCube(2);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1,0,0);
  glScaled(0.8, 0.15, 0.9);
  glTranslated(2, -5, 1.5);
  glutSolidCube(2);
  glPopMatrix();

  GLUquadricObj* b = gluNewQuadric();
  glPushMatrix();
  glColor3f(0, 1, 0);
  glRotated(90, 1, 0, 0);
  //glScaled(0.5, 1, 0.5);
  glTranslated(1.7, 1.3, 0.9);
  gluCylinder(b, 0.3, 0.3, 0.9, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glScaled(1, 0.06, 1);
  glTranslated(1.7, -30, 1.3);
  glutSolidCube(0.8);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glScaled(0.1, 0.1, 1);
  glTranslated(17, -10, 0.6);
  glutSolidCube(0.8);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glScaled(0.1, 0.1, 1);
  glTranslated(17, -10, 2);
  glutSolidCube(0.8);
  glPopMatrix();
  glPushMatrix();
  glColor3f(1, 0, 0);
  glScaled(0.1, 0.8, 0.1);
  glTranslated(17, -0.8, 2.35);
  glutSolidCube(0.8);
  glPopMatrix();
  glPushMatrix();
  glColor3f(1, 0, 0);
  glScaled(0.1, 0.8, 0.1);
  glTranslated(17, -0.8, 23.5);
  glutSolidCube(0.8);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 1, 1);
  glScaled(0.5, 0.1, 0.1);
  glTranslated(3.4, -2.8, 2.35);
  glutSolidCube(0.8);
  glPopMatrix();
  glPushMatrix();
  glColor3f(1, 1, 1);
  glScaled(0.5, 0.1, 0.1);
  glTranslated(3.4, -2.8, 23.5);
  glutSolidCube(0.8);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 0, 1);
  glScaled(0.1, 0.15, 0.1);
  glTranslated(25.5, 9, 11);
  glutSolidCube(0.8);
  glPopMatrix();
  glPushMatrix();
  glColor3f(1, 0, 1);
  glScaled(0.1, 0.15, 0.1);
  glTranslated(25.5, 9, 16);
  glutSolidCube(0.8);
  glPopMatrix();
  glEndList();





  glNewList(2, GL_COMPILE);
  //الدكه
  glPushMatrix();
  //GLUquadricObj* a = gluNewQuadric();
  double eq[4] = { 1, 0, 0, 0.6 };
  double eq1[4] = { 0, 1, 0, -1 };
  glPushMatrix();
  glEnable(GL_CLIP_PLANE0);
  glEnable(GL_CLIP_PLANE1);
  glClipPlane(GL_CLIP_PLANE0, eq);
  glClipPlane(GL_CLIP_PLANE1, eq1);
  glColor3f(0,0,1);
  glTranslated(0, 0.8, 0);
  gluCylinder(a, 3, 3, 12, 50, 30);
  glDisable(GL_CLIP_PLANE1);
  glDisable(GL_CLIP_PLANE0);
  glColor3f(1, 0.5, 0.8);
  glTranslated(0, 0, 0);
  gluPartialDisk(a, 0, 3, 30, 25, 360, 180);
  glTranslated(0, 0, 12);
  gluPartialDisk(a, 0, 3, 30, 25, 360, 180);
  glScaled(0.1, 3, 0.1);
  glColor3f(1, 0.5, 0.8);
  glTranslated(-1, 0, 0);
  glutSolidCube(2);
  glPopMatrix();

  glPushMatrix();
  glScaled(0.1, 3, 0.1);
  glColor3f(0.1, 0.5, 0.8);
  glTranslated(-0.2, 0.265, 0);
  glutSolidCube(2);
  glPopMatrix();
  glPushMatrix();
  glScaled(0.1, 0.1, 6);
  glColor3f(0.1, 0.5, 0.8);
  glTranslated(-6.5, 37.5, 1);
  glutSolidCube(2);
  glPopMatrix();

  glPushMatrix();
  glScaled(0.03, 1, 4);
  glColor3f(1,1,1);
  glTranslated(100, -0.5, 1.5);
  glutSolidCube(3);
  glPopMatrix();

  glPushMatrix();
  glScaled(1.5, 0.1, 4);
  glColor3f(0.1, 0.5, 0.8);
  glTranslated(0.5, -20, 1.5);
  glutSolidCube(3);
  glPopMatrix();
  double eq2[4] = { 3.5, -4,5,-8.5 };
  glPushMatrix();
  glEnable(GL_CLIP_PLANE0);
  glClipPlane(GL_CLIP_PLANE0, eq2);
  glScaled(1, 1, 0.005);
  glColor3f(0, 0, 1);
  glTranslated(1.5, -0.65, 0.5);
  glutSolidCube(3);
  glDisable(GL_CLIP_PLANE0);
  glPopMatrix();
  double eq3[4] = { 3.5,-4,0,-8.5 };
  glPushMatrix();
  glEnable(GL_CLIP_PLANE0);
  glClipPlane(GL_CLIP_PLANE0, eq3);
  glScaled(1, 1, 0.009);
  glColor3f(0, 0, 1);
  glTranslated(1.5, -0.6, 1335);
  glutSolidCube(3);
  glDisable(GL_CLIP_PLANE0);
  glPopMatrix();
  glPopMatrix();
  glEndList();

 glNewList(3, GL_COMPILE);
 //اعلان
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslated(224, -9, -410);
 glTranslated(0, 0, position);
 glScaled(0.1, 0.9, 0.9);
 glutWireCube(1.5);
 glPopMatrix();

 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslated(224, -9, -405);
 glTranslated(0, 0, position);
 glRotated(90, 0, 1, 0);
 gluDisk(a, 0.55, 0.75, 50, 50);
 glPopMatrix();

 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslated(224, -9, -398);
 glTranslated(0, 0, position);
 glTranslated(0, 0, -2);
 glRotated(40, 1, 0, 0);
 glScaled(0.1, 0.85, 0.1);
 glutSolidCube(1.5);
 glPopMatrix();


 glPushMatrix();
 glTranslated(224, -9, -398);
 glTranslated(0, 0, position);
 glColor3f(1, 0, 1);
 glTranslated(0, 0, -2);
 glRotated(40, -1, 0, 0);
 glScaled(0.1, 0.85, 0.1);
 glutSolidCube(1.5);
 glPopMatrix();

 //p
 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslated(224.4, -8.7, -370);
 glTranslated(0, 0, -15);
 glRotated(90, 0, 1, 0);
 gluDisk(a, 0.25, 0.45, 50, 50);
 glPopMatrix();

 glPushMatrix();
 glColor3f(1, 0, 0);
 glTranslated(224.4, -9, -385.35);
 glScaled(0.001, 0.8, 0.2);
 glutSolidCube(1);
 glPopMatrix();
 //5

 glPushMatrix();
 glTranslated(224.4, -8.5, -384);
 glColor3f(1, 0, 0);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -8.65, -384.2);
 glScaled(0.1, 0.4, 0.1);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -8.9, -384.05);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -9.05, -383.9);
 glScaled(0.1, 0.4, 0.1);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -9.2, -384.05);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();

 //5

 glPushMatrix();
 glTranslated(224.4, -8.5, -383.25);
 glColor3f(1, 0, 0);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -8.65, -383.4);
 glScaled(0.1, 0.4, 0.1);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -8.9, -383.25);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(1, 0, 1);
 glTranslated(224.4, -9.05, -383.1);
 glScaled(0.1, 0.4, 0.1);
 glutSolidCube(1);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 1);
 glTranslated(224.4, -9.2, -383.25);
 glScaled(0.1, 0.1, 0.4);
 glutSolidCube(1);
 glPopMatrix();
 glEndList();

int position =5;

  glNewList(3, GL_COMPILE);
  //اعلان
  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslated(198.9, -0.6, -410);
  glTranslated(0, 0, position);
  glScaled(0.1, 0.9, 0.9);
  glutWireCube(1.5);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslated(198.9, -0.6, -405);
  glTranslated(0, 0, position);
  glRotated(90, 0, 1, 0);
  gluDisk(a, 0.55, 0.75, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslated(198.9, -0.6, -398);
  glTranslated(0, 0, position);
  glTranslated(0, 0, -2);
  glRotated(40, 1, 0, 0);
  glScaled(0.1, 0.85, 0.1);
  glutSolidCube(1.5);
  glPopMatrix();


  glPushMatrix();
  glTranslated(198.9, -0.6, -398);
  glTranslated(0, 0, position);
  glColor3f(1, 0, 1);
  glTranslated(0, 0, -2);
  glRotated(40, -1, 0, 0);
  glScaled(0.1, 0.85, 0.1);
  glutSolidCube(1.5);
  glPopMatrix();

  //p
  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslated(198.9, -0.4, -370);
  glTranslated(0, 0, -15);
  glRotated(90, 0, 1, 0);
  gluDisk(a, 0.25, 0.45, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslated(198.9, -0.9, -385.35);
  glScaled(0.001, 0.8, 0.2);
  glutSolidCube(1);
  glPopMatrix();
  //5

  glPushMatrix();
  glTranslated(198.9, -0.2, -384);
  glColor3f(1, 0, 0);
  glScaled(0.1, 0.1, 0.4);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0, 0, 1);
  glTranslated(198.9, -0.35, -384.2);
  glScaled(0.1, 0.4, 0.1);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0, 0, 1);
  glTranslated(198.9, -0.6, -384.05);
  glScaled(0.1, 0.1, 0.4);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0, 0, 1);
  glTranslated(198.9, -0.75, -383.9);
  glScaled(0.1, 0.4, 0.1);
  glutSolidCube(1);
  glPopMatrix();
  glPushMatrix();
  glColor3f(0, 0, 1);
  glTranslated(198.9, -0.90, -384.05);
  glScaled(0.1, 0.1, 0.4);
  glutSolidCube(1);
  glPopMatrix();

  //5

  glPushMatrix();
  glTranslated(198.9, -0.2, -383.25);
  glColor3f(1, 0, 0);
  glScaled(0.1, 0.1, 0.4);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glColor3f(0, 0, 1);
  glTranslated(198.9, -0.35, -383.4);
  glScaled(0.1, 0.4, 0.1);
  glutSolidCube(1);
  glPopMatrix();
  glEndList();












}

void ReSizeGLScene(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0f, (GLfloat)w / (GLfloat)h, 0.1f, 10000.0f);
        //gluOrtho2D(-50, 50, -50, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
bool ss=true;
void timer(int a)
{


if (xx<350){
        xx = xx + 0.4;


}
if(opensurf==false){
xx=0;
}
if(closesurf==true && xy<=0){



    xy=xy-0.5;
    }


else{
    xy=0;
}
    glutPostRedisplay();
    glutTimerFunc(10, timer, 100);

}







void DrawGLScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


    //CAMERA LOOK
    CX = EX + cos(th);
	CZ = EZ + sin(th);
	gluLookAt(EX, EY, EZ, CX, EY, CZ, 0, 1, 0);
    //*CAMERA LOOK



    //طريق رمادي
    glPushMatrix();
    glTranslated(0,-14.3,0);
    glScaled(4000,1,4000);
    glColor3f(128/255.0, 128/255.0, 128/255.0);
    glutSolidCube(2);
    glPopMatrix();

    //العشب
    glPushMatrix();
    glTranslated(0,-14.2,0);
    glScaled(200,1,400);
    glColor3f(0.2,0.5,0.2);
    glutSolidCube(2);
    glPopMatrix();

//بقسم ال

//

    // خطوط الملعب//
    {
        //(خط الطول الاول(خلفي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l1(-201, -199, -13.2, -13.199, 400, -400);
        glPopMatrix();

        //(خط الطول الثاني(امامي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l2(199, 201, -13.2, -13.199, -400, 400);
        glPopMatrix();

        //خط العرض يلي بالنص//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l3(200, -200, -13.2, -13.199, -1, 1);
        glPopMatrix();

        //(خط العرض الثاني(يسار//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l4(200, -200, -13.2, -13.199, -400, -398);
        glPopMatrix();

        //خط العرض الثالث//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l5(200, -200, -13.2, -13.199, 400, 398);
        glPopMatrix();
    }

    //penalty area (right)//
    {
        //خط العرض الخارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l6(-75, 75, -13.2, -13.199, 250, 252);
        glPopMatrix();

        //(خط الطول اليمين (خارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l7(75, 77, -13.2, -13.199, 400, 250);
        glPopMatrix();

        //(خط الطول اليسار (خارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l8(-77, -75, -13.2, -13.199, 400, 250);
        glPopMatrix();

        //خط العرض الداخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l9(-40, 40, -13.2, -13.199, 325, 327);
        glPopMatrix();

        //(خط الطول اليسار (داخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l10(40, 42, -13.2, -13.199, 400, 325);
        glPopMatrix();

        //(خط الطول اليمين (داخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l11(-42, -40, -13.2, -13.199, 400, 325);
        glPopMatrix();

        //نقطة الجزاء اليمين//
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, 290, 0);
        gluDisk(b, 0, 2, 100, 100);
        glPopMatrix();

        //نصف الدائرة لمنطقة الجزاء//
        glPushMatrix();
        GLUquadricObj* a;
        a = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, 250, 0);
        gluPartialDisk(a, 20, 22, 100, 100, 90, 180);
        glPopMatrix();
    }

    //penalty area (left)//
    {
        //خط العرض الخارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l12(75, -75, -13.2, -13.199, -250, -252);
        glPopMatrix();

        //(خط الطول اليمين (خارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l13(-75, -77, -13.2, -13.199, -400, -250);
        glPopMatrix();

        //(خط الطول اليسار (خارجي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l14(77, 75, -13.2, -13.199, -400, -250);
        glPopMatrix();

        ///خط العرض الداخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l15(40, -40, -13.2, -13.199, -325, -327);
        glPopMatrix();

        //(خط الطول اليسار (داخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l16(-40, -42, -13.2, -13.199, -400, -325);
        glPopMatrix();

        //(خط الطول اليمين (داخلي//
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines l17(42, 40, -13.2, -13.199, -400, -325);
        glPopMatrix();

        //نقطة الجزاء اليمين//
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, -290, 0);
        gluDisk(b, 0, 2, 100, 100);
        glPopMatrix();

        //نصف الدائرة لمنطقة الجزاء//
        glPushMatrix();
        GLUquadricObj* a;
        a = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, -250, 0);
        gluPartialDisk(a, 20, 22, 100, 100, -90, 180);
        glPopMatrix();
    }

    //دائرة منتصف الملعب//
    {
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 1, 0);
        glTranslated(0, 0, 13.2);
        gluDisk(b, 38, 40, 100, 100);
        glPopMatrix();
    }

    //نقطة منتصف الملعب//
    {
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        gluDisk(b, 0, 2, 100, 100);
        glPopMatrix();
    }

    //الزوايا//
    {
        //الزاوية الثانية يسار//
        glPushMatrix();
        GLUquadricObj* a;
        a = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, -400, 0);
        glTranslated(200, 0, 0);
        gluPartialDisk(a, 13, 15, 100, 100, -90, 90);
        glPopMatrix();

        //الزاوية الاولى يسار//
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, -400, 0);
        glTranslated(-200, 0, 0);
        gluPartialDisk(b, 13, 15, 100, 100, 90, -90);
        glPopMatrix();

        //الزاوية الاولى يمين//
        glPushMatrix();
        GLUquadricObj* c;
        c = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, 400, 0);
        glTranslated(-200, 0, 0);
        gluPartialDisk(c, 13, 15, 100, 100, 90, 90);
        glPopMatrix();

        //الزاوية الثانية يمين//
        glPushMatrix();
        GLUquadricObj* d;
        d = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, 13.2);
        glTranslated(0, 400, 0);
        glTranslated(200, 0, 0);
        gluPartialDisk(d, 13, 15, 100, 100, -90, -90);
        glPopMatrix();
    }

    //الاعلام بالزوايا//
    {
        //علم الزاوية الثانية يسار يلي لونو احمر//
        glPushMatrix();
        GLUquadricObj* a;
        a = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 0, 1, 0);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, -2);
        glTranslated(399, 0, 0);
        glTranslated(0, 200, 0);
        gluCylinder(a, 0.5, 0.5, 20, 100, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3d(1, 0, 0);
        lines l18(200, 210, -3, 2, -399, -399.00001);
        glPopMatrix();

        //علم الزاوية الاولى يسار يلي لونو ازرق//
        glPushMatrix();
        GLUquadricObj* b;
        b = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 0, 1, 0);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, -2);
        glTranslated(399, 0, 0);
        glTranslated(0, -200, 0);
        gluCylinder(b, 0.5, 0.5, 20, 100, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 1);
        lines l19(-200, -210, -3, 2, -399, -399.00001);
        glPopMatrix();

        //علم الزاوية الاولى يمين يلي لونو ازرق//
        glPushMatrix();
        GLUquadricObj* c;
        c = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 0, 1, 0);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, -2);
        glTranslated(-399, 0, 0);
        glTranslated(0, -200, 0);
        gluCylinder(c, 0.5, 0.5, 20, 100, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 1);
        lines l20(-200, -210, -3, 2, 399, 399.00001);
        glPopMatrix();

        //علم الزاوية الثانية يمين يلي لونو احمر//
        glPushMatrix();
        GLUquadricObj* d;
        d = gluNewQuadric();
        glColor3d(1, 1, 1);
        glRotated(90, 0, 1, 0);
        glRotated(90, 1, 0, 0);
        glTranslated(0, 0, -2);
        glTranslated(-399, 0, 0);
        glTranslated(0, 200, 0);
        gluCylinder(d, 0.5, 0.5, 20, 100, 50);
        glPopMatrix();

        glPushMatrix();
        glColor3d(1, 0, 0);
        lines l21(200, 210, -3, 2, 399, 399.00001);
        glPopMatrix();
    }

    //الاغوال//
    {
        goal(1);
    }
    {
        glPushMatrix();
        glRotated(180, 0, 1, 0);
        goal(1);
        glPopMatrix();
    }

    //علم الفريق//
    {
        team_patch(1);
    }
    {
        glPushMatrix();
        glTranslated(0, 0, 910);
        team_patch(1);
        glPopMatrix();
    }

    //مقاعد غرفة الملابس//
    {
        glPushMatrix();
        glColor3d(1, 1, 1);
        lines g1(790, 1000, -13.2, 1.8, 170, 190);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines n1(790, 1000, -13.2, -1.8, 170, 171);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines s1(790, 1000, 1.79, 1.8, 170, 171);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines s2(790, 1000, 1.79, 1.8, 175, 176);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines s3(790, 1000, 1.79, 1.8, 180, 181);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines s4(790, 1000, 1.79, 1.8, 185, 186);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines s5(790, 1000, 1.79, 1.8, 189, 190);
        glPopMatrix();


        glPushMatrix();
        glColor3d(1, 1, 1);
        lines g2(790, 1000, -13.2, 1.8, -170, -190);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines n2(790, 1000, -13.2, -1.8, -170, -171);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines c1(790, 1000, 1.79, 1.8, -170, -171);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines c2(790, 1000, 1.79, 1.8, -175, -176);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines c3(790, 1000, 1.79, 1.8, -180, -181);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines c4(790, 1000, 1.79, 1.8, -185, -186);
        glPopMatrix();

        glPushMatrix();
        glColor3d(0, 0, 0);
        lines c5(790, 1000, 1.79, 1.8, -189, -190);
        glPopMatrix();
    }

    //زلمة
    glPushMatrix();
    glTranslated(280,-0.3,0);
    glScaled(1,3.8,1);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
    glPopMatrix();







    //حافة1
    glPushMatrix();
    glTranslated(0,-4.5,500);
    glScaled(602,27,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();


    //حافة2
    glPushMatrix();
    glTranslated(0,-4.5,-500);
    glScaled(602,27,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //حافة3
    glPushMatrix();
    glTranslated(300,-4.5,260);
    glRotated(90,0,1,0);
    glScaled(490,27,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //حافة3
    glPushMatrix();
    glTranslated(300,-4.5,-260);
    glRotated(90,0,1,0);
    glScaled(490,27,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //حافة3
    glPushMatrix();
    glTranslated(300,4,0);
    glRotated(90,0,1,0);
    glScaled(490,11,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();




    //حافة3
    glPushMatrix();
    glTranslated(545,-0.6,0);

    glScaled(490,2,35);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glPopMatrix();

    //حافة3
    glPushMatrix();
    glTranslated(545,-17,16);
    glRotated(90,1,0,0);
    glScaled(490,2,35);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(790,0,100);
    glRotated(90,0,1,0);
    glScaled(170,60,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(790,0,-100);
    glRotated(90,0,1,0);
    glScaled(170,60,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1000,0,100);
    glRotated(90,0,1,0);
    glScaled(170,60,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(1000,0,0);
    glRotated(90,0,1,0);
    glScaled(170,60,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1000,0,-100);
    glRotated(90,0,1,0);
    glScaled(170,60,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();



    glPushMatrix();
    glTranslated(895,0,-185);

    glScaled(220,60,1);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glPopMatrix();
glPushMatrix();


    glTranslated(895,0,185);

    glScaled(220,60,1);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(895,30,0);
    glRotated(90,1,0,0);
    glScaled(220,390,1);
    glColor3f(1,1,0);
    glutSolidCube(1);
    glPopMatrix();


    glPushMatrix();
    glTranslated(790,15,0);
    glRotated(90,0,1,0);
    glScaled(170,30,1);
    glColor3f(1,0,0);
    glutSolidCube(1);
    glPopMatrix();




    //حافة3
    glPushMatrix();
    glTranslated(545,-17,-16);
    glRotated(90,1,0,0);
    glScaled(490,2,35);
    glColor3f(0,0,1);
    glutSolidCube(1);
    glPopMatrix();


    //حافة4
    glPushMatrix();
    glTranslated(-300,-4.5,0);
    glRotated(90,0,1,0);
    glScaled(1000,27,2);
    glColor3f(0.3,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1
    glPushMatrix();
    glTranslated(305,2.4,0);
    glRotated(90,0,1,0);
    glScaled(1018,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج11
    glPushMatrix();
    glTranslated(313,4.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();


    //ارض مدرج12
    glPushMatrix();
    glTranslated(313,4.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();

    //ارض مدرج111
    glPushMatrix();
    glTranslated(321,6.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج112
    glPushMatrix();
    glTranslated(321,6.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();


    //ارض مدرج1111
    glPushMatrix();
    glTranslated(329,8.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
    glPushMatrix();
    glTranslated(329,8.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1111
    glPushMatrix();
    glTranslated(337,10.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
    glPushMatrix();
    glTranslated(337,10.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();


     //ارض مدرج1111
    glPushMatrix();
    glTranslated(345,12.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
    glPushMatrix();
    glTranslated(345,12.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();
    //oirjtgoirtjgpotr4gporkgoprkgpoerkgoperk spooookkkkkkk



     //ارض مدرج1111
    glPushMatrix();
    glTranslated(353,14.4,272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
    glPushMatrix();
    glTranslated(353,14.4,-272);
    glRotated(90,0,1,0);
    glScaled(474,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1111
glPushMatrix();
glTranslated(361,16.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(361,16.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(369,18.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(369,18.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(377,20.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(377,20.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(385,22.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(385,22.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(393,24.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(393,24.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();
//sppppppppppppppooooooooooooookkkkkkkkkkk




    //ارض مدرج1111
glPushMatrix();
glTranslated(401,26.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(401,26.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(409,28.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(409,28.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(417,30.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(417,30.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(425,32.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(425,32.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(433,34.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(433,34.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();





//ارض مدرج1111
glPushMatrix();
glTranslated(441,36.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(441,36.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(449,38.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(449,38.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(457,40.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(457,40.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(465,42.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(465,42.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(473,44.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(473,44.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();


//jlhfouihfoiernfokewnfoiewnfofwnefoiwofiwbnfowib


    //ارض مدرج2
    glPushMatrix();
    glTranslated(-305,2.4,0);
    glRotated(90,0,1,0);
    glScaled(1018,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج11
glPushMatrix();
glTranslated(-313,4.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج12
glPushMatrix();
glTranslated(-313,4.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج111
glPushMatrix();
glTranslated(-321,6.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج112
glPushMatrix();
glTranslated(-321,6.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-329,8.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-329,8.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-337,10.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-337,10.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-345,12.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-345,12.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();





    //ارض مدرج1111
glPushMatrix();
glTranslated(-401,26.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-401,26.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-409,28.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-409,28.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-417,30.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-417,30.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();



//ارض مدرج1111
glPushMatrix();
glTranslated(-353,14.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-353,14.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-361,16.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-361,16.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-369,18.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-369,18.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-377,20.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-377,20.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-385,22.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-385,22.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-393,24.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-393,24.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();





// ارض مدرج1111
glPushMatrix();
glTranslated(-425, 32.4, 272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1112
glPushMatrix();
glTranslated(-425, 32.4, -272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1111
glPushMatrix();
glTranslated(-433, 34.4, 272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.3, 0.3, 0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1112
glPushMatrix();
glTranslated(-433, 34.4, -272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.3, 0.3, 0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1111
glPushMatrix();
glTranslated(-441, 36.4, 272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1112
glPushMatrix();
glTranslated(-441, 36.4, -272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1111
glPushMatrix();
glTranslated(-449, 38.4, 272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.3, 0.3, 0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1112
glPushMatrix();
glTranslated(-449, 38.4, -272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.3, 0.3, 0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1111
glPushMatrix();
glTranslated(-457, 40.4, 272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

// ارض مدرج1112
glPushMatrix();
glTranslated(-457, 40.4, -272);
glRotated(90, 0, 1, 0);
glScaled(474, 2, 8);
glColor3f(0.6, 0.3, 0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();




//ارض مدرج1111
glPushMatrix();
glTranslated(-465,42.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-465,42.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1111
glPushMatrix();
glTranslated(-473,44.4,272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-473,44.4,-272);
glRotated(90,0,1,0);
glScaled(474,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

glNewList(144, GL_COMPILE);
//ارض مدرج1112
glPushMatrix();

glScaled(474,2,8);

glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();
glEndList();

glPushMatrix();
glTranslated(-490,46.7,-272);
glRotated(90,0,1,0);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();

glPushMatrix();
glTranslated(-498,48.7,-272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();

glPushMatrix();
glTranslated(-490,46.7,272);
glRotated(90,0,1,0);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();

glPushMatrix();
glTranslated(-498,48.7,272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();


glPushMatrix();
glTranslated(490,46.7,-272);
glRotated(90,0,1,0);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();

glPushMatrix();
glTranslated(498,48.7,-272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();


glPushMatrix();
glTranslated(490,46.7,272);
glRotated(90,0,1,0);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();

glPushMatrix();
glTranslated(498,48.7,272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();



glPushMatrix();
glTranslated(715,102,272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();

glPushMatrix();
glTranslated(707,100,272);
glColor3f(0.3,0.3,0.6);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();



glPushMatrix();
glTranslated(-715,102,272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();

glPushMatrix();
glTranslated(-707,100,272);
glColor3f(0.3,0.3,0.6);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();


glPushMatrix();
glTranslated(-715,102,-272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();

glPushMatrix();
glTranslated(-707,100,-272);
glColor3f(0.3,0.3,0.6);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,-16);

}
glPopMatrix();




glPushMatrix();
glTranslated(715,102,-272);
glColor3f(0.6,0.3,0.3);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();

glPushMatrix();
glTranslated(707,100,-272);
glColor3f(0.3,0.3,0.6);
glRotated(90,0,1,0);
for(int i=0;i<13;i++){
    glCallList(144);
    glTranslated(0,4,16);

}
glPopMatrix();









    //ارض مدرج3
    glPushMatrix();
    glTranslated(0,2.4,505);
    glScaled(610,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();







    //ارض مدرج1112
     glPushMatrix();
    glTranslated(175,4.4,513);
    glScaled(284,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
     glPushMatrix();
    glTranslated(-175,4.4,513);
    glScaled(284,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
     glPushMatrix();
    glTranslated(167,6.4,521);
    glScaled(268,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
     glPushMatrix();
    glTranslated(-167,6.4,521);
    glScaled(268,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();




    //ارض مدرج1112
     glPushMatrix();
    glTranslated(167,8.4,529);
    glScaled(268,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();



    //ارض مدرج1112
     glPushMatrix();
    glTranslated(-167,8.4,529);
    glScaled(268,2,8);
    glColor3f(0.6,0.3,0.3);
    glutSolidCube(1);
    glPopMatrix();




    //ارض مدرج1112
glPushMatrix();
glTranslated(167,10.4,537);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,10.4,537);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,12.4,545);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,12.4,545);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,14.4,553);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,14.4,553);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,16.4,561);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,16.4,561);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,18.4,569);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,18.4,569);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,20.4,577);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,20.4,577);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,22.4,585);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,22.4,585);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,24.4,593);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,24.4,593);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();



//ارض مدرج1112
glPushMatrix();
glTranslated(167,26.4,601);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,26.4,601);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,28.4,609);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,28.4,609);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,30.4,617);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,30.4,617);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,32.4,625);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,32.4,625);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,34.4,633);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,34.4,633);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();


//ارض مدرج1112
glPushMatrix();
glTranslated(167,36.4,641);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,36.4,641);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,38.4,649);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,38.4,649);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,40.4,657);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,40.4,657);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,42.4,665);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,42.4,665);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();


//ارض مدرج1112
glPushMatrix();
glTranslated(167,44.4,673);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,44.4,673);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();







    //ارض مدرج4
    glPushMatrix();
    glTranslated(0,2.4,-505);
    glScaled(610,2,8);
    glColor3f(0.3,0.3,0.6);
    glutSolidCube(1);
    glPopMatrix();





    //ارض مدرج1112
glPushMatrix();
glTranslated(175,4.4,-513);
glScaled(284,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-175,4.4,-513);
glScaled(284,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,6.4,-521);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,6.4,-521);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,8.4,-529);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,8.4,-529);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,10.4,-537);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,10.4,-537);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,12.4,-545);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,12.4,-545);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,14.4,-553);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,14.4,-553);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,16.4,-561);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,16.4,-561);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,18.4,-569);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,18.4,-569);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();


//ارض مدرج1112
glPushMatrix();
glTranslated(-167,20.4,-577);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,20.4,-577);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,22.4,-585);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,22.4,-585);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,24.4,-593);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,24.4,-593);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,26.4,-601);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,26.4,-601);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180, 1, 0, 0);
glutSolidCube(1);
glPopMatrix();



//ارض مدرج1112
glPushMatrix();
glTranslated(167,28.4,-609);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,28.4,-609);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,30.4,-617);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,30.4,-617);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,32.4,-625);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,32.4,-625);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,34.4,-633);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,34.4,-633);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,36.4,-641);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,36.4,-641);
glRotated(180,1,0,0);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glutSolidCube(1);
glPopMatrix();


//ارض مدرج1112
glPushMatrix();
glTranslated(167,38.4,-649);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,38.4,-649);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,40.4,-657);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,40.4,-657);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,42.4,-665);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,42.4,-665);
glScaled(268,2,8);
glColor3f(0.3,0.3,0.6);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(167,44.4,-673);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();

//ارض مدرج1112
glPushMatrix();
glTranslated(-167,44.4,-673);
glScaled(268,2,8);
glColor3f(0.6,0.3,0.3);
glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();


glNewList(133, GL_COMPILE);
glPushMatrix();

glScaled(268,2,8);

glRotated(180,1,0,0);
glutSolidCube(1);
glPopMatrix();
glEndList();


//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,46.7,-690);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();




//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,48.7,-698);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();





//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,46.7,-690);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();




//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,48.7,-698);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();












//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,46.7,690);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();

//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,100.7,904);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();

//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,100.7,904);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();

//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,100.7,-904);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();




//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,100.7,-904);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();





//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,48.7,698);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();



//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,102.7,912);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();


//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,102.7,912);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();








//new st
//ارض مدرج111
glPushMatrix();
glTranslated(-167,102.7,-912);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();


//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,102.7,-912);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,-16);
}
glPopMatrix();











//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,46.7,690);
glColor3f(0.6,0.3,0.3);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();




//new st
//ارض مدرج111
glPushMatrix();
glTranslated(167,48.7,698);
glColor3f(0.3,0.3,0.6);
for(int i=0;i<13;i++){


glCallList(133);
glTranslated(0,4,16);
}
glPopMatrix();

















//درح اسود زاوية
glPushMatrix();
glTranslated(-370,43,-673);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);

glPopMatrix();



glPushMatrix();
glTranslated(-370,42.2,-670);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();



glPushMatrix();
glTranslated(-370, 41.4, -667);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 40.6, -664);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 39.8, -661);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 39.0, -658);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 38.2, -655);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 37.4, -652);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 36.6, -649);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 35.8, -646);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 35.0, -643);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 34.2, -640);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 33.4, -637);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 32.6, -634);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 31.8, -631);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 31.0, -628);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 30.2, -625);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 29.4, -622);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370,43,673);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370,42.2,670);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 41.4, 667);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 40.6, 664);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 39.8, 661);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 39.0, 658);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 38.2, 655);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 37.4, 652);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 36.6, 649);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 35.8, 646);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 35.0, 643);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 34.2, 640);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 33.4, 637);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 32.6, 634);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 31.8, 631);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 31.0, 628);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 30.2, 625);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 29.4, 622);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
//درح اسود زاوية
glPushMatrix();
glTranslated(370,43,-673);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370,42.2,-670);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 41.4, -667);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 40.6, -664);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 39.8, -661);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 39.0, -658);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 38.2, -655);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 37.4, -652);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 36.6, -649);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 35.8, -646);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 35.0, -643);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 34.2, -640);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 33.4, -637);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 32.6, -634);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 31.8, -631);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 31.0, -628);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 30.2, -625);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 29.4, -622);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
//درح اسود زاوية
glPushMatrix();
glTranslated(370,43,673);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370,42.2,670);
glScaled(218,1.5,7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 41.4, 667);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 40.6, 664);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 39.8, 661);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 39.0, 658);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 38.2, 655);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 37.4, 652);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 36.6, 649);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 35.8, 646);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 35.0, 643);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 34.2, 640);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 33.4, 637);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 32.6, 634);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 31.8, 631);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 31.0, 628);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 30.2, 625);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 29.4, 622);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370, 28.6, -619);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 27.8, -616);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 27.0, -613);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 26.2, -610);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 25.4, -607);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 24.6, -604);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 23.8, -601);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 23, -598);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 22.2, -595);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 21.4, -592);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 20.6, -589);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 19.8, -586);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 19, -583);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 18.2, -580);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370, 28.6, 619);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 27.8, 616);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 27.0, 613);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 26.2, 610);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 25.4, 607);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 24.6, 604);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 23.8, 601);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 23, 598);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 22.2, 595);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 21.4, 592);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 20.6, 589);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 19.8, 586);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 19, 583);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 18.2, 580);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 28.6, -619);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 27.8, -616);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 27.0, -613);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 26.2, -610);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 25.4, -607);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 24.6, -604);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 23.8, -601);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 23, -598);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 22.2, -595);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 21.4, -592);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 20.6, -589);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 19.8, -586);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 19, -583);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 18.2, -580);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 28.6, 619);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 27.8, 616);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 27.0, 613);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 26.2, 610);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 25.4, 607);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 24.6, 604);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 23.8, 601);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 23, 598);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 22.2, 595);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 21.4, 592);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 20.6, 589);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 19.8, 586);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 19, 583);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 18.2, 580);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370, 17.4, -577);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 16.6, -574);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 15.8, -571);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 15, -568);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 14.2, -565);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 13.4, -562);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 12.6, -559);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 11.8, -556);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 11, -553);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 10.2, -550);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 9.4, -547);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();



glPushMatrix();
glTranslated(-370, 9.4, -544);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 8.6, -541);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370, 17.4, 577);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 16.6, 574);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 15.8, 571);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 15, 568);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 14.2, 565);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 13.4, 562);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 12.6, 559);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 11.8, 556);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 11, 553);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 10.2, 550);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 9.4, 547);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 9.4, 544);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 8.6, 541);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 17.4, -577);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 16.6, -574);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 15.8, -571);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 15, -568);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 14.2, -565);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 13.4, -562);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 12.6, -559);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 11.8, -556);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 11, -553);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 10.2, -550);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 9.4, -547);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 9.4, -544);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 8.6, -541);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 17.4, 577);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 16.6, 574);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 15.8, 571);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 15, 568);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 14.2, 565);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 13.4, 562);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 12.6, 559);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 11.8, 556);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 11, 553);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 10.2, 550);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 9.4, 547);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 9.4, 544);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 8.6, 541);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(-370, 7.8, -538);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 7.0, -535);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 6.2, -532);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 5.4, -529);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 4.6, -526);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 3.8, -523);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 3.0, -520);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 2.2, -517);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 1.4, -514);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 0.6, -511);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, -0.2, -508);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, -1.0, -505);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 7.8, 538);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 7.0, 535);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 6.2, 532);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 5.4, 529);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 4.6, 526);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 3.8, 523);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 3.0, 520);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 2.2, 517);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 1.4, 514);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, 0.6, 511);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, -0.2, 508);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-370, -1.0, 505);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 7.8, -538);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 7.0, -535);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 6.2, -532);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 5.4, -529);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 4.6, -526);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 3.8, -523);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 3.0, -520);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 2.2, -517);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 1.4, -514);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 0.6, -511);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, -0.2, -508);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, -1.0, -505);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
glPushMatrix();
glTranslated(370, 7.8, 538);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 7.0, 535);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 6.2, 532);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 5.4, 529);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 4.6, 526);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 3.8, 523);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 3.0, 520);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 2.2, 517);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 1.4, 514);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, 0.6, 511);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, -0.2, 508);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(370, -1.0, 505);
glScaled(218, 1.5, 7.9);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
// 1
glPushMatrix();
glTranslated(-474, 43, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(-471, 42.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(-468, 41.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(-465, 40.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(-462, 39.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(-459, 39, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(-456, 38.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(-453, 37.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(-450, 36.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(-447, 35.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(-444, 35, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(-441, 34.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(-438, 33.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 14
glPushMatrix();
glTranslated(-435, 32.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(-432, 31.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(-429, 31, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(-426, 30.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(-423, 29.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(-420, 28.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(-417, 27.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();



// 1
glPushMatrix();
glTranslated(-417, 27.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(-414, 27.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(-411, 26.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(-408, 25.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(-405, 24.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(-402, 23.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(-399, 23.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(-396, 22.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(-393, 21.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(-390, 20.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(-387, 19.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(-384, 19.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(-381, 18.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 14
glPushMatrix();
glTranslated(-378, 17.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(-375, 16.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(-372, 15.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(-369, 15.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(-366, 14.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(-363, 13.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(-360, 12.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-357, 12.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-354, 11.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-351, 11.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-348, 10.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-345, 9.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-342, 8.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-339, 7.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-336, 7.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-333, 6.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-330, 5.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-327, 4.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-324, 3.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-321, 3.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-318, 2.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-315, 1.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-312, 0.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-309, -0.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-306, -1.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(-357, 12.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-354, 11.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-351, 11.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-348, 10.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-345, 9.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-342, 8.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-339, 7.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-336, 7.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-333, 6.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-330, 5.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-327, 4.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-324, 3.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-321, 3.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-318, 2.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-315, 1.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-312, 0.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-309, -0.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(-399, 23.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(-396, 22.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(-393, 21.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(-390, 20.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(-387, 19.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(-384, 19.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(-381, 18.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 14
glPushMatrix();
glTranslated(-378, 17.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(-375, 16.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(-372, 15.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(-369, 15.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(-366, 14.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(-363, 13.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(-360, 12.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();





// 14
glPushMatrix();
glTranslated(-435, 32.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(-432, 31.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(-429, 31, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(-426, 30.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(-423, 29.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(-420, 28.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(-417, 27.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 1
glPushMatrix();
glTranslated(-417, 27.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(-414, 27.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(-411, 26.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(-408, 25.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(-405, 24.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(-402, 23.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 1
glPushMatrix();
glTranslated(-474, 43, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();



glNewList(3330, GL_COMPILE);
//ارض مدرج1112
glPushMatrix();


glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glEndList();



glPushMatrix();

glTranslated(-610, 45, 691);
glScaled(630, 1,7.9 );
for(int i=0;i<107;i++){

    glCallList(3330);
    glTranslated(0,0.9999,0.5);



}



glPopMatrix();

glPushMatrix();

glTranslated(610, 45, 691);
glScaled(630, 1,7.9 );
for(int i=0;i<107;i++){

    glCallList(3330);
    glTranslated(0,0.9999,0.5);



}



glPopMatrix();





glPushMatrix();

glTranslated(-610, 45, -691);
glScaled(630, 1,7.9 );
for(int i=0;i<107;i++){

    glCallList(3330);
    glTranslated(0,0.9999,-0.5);



}



glPopMatrix();


glPushMatrix();

glTranslated(610, 45, -691);
glScaled(630, 1,7.9 );
for(int i=0;i<107;i++){

    glCallList(3330);
    glTranslated(0,0.9999,-0.5);



}



glPopMatrix();





glPushMatrix();

glTranslated(0,151,1190);
glScaled(1900,15,170);
glColor3f(108/255.0,108/255.0,108/255.0);
glutSolidCube(1);






glPopMatrix();

glPushMatrix();

glTranslated(0,151,-1190);
glScaled(1900,15,170);
glColor3f(108/255.0,108/255.0,108/255.0);
glutSolidCube(1);




//حافة اخيرة

glPopMatrix();

glPushMatrix();

glTranslated(996,151,0);
glScaled(170,15,2550);
glColor3f(108/255.0,108/255.0,108/255.0);
glutSolidCube(1);






glPopMatrix();

glPushMatrix();

glTranslated(-996,151,0);
glScaled(170,15,2550);
glColor3f(108/255.0,108/255.0,108/255.0);
glutSolidCube(1);






glPopMatrix();


glPushMatrix();

glTranslated(1160,20,0);
glScaled(170,750,2750);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);


glPopMatrix();

//مهم
glPushMatrix();

glTranslated(-1160,-2,0);
glScaled(170,322,2750);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();




glPushMatrix();

glTranslated(-1160,237,600);
glScaled(170,322,1700);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();

glPushMatrix();

glTranslated(-1160,245,-1000);
glScaled(170,300,700);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();


glPopMatrix();

glPushMatrix();

glTranslated(-1160,319,-600);
glScaled(170,150,700);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();




glPushMatrix();

glTranslated(-1243,220,-600);
glScaled(1,150,700);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();




//window
glPushMatrix();
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glTranslated(-1080,220,-750);
glScaled(1,60,700);
glColor4f(0.02, 0.55, 0.66, 0.25f);
glutSolidCube(1);
glDisable(GL_BLEND);


glPopMatrix();


glPushMatrix();

glTranslated(-1080,170,-750);
glScaled(1,60,700);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();






glPushMatrix();

glTranslated(-1080,200,-350);
glScaled(1,140,100);
glColor3f(0.3,0.3,0.3);
glutSolidCube(1);



glPopMatrix();
 for (int i = 0; i < 1; i++) {
     glPushMatrix();
     //glTranslated(0, 0, 1);
     glTranslated(0, 0, position);
     glCallList(3);
     glPopMatrix();

 }

 for (int i = 0; i < 1; i++) {
     glPushMatrix();
     glRotated(90, 0, 1, 0);

     glTranslated(212.5, 0, 170);
     glTranslated(0, 0, position1);
     glCallList(3);
     glPopMatrix();
 }
 for (int i = 0; i < 1; i++) {
     glPushMatrix();
     glRotated(90, 0, 1, 0);

     glTranslated(-630, 0,200);
     glTranslated(0, 0, position1);
     glCallList(3);
     glPopMatrix();
 }

//door glass
glPushMatrix();
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
glTranslated(-1080,201,-276);
if(opensurf){
        glTranslated(0,0,30);
    glRotated(90,0,1,0);
}
glScaled(1,86,49);
glColor4f(0.02, 0.55, 0.66, 0.25f);

glutSolidCube(1);

glDisable(GL_BLEND);

glPopMatrix();















//flkewhofiuhe3r3ioufheroife3roiferoifneofinmewfimnefm newwwwww










glPopMatrix();


glPushMatrix();

glTranslated(0,20,1400);
glScaled(2490,750,170);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);


glPopMatrix();


glPushMatrix();

glTranslated(0,20,-1400);
glScaled(2490,750,170);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);


glPopMatrix();

















// 2
glPushMatrix();
glTranslated(-471, 42.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(-468, 41.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(-465, 40.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(-462, 39.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(-459, 39, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(-456, 38.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(-453, 37.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(-450, 36.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(-447, 35.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(-444, 35, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(-441, 34.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(-438, 33.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 1
glPushMatrix();
glTranslated(474, 43, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(471, 42.2, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(468, 41.4, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(465, 40.6, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(462, 39.8, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(459, 39, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(456, 38.2, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(453, 37.4, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(450, 36.6, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(447, 35.8, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(444, 35, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(441, 34.2, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(438, 33.4, 577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();
// 1
glPushMatrix();
glTranslated(474, 43, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();



glNewList(99, GL_COMPILE);

glPushMatrix();

glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

glEndList();

glPushMatrix();
glTranslated(488, 44.5, -777);
glScaled(-7.9, 1.5, 718);
for(int i =0;i<109;i++)
{
    glCallList(99);

    glTranslated(-0.5,0.64,0);


}




glPopMatrix();

glPushMatrix();
glTranslated(488, 44.5, 777);
glScaled(-7.9, 1.5, 718);
for(int i =0;i<109;i++)
{
    glCallList(99);

    glTranslated(-0.5,0.64,0);


}




glPopMatrix();


glPushMatrix();
glTranslated(-488, 44.5, -777);
glScaled(-7.9, 1.5, 718);
for(int i =0;i<109;i++)
{
    glCallList(99);

    glTranslated(0.5,0.64,0);


}




glPopMatrix();


glPushMatrix();
glTranslated(-488, 44.5, 777);
glScaled(-7.9, 1.5, 718);
for(int i =0;i<109;i++)
{
    glCallList(99);

    glTranslated(0.5,0.64,0);


}




glPopMatrix();


// 2
glPushMatrix();
glTranslated(471, 42.2, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(468, 41.4, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(465, 40.6, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(462, 39.8, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(459, 39, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(456, 38.2, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 8
glPushMatrix();
glTranslated(453, 37.4, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(450, 36.6, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(447, 35.8, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(444, 35, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(441, 34.2, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(438, 33.4, -577);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);glutSolidCube(1);
glPopMatrix();




// 14
glPushMatrix();
glTranslated(435, 32.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(432, 31.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(429, 31, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(426, 30.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(423, 29.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(420, 28.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(417, 27.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 1
glPushMatrix();
glTranslated(417, 27.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(414, 27.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(411, 26.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(408, 25.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(405, 24.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(402, 23.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(399, 23.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(0,96.4,899.8);
glScaled(1400,5.5,11.9);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
glPopMatrix();




// 14
glPushMatrix();
glTranslated(435, 32.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(432, 31.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(429, 31, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(426, 30.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(423, 29.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 19
glPushMatrix();
glTranslated(420, 28.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(417, 27.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();



// 1
glPushMatrix();
glTranslated(417, 27.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 2
glPushMatrix();
glTranslated(414, 27.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 3
glPushMatrix();
glTranslated(411, 26.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 4
glPushMatrix();
glTranslated(408, 25.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 5
glPushMatrix();
glTranslated(405, 24.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 6
glPushMatrix();
glTranslated(402, 23.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 7
glPushMatrix();
glTranslated(399, 23.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
// 8
glPushMatrix();
glTranslated(396, 22.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(393, 21.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(390, 20.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(387, 19.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(384, 19.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(381, 18.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 14
glPushMatrix();
glTranslated(378, 17.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(375, 16.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(372, 15.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(369, 15.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(366, 14.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
// 8
glPushMatrix();
glTranslated(396, 22.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 9
glPushMatrix();
glTranslated(393, 21.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 10
glPushMatrix();
glTranslated(390, 20.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 11
glPushMatrix();
glTranslated(387, 19.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 12
glPushMatrix();
glTranslated(384, 19.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 13
glPushMatrix();
glTranslated(381, 18.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 14
glPushMatrix();
glTranslated(378, 17.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 15
glPushMatrix();
glTranslated(375, 16.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 16
glPushMatrix();
glTranslated(372, 15.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 17
glPushMatrix();
glTranslated(369, 15.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 18
glPushMatrix();
glTranslated(366, 14.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(363, 13.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(360, 12.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(357, 12.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(354, 11.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(351, 11.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(348, 10.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(345, 9.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(342, 8.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(339, 7.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(336, 7.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
// 19
glPushMatrix();
glTranslated(363, 13.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

// 20
glPushMatrix();
glTranslated(360, 12.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(357, 12.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(354, 11.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(351, 11.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(348, 10.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(345, 9.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(342, 8.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(339, 7.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(336, 7.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(333, 6.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(330, 5.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(327, 4.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(324, 3.8, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(321, 3.0, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(318, 2.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(315, 1.4, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(312, 0.6, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(309, -0.2, -577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(333, 6.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(330, 5.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(327, 4.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(324, 3.8, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(321, 3.0, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(318, 2.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(315, 1.4, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(312, 0.6, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(309, -0.2, 577);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();






//حافة222
glPushMatrix();
    glTranslated(481,43,0);
glScaled(11.9, 5.5, 1371);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
    glPopMatrix();


    //حافة222
glPushMatrix();
    glTranslated(-481,43,0);
glScaled(11.9, 5.5, 1371);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
    glPopMatrix();

//حافة222
glPushMatrix();
    glTranslated(699,96.4,0);
glScaled(11.9, 5.5, 1871);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
    glPopMatrix();


    //حافة222
glPushMatrix();
    glTranslated(-699,96.4,0);
glScaled(11.9, 5.5, 1871);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
    glPopMatrix();




//stair mid


    glPushMatrix();
glTranslated(473, 43, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(470, 42.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(467, 41.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(464, 40.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(461, 39.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(458, 39, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(455, 38.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(452, 37.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(449, 36.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(446, 35.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(443, 35, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(440, 34.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(437, 33.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 1.7, 0.7);
glutSolidCube(1);
glPopMatrix();



glNewList(777,GL_COMPILE);
glPushMatrix();

glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();
glEndList();



glPushMatrix();
glTranslated(490, 44.6, 0);
glScaled(7.9, 1.5, 218);
for(int i=0;i<65;i++){


glCallList(777);
glTranslated(0.5,0.65,0);

}

glPopMatrix();


glPushMatrix();
glTranslated(-490, 44.6, 0);
glScaled(7.9, 1.5, 218);
for(int i=0;i<65;i++){


glCallList(777);
glTranslated(-0.5,0.65,0);

}

glPopMatrix();




glPushMatrix();
glTranslated(833, 128.3, 0);
glScaled(7.9, 1.5, 218);
for(int i=0;i<23;i++){


glCallList(777);
glTranslated(0.5,0.65,0);

}

glPopMatrix();



glPushMatrix();
glTranslated(-833, 128.3, 0);
glScaled(7.9, 1.5, 218);
for(int i=0;i<23;i++){


glCallList(777);
glTranslated(-0.5,0.65,0);

}

glPopMatrix();







//1

glPushMatrix();
glTranslated(840, 127.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(840, 107.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(840, 113.8, 17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(840, 113.8, -17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();


//1

glPushMatrix();
glTranslated(-840, 127.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(-840, 107.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(-840, 113.8, 17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(-840, 113.8, -17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(672.5,86.85 , 30);
glScaled(7.9, 1.5, 25);
for(int i=0;i<43;i++){


glCallList(777);
glTranslated(0.5,0.65,0);

}

glPopMatrix();


glPushMatrix();
glTranslated(672.5,86.85 , -30);
glScaled(7.9, 1.5, 25);
for(int i=0;i<43;i++){


glCallList(777);
glTranslated(0.5,0.65,0);

}

glPopMatrix();




glPushMatrix();
glTranslated(-672.5,86.85 , 30);
glScaled(7.9, 1.5, 25);
for(int i=0;i<43;i++){


glCallList(777);
glTranslated(-0.5,0.65,0);

}

glPopMatrix();


glPushMatrix();
glTranslated(-672.5,86.85 , -30);
glScaled(7.9, 1.5, 25);
for(int i=0;i<43;i++){


glCallList(777);
glTranslated(-0.5,0.65,0);

}

glPopMatrix();





//1

glPushMatrix();
glTranslated(447, 30.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(447, 10.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(447, 16.8, 17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(447, 16.8, -17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(434, 32.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(431, 31.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(428, 31, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();



//1

glPushMatrix();
glTranslated(447, 30.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(447, 10.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(447, 16.8, 17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(447, 16.8, -17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();



glPushMatrix();
glTranslated(425, 30.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(425, 30.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(422, 29.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(419, 28.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(416, 27.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(413, 27.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(410, 26.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(407, 25.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(404, 24.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(401, 23.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(398, 23.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(395, 22.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(392, 21.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(389, 20.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(386, 19.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(383, 19.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(380, 18.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(377, 17.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(374, 16.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(371, 15.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(368, 15.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(425, 30.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(422, 29.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(419, 28.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(416, 27.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(413, 27.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(410, 26.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(407, 25.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(404, 24.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(401, 23.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(398, 23.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(395, 22.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(392, 21.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(389, 20.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(386, 19.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(383, 19.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(380, 18.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(377, 17.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(374, 16.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(371, 15.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(368, 15.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(365, 14.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(362, 13.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(359, 12.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(356, 11.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(353, 11.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(392, 21.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(389, 20.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(386, 19.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(383, 19.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(380, 18.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(377, 17.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(374, 16.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(371, 15.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(368, 15.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(365, 14.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(362, 13.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(359, 12.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(356, 11.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(353, 11.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(347, 9.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(344, 8.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(341, 7.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(338, 7.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(335, 6.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(332, 5.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(329, 4.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(326, 3.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(323, 3.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(320, 2.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(317, 1.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(314, 0.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(311, -0.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(308, -1.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


//stair mid
glPushMatrix();
    glTranslated(-473,43,0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-473, 43, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-470, 42.2, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-467, 41.4, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-464, 40.6, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-461, 39.8, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-458, 39, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-455, 38.2, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-452, 37.4, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-449, 36.6, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-446, 35.8, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-443, 35, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-440, 34.2, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-437, 33.4, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-434, 32.6, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-431, 31.8, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

glPushMatrix();
    glTranslated(-428, 31, 0);
    glScaled(7.9, 1.5, 218);
    glColor3f(0.7, 0.7, 0.7);
    glutSolidCube(1);
glPopMatrix();

//1
glPushMatrix();
glTranslated(-447, 30.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(-447, 10.8, 0);
glScaled(200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(-447, 16.8, 17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(-447, 16.8, -17.2);
glRotated(90,1,0,0);
glScaled(200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-425, 30.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-425, 30.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-422, 29.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-419, 28.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-416, 27.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-413, 27.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-410, 26.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-407, 25.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-404, 24.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-401, 23.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-398, 23.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-395, 22.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-392, 21.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-389, 20.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-386, 19.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-383, 19.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-380, 18.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-377, 17.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-374, 16.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-371, 15.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-368, 15.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-365, 14.2, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-362, 13.4, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-359, 12.6, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-356, 11.8, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-353, 11.0, 30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-347, 9.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-344, 8.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-341, 7.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-338, 7.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-335, 6.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-332, 5.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-329, 4.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-326, 3.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-323, 3.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-320, 2.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-317, 1.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-314, 0.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-311, -0.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-308, -1.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

//stair mid
glPushMatrix();
glTranslated(473,43,0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(473, 43, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(470, 42.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(467, 41.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(464, 40.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(461, 39.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(458, 39, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(455, 38.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(452, 37.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(449, 36.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(446, 35.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(443, 35, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(440, 34.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(437, 33.4, 0);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(434, 32.6, 0);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(431, 31.8, 0);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(428, 31, 0);
glScaled(-7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

//1
glPushMatrix();
glTranslated(447, 30.8, 0);
glScaled(-200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//2
glPushMatrix();
glTranslated(447, 10.8, 0);
glScaled(-200.9, 1.5, 33);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//3
glPushMatrix();
glTranslated(447, 16.8, 17.2);
glRotated(90,1,0,0);
glScaled(-200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();
//4
glPushMatrix();
glTranslated(447, 16.8, -17.2);
glRotated(90,1,0,0);
glScaled(-200.9, 1.5, 29.5);
glColor3f(0,0,0);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(425, 30.2, 30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(425, 30.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(422, 29.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(419, 28.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(416, 27.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(413, 27.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(410, 26.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(407, 25.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(404, 24.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(401, 23.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(398, 23.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(395, 22.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(392, 21.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(389, 20.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(386, 19.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(383, 19.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(380, 18.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(377, 17.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(374, 16.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(371, 15.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(368, 15.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(365, 14.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(362, 13.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(359, 12.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(356, 11.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(353, 11.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(350, 10.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(347, 9.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(344, 8.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(341, 7.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(338, 7.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(335, 6.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(332, 5.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(329, 4.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(326, 3.8, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(323, 3.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(320, 2.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(317, 1.4, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(314, 0.6, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(311, -0.2, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(308, -1.0, 0);
glScaled(7.9, 1.5, 218);
glColor3f(0.7, 0.7, 0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(425, 30.2, 30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-425, 30.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-422, 29.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-419, 28.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-416, 27.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-413, 27.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-410, 26.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-407, 25.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-404, 24.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-401, 23.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-398, 23.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-395, 22.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-392, 21.4, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-389, 20.6, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-386, 19.8, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-383, 19.0, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-380, 18.2, -30);
glScaled(-7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(-377, 17.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-374, 16.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-371, 15.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-368, 15.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-365, 14.2, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-362, 13.4, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-359, 12.6, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-356, 11.8, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

glPushMatrix();
glTranslated(-353, 11.0, -30);
glScaled(7.9, 1.5, 25);
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();

//حافة222
glPushMatrix();
glTranslated(0,43,-681);
glRotated(90,0,1,0);
glScaled(11.9, 5.5, 990);

glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
glPopMatrix();

//حافة222
glPushMatrix();
glTranslated(0,43,681);
glRotated(90,0,1,0);
glScaled(11.9, 5.5, 990);

glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
glPopMatrix();

glNewList(300, GL_COMPILE);
//ارض مدرج1112
glPushMatrix();
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glEndList();

glPushMatrix();
glTranslated(0,45.3,-700);
for(int i=0;i<38;i++){

    glCallList(300);
    glTranslated(0,1.52,-6.3);



}
glPopMatrix();





glPushMatrix();
glTranslated(0,45.3,700);
for(int i=0;i<38;i++){

    glCallList(300);
    glTranslated(0,1.52,6.3);



}
glPopMatrix();

glPushMatrix();
glTranslated(0,95.12,-890.8);
for(int i=0;i<36;i++){

    glCallList(300);
    glTranslated(0,1.52,-6.3);



}
glPopMatrix();


glPopMatrix();

glPushMatrix();
glTranslated(0,95.12,890.8);
for(int i=0;i<36;i++){

    glCallList(300);
    glTranslated(0,1.52,6.3);



}
glPopMatrix();



glPushMatrix();
glTranslated(0,42.12,-679.8);
for(int i=26;i>0;i--){

    glCallList(300);
    glTranslated(0,-1.52,6.3);



}
glPopMatrix();



//حافة
glPushMatrix();
glTranslated(0,96.4,-899.8);
glScaled(1400,5.5,11.9);
glColor3f(108/255.0, 108/255.0, 108/255.0);
glutSolidCube(1);
glPopMatrix();








//ارض مدرج1112
glPushMatrix();
glTranslated(0,43,-673);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(0,42.2,-670);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();



glPushMatrix();
glTranslated(0,41.4,-667);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(0,40.6,-664);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(0,39.8,-661);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();


glPushMatrix();
glTranslated(0,39,-658);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();



glPushMatrix();
glTranslated(0,38.2,-655);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();





glPushMatrix();
glTranslated(0,37.4,-652);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();




glPushMatrix();
glTranslated(0,36.6,-649);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();






glPushMatrix();
glTranslated(0,35.8,-646);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();






glPushMatrix();
glTranslated(0,35,-643);
glScaled(218, 1.5,7.9 );
glColor3f(0.7,0.7,0.7);
glutSolidCube(1);
glPopMatrix();





glNewList(33,GL_COMPILE);
glPushMatrix();
glTranslated(0,34.2,-640);
glColor3f(0.7,0.7,0.7);
glScaled(218, 1.5,7.9 );
glutSolidCube(1);
glPopMatrix();
glEndList();

glPushMatrix();


for(int i=0;i<44;i++){
        glTranslated(0,-0.8,3);
glCallList(33);




}
glPopMatrix();


glNewList(34,GL_COMPILE);
glPushMatrix();
glTranslated(0,34.2,640);
glColor3f(0.7,0.7,0.7);
glScaled(218, 1.5,7.9 );
glutSolidCube(1);
glPopMatrix();
glEndList();

glPushMatrix();


for(int i=0;i<44;i++){
        glTranslated(0,-0.8,-3);
glCallList(34);




}
glPopMatrix();

glNewList(35,GL_COMPILE);
glPushMatrix();
glTranslated(0,34.2,640);
glColor3f(0.7,0.7,0.7);
glScaled(218, 1.5,7.9 );
glutSolidCube(1);
glPopMatrix();
glEndList();

glPushMatrix();


for(int i=0;i<11;i++){
        glTranslated(0,0.8,3);
glCallList(35);




}
glPopMatrix();




 //chair
  glNewList(6,GL_COMPILE);
    glPushMatrix();

    glScaled(1,4,5);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-2,-2.5,0);
    glRotated(90,0,0,1);
    glScaled(1,4,5);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
glEndList();





//chair
  glNewList(61,GL_COMPILE);
    glPushMatrix();

    glScaled(1,4,5);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2,-2.5,0);
    glRotated(90,0,0,1);
    glScaled(1,4,5);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
glEndList();

//chair
  glNewList(62,GL_COMPILE);
    glPushMatrix();

    glScaled(5,4,1);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-2.5,2);
    glRotated(90,1,0,0);
    glScaled(5,4,1);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
glEndList();

//chair
  glNewList(63,GL_COMPILE);
    glPushMatrix();

    glScaled(5,4,1);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0,-2.5,-2);
    glRotated(90,1,0,0);
    glScaled(5,4,1);
    glColor3f(0.8f, 0.7f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();
glEndList();




glPushMatrix();
glTranslated(314,8.5,38);
for(int j=0;j<82;j++){
    glPushMatrix();
for(int i=0;i<59;i++){

glCallList(6);


glTranslated(0,0,8);
}
glPopMatrix();
glTranslated(7,1.75,0);

}
glPopMatrix();



glPushMatrix();
glTranslated(314,8.5,-38);
for(int j=0;j<82;j++){
    glPushMatrix();
for(int i=0;i<59;i++){

glCallList(6);


glTranslated(0,0,-8);
}
glPopMatrix();
glTranslated(7,1.75,0);

}
glPopMatrix();




glPushMatrix();

glTranslated(-314,8.5,38);
for(int j=0;j<82;j++){
    glPushMatrix();
for(int i=0;i<59;i++){

glCallList(61);


glTranslated(0,0,8);
}
glPopMatrix();
glTranslated(-7,1.75,0);

}
glPopMatrix();


glPushMatrix();

glTranslated(-314,8.5,-38);
for(int j=0;j<82;j++){
    glPushMatrix();
for(int i=0;i<59;i++){

glCallList(61);


glTranslated(0,0,-8);
}
glPopMatrix();
glTranslated(-7,1.75,0);

}




glPopMatrix();
glPushMatrix();
glTranslated(38,8.5,-514);
for(int j=0;j<82;j++){
        glPushMatrix();
for(int i=0;i<33;i++){
glCallList(62);
glTranslated(8,0,0);
}
glPopMatrix();
glTranslated(0,1.75,-7);
}
glPopMatrix();





glPopMatrix();
glPushMatrix();
glTranslated(-38,8.5,-514);
for(int j=0;j<82;j++){
        glPushMatrix();
for(int i=0;i<33;i++){
glCallList(62);
glTranslated(-8,0,0);
}
glPopMatrix();
glTranslated(0,1.75,-7);
}
glPopMatrix();


glPopMatrix();
glPushMatrix();
glTranslated(-38,8.5,514);
for(int j=0;j<82;j++){
        glPushMatrix();
for(int i=0;i<33;i++){
glCallList(63);
glTranslated(-8,0,0);
}
glPopMatrix();
glTranslated(0,1.75,7);
}
glPopMatrix();

glPopMatrix();
glPushMatrix();
glTranslated(38,8.5,514);
for(int j=0;j<82;j++){
        glPushMatrix();
for(int i=0;i<33;i++){
glCallList(63);
glTranslated(8,0,0);
}
glPopMatrix();
glTranslated(0,1.75,7);
}
glPopMatrix();

glNewList(104,GL_COMPILE);
     //table
     //surf
     glPushMatrix();
    glTranslatef(2, -1, 1);
    glScalef(1.4, 0.17, 2.6);
    glColor3f(0.1,0.1,0.3);
    glutSolidCube(11);
    glPopMatrix();


    //leg1
     glPushMatrix();
     glTranslatef(1.8, -6, -12);
    glScalef(7.5, 5.1, 1);
     glColor3f(0.9f, 0.9f, 1.8f);
    glutSolidCube(1.9);
    glPopMatrix();


     //leg2
    glPushMatrix();
     glTranslatef(1.8, -6, 14);
    glScalef(7.5, 5.1, 1);
    glutSolidCube(1.9);
    glPopMatrix();

    //leg3
     glPushMatrix();
     glRotated(90,0,1,0);
     glTranslatef(-1, -6, 8);
     glScalef(13, 5.1, 1);
     glutSolidCube(1.9);
     glPopMatrix();

     //chair
     //column1
     glPushMatrix();
     glTranslatef(-9,-9.5,1);
     glRotated(90,0,1,0);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,8.7);
     glutSolidCube(0.7);
     glPopMatrix();

      //first_wheel
     glPushMatrix();
     glTranslatef(-6,-10.2,1);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,1);
     glutSolidCube(0.7);
     glPopMatrix();

      //second_wheel
     glPushMatrix();
     glTranslatef(-12,-10.2,1);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,1);
     glutSolidCube(0.7);
     glPopMatrix();

      //column2
     glPushMatrix();
     glTranslatef(-9,-9.5,1);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,8.7);
     glutSolidCube(0.7);
     glPopMatrix();

      //third_wheel
     glPushMatrix();
     glTranslatef(-9,-10.2,-2);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,1);
     glutSolidCube(0.7);
     glPopMatrix();

      //forth_wheel
     glPushMatrix();
     glTranslatef(-9,-10.2,4);
     glColor3f(0,0,0);
     glScalef(0.9,0.9,1);
     glutSolidCube(0.7);
     glPopMatrix();

      //column1
     glPushMatrix();
     glTranslatef(-9,-7.5,1);
     glRotated(90,0,1,0);
     glColor3f(0,0,0);
     glScalef(0.9,4.9,1);
     glutSolidCube(0.7);
     glPopMatrix();

      //column1
      glPushMatrix();
     glTranslatef(-9,-5.9,1);
     glRotated(90,0,1,0);
     glColor3f(0.1,0.1,0.3);
     glScalef(6.9,0.9,9);
     glutSolidCube(0.7);
     glPopMatrix();

      //column1
      glPushMatrix();
     glTranslatef(-13,-1.9,1);
     glRotated(105,0,0,1);
     glRotated(90,0,1,0);
     glColor3f(0.1,0.1,0.3);
     glScalef(6.9,0.9,11.3);
     glutSolidCube(0.7);
     glPopMatrix();

    glEndList();
glPushMatrix();
glTranslated(-1130,190,-490);
glScaled(2,3,2);
glCallList(104);
glPopMatrix();




glNewList(444, GL_COMPILE);
//مكريفون
glPushMatrix();
glRotated(10, 1, 0, 0);
glColor3f(0, 0, 0);
glutSolidCone(0.3, 3, 20, 20);
glPopMatrix();

glPushMatrix();
glColor3f(0.75, 0.75, 0.75);
glTranslated(0, 0, -0.3);
glutSolidSphere(0.5, 20, 20);
glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 0);
glTranslated(0, -2, 0.6);
glScaled(0.05, 1, 0.05);
glutSolidCube(4);
glPopMatrix();
glEndList();

glPushMatrix();
glTranslated(-1130,200,-490);
glRotated(90,0,1,0);
glScaled(3,3,3);
glCallList(444);
glPopMatrix();



glPushMatrix();
glTranslated(200,-11.1,0);
glScaled(2,1.5,5);
glCallList(2);
glPopMatrix();



glPushMatrix();
glTranslated(200,-11.1,75);
glScaled(2,1.5,2);
glCallList(2);
glPopMatrix();




glPushMatrix();
glTranslated(-200,-11.1,0);
glRotated(180,0,1,0);
glScaled(2,1.5,5);
glCallList(2);
glPopMatrix();



glPushMatrix();
glTranslated(-200,-11.1,75);
glRotated(180,0,1,0);
glScaled(2,1.5,2);
glCallList(2);
glPopMatrix();


glPushMatrix();
glTranslated(-200,-10.5,75.8);
glRotated(180,0,1,0);
glScaled(2,1.5,2);
for(int i=0;i<6;i++){


glCallList(1);
glTranslated(0,0,2);
}
glPopMatrix();


glPushMatrix();
glTranslated(-200,-10.5,0);
glRotated(180,0,1,0);
glScaled(2,1.5,2);
for(int i=0;i<15;i++){


glCallList(1);
glTranslated(0,0,2);
}
glPopMatrix();


glPushMatrix();
glTranslated(200,-10.5,75);
glScaled(2,1.5,2);
for(int i=0;i<6;i++){


glCallList(1);
glTranslated(0,0,2);
}
glPopMatrix();


glPushMatrix();
glTranslated(200,-10.5,0);
glScaled(2,1.5,2);
for(int i=0;i<15;i++){


glCallList(1);
glTranslated(0,0,2);
}
glPopMatrix();




/*
//cir
glPushMatrix();
glTranslated(0,390,0);
glScaled(1,119,1);
glRotated(90,1,0,0);
gluDisk(a,0, 400, 140, 135);
glPopMatrix();

*/


// سثق يمين
glPushMatrix();
glTranslated(0,395,940);
glScaled(2485,6,1090);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);
glPopMatrix();


//سثق يسار
glPushMatrix();
glTranslated(0,395,-940);
glScaled(2485,6,1090);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);
glPopMatrix();



//سثق امام
glPushMatrix();
glTranslated(812,395,0);
glScaled(840,6,1000);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);
glPopMatrix();



//سثق خلف
glPushMatrix();
glTranslated(-812,395,0);
glScaled(840,6,1000);
glColor3f(0.2,0.2,0.2);
glutSolidCube(1);
glPopMatrix();

glNewList(450,GL_COMPILE);
glPushMatrix();
//glTranslated(20,395,0);
glColor3f(0,0,1);
glScaled(15.28,4,2);

//glRotated(30,1,0,0);

gluCylinder(a,10,0,180,4,20);


glPopMatrix();


glPushMatrix();
//glTranslated(20,395,0);
glScaled(15.28,4,2);
glColor3f(1,0,0);
//glRotated(45,0,0,1);
glRotated(180,1,0,0);
//glRotated(30,1,0,0);

gluCylinder(a,10,0,40,4,20);


glPopMatrix();
glEndList();

//جبنة1
glPushMatrix();

glTranslated(-320,395,-140);
glRotated(67,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}


glCallList(450);



glPopMatrix();



//جبنة2
glPushMatrix();
glTranslated(320,395,-140);
glRotated(293,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}

glCallList(450);



glPopMatrix();




//جبنة3
glPushMatrix();
glTranslated(-320,395,140);
glRotated(113,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}

glCallList(450);



glPopMatrix();


//جبنة4
glPushMatrix();
glTranslated(320,395,140);
glRotated(247,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}

glCallList(450);



glPopMatrix();



//جبنة5
glPushMatrix();
glTranslated(140,395,320);
glRotated(202,0,1,0);


if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}
glCallList(450);



glPopMatrix();



//جبنة6
glPushMatrix();
glTranslated(-140,395,320);
glRotated(158,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}

glCallList(450);



glPopMatrix();


//جبنة7
glPushMatrix();
glTranslated(140,395,-320);
glRotated(-382,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}

glCallList(450);



glPopMatrix();





//جبنة8
glPushMatrix();
glTranslated(-140,395,-320);
glRotated(382,0,1,0);

if(opensurf){

    glTranslated(xx,0,0);




}
if(closesurf){

    glTranslated(xy,0,0);




}
glCallList(450);



glPopMatrix();


















/*

glPushMatrix();
glTranslated(-270,0,-240);
glRotated(45,0,1,0);
glCallList(450);


glPopMatrix();
*/






//تلفاز 1
glPushMatrix();
glColor3f(0, 0, 0);
glRotated(10, 0, 0, 1);
glScaled(0.3, 10, 15);
glTranslated(1500, 26, 0.7);
glutSolidCube(5);
glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 0);
//glRotated(-30, 1, 0, 1);
glScaled(0.5, 8, 0.5);
glTranslated(800, 46.5, 20);
glutSolidCube(5);
glPopMatrix();

//تلفاز 2
glPushMatrix();
glColor3f(0, 0, 0);
glRotated(-10, 0, 0, 1);
glScaled(0.3, 10, 15);
glTranslated(-1500, 26, 0.7);
glutSolidCube(5);
glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 0);
//glRotated(-30, 1, 0, 1);
glScaled(0.5, 8, 0.5);
glTranslated(-800, 46.5, 20);
glutSolidCube(5);
glPopMatrix();
//تلفاز 3
glPushMatrix();
glColor3f(0, 0, 0);
glRotated(-10, 1, 0, 0);
glScaled(15, 10, 0.3);
glTranslated(0, 27, 1510);
glutSolidCube(5);
glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 0);
//glRotated(-30, 1, 0, 1);
glScaled(0.5, 8, 0.5);
glTranslated(-3, 46.5, 800);
glutSolidCube(5);
glPopMatrix();
//تلفاز 4
glPushMatrix();
glColor3f(0, 0, 0);
glRotated(10, 1, 0, 0);
glScaled(15, 10, 0.3);
glTranslated(0, 27, -1510);
glutSolidCube(5);
glPopMatrix();

glPushMatrix();
glColor3f(0, 0, 0);
//glRotated(-30, 1, 0, 1);
glScaled(0.5, 8, 0.5);
glTranslated(-3, 46.5, -800);
glutSolidCube(5);
glPopMatrix();

 //كاميرا
 glPushMatrix();
 glColor3f(0.3, 0.3, 0.3);
 glScaled(4,4,6);
glutSolidCube(2);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0.7,  0.7, 0.7);
 glRotated(180, 1, 0, 0);
 glTranslated(0, 0,-13);
 glutSolidCone(3, 10, 20, 20);
 glPopMatrix();

 glPushMatrix();
 glColor3f(0, 0, 0);
 glTranslated(0, 0,13);
 glutSolidSphere(2, 20, 20);
 glPopMatrix();

 glPushMatrix();
 glColor3f(1, 1, 1);
 //glScaled(0.05, 5, 0.05);
 glTranslated(0, 0, -5);
 glutSolidCube(1);
 glPopMatrix();

//لوجه اعلانات
glPushMatrix();
glColor3f(1, 1, 1);
glTranslated(225, -9, -12.7);
glScaled(0.3, 2, 280);
glutSolidCube(3);
glPopMatrix();

glPushMatrix();
glColor3f(1, 1, 1);
glTranslated(-0.4, -9, 407);
glScaled(150, 2, 0.3);
glutSolidCube(3);
glPopMatrix();

glPushMatrix();
glColor3f(1, 1, 1);
glTranslated(-0.4, -9, -437.5);
glScaled(150, 2, 0.3);
glutSolidCube(3);
glPopMatrix();


glNewList(1007,GL_COMPILE);

        //1clock
     glPushMatrix();
     glTranslatef(1,0.2,-1);
     glColor3f(1,0,0);
     glScalef(1,82,1);
     glutSolidCube(0.005);
     glPopMatrix();



       //2clock
     glPushMatrix();
     glTranslatef(1,-0.001,-1);
     glRotated(xxx-=0.2,0,0,1);
     glTranslatef(0,0.2,0);
     glColor3f(1,0,0);
     glScalef(1,87,1);
     glutSolidCube(0.005);
     glPopMatrix();

      //circle
       glPushMatrix();
     glTranslatef(1,0,-1.0001);
     glColor3f(0,0,0);
     glScalef(1,1,0.0001);
     glutSolidSphere(0.6,10,10);
     glPopMatrix();

        //circle2
       glPushMatrix();
     glTranslatef(1,0,-1);
     glColor3f(1,1,1);
     glScalef(1,1,0.0001);
     glutSolidSphere(0.5,10,10);
     glPopMatrix();

     glEndList();

     glPushMatrix();
     glCallList(1007);
     glPopMatrix();



/*
glPushMatrix();
glTranslated(0,395,0);
glScaled(2490,6,2700);
glColor3f(0.2,1.2,0.2);
glutSolidCube(1);
glPopMatrix();
*/


glCallList(3);



	glutSwapBuffers();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE); // Use single display buffer.
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("MERCEDES");
    InitGL();
    glutReshapeFunc(ReSizeGLScene);
    glutDisplayFunc(DrawGLScene);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
Timer3(0);
    glutSpecialFunc(special);
    glutMainLoop();

    return 0;
}
