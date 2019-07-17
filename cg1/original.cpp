//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdlib.h>
//#include <stdio.h>
//#include <math.h>
//#include <assert.h>
//#include <float.h>
//
//#include "glut.h"
//
//// dimensiunea ferestrei in pixeli
//#define dim 300
//#define RX_JF 0.01
//#define RY_JF 0.01
//#define MODMAX_M 4.0
//#define NRITER_M 5000
//
//unsigned char prevKey;
//
//class CComplex {
//public:
//	CComplex() : re(0.0), im(0.0) {}
//	CComplex(double re1, double im1) : re(re1 * 1.0), im(im1 * 1.0) {}
//	CComplex(const CComplex &c) : re(c.re), im(c.im) {}
//	~CComplex() {}
//
//	CComplex &operator=(const CComplex &c)
//	{
//		re = c.re;
//		im = c.im;
//		return *this;
//	}
//
//	double getRe() { return re; }
//	void setRe(double re1) { re = re1; }
//
//	double getIm() { return im; }
//	void setIm(double im1) { im = im1; }
//
//	double getModul() { return sqrt(re * re + im * im); }
//
//	int operator==(CComplex &c1)
//	{
//		return ((re == c1.re) && (im == c1.im));
//	}
//
//	CComplex pow2()
//	{
//		CComplex rez;
//		rez.re = powl(re * 1.0, 2) - powl(im * 1.0, 2);
//		rez.im = 2.0 * re * im;
//		return rez;
//	}
//
//	friend CComplex operator+(const CComplex &c1, const CComplex &c2);
//	friend CComplex operator*(CComplex &c1, CComplex &c2);
//
//	void print(FILE *f)
//	{
//		fprintf(f, "%.20f%+.20f i", re, im);
//	}
//
//private:
//	double re, im;
//};
//
//CComplex operator+(const CComplex &c1, const CComplex &c2)
//{
//	CComplex rez(c1.re + c2.re, c1.im + c2.im);
//	return rez;
//}
//
//CComplex operator*(CComplex &c1, CComplex &c2)
//{
//	CComplex rez(c1.re * c2.re - c1.im * c2.im,
//		c1.re * c2.im + c1.im * c2.re);
//	return rez;
//}
//
//int nivel = 0;
//
//class C2coord
//{
//public:
//	C2coord()
//	{
//		m.x = m.y = 0;
//	}
//
//	C2coord(double x, double y)
//	{
//		m.x = x;
//		m.y = y;
//	}
//
//	C2coord(const C2coord &p)
//	{
//		m.x = p.m.x;
//		m.y = p.m.y;
//	}
//
//	C2coord &operator=(C2coord &p)
//	{
//		m.x = p.m.x;
//		m.y = p.m.y;
//		return *this;
//	}
//
//	int operator==(C2coord &p)
//	{
//		return ((m.x == p.m.x) && (m.y == p.m.y));
//	}
//
//protected:
//	struct SDate
//	{
//		double x, y;
//	} m;
//};
//
//class CPunct : public C2coord
//{
//public:
//	CPunct() : C2coord(0.0, 0.0)
//	{}
//
//	CPunct(double x, double y) : C2coord(x, y)
//	{}
//
//	CPunct &operator=(const CPunct &p)
//	{
//		m.x = p.m.x;
//		m.y = p.m.y;
//		return *this;
//	}
//
//	void getxy(double &x, double &y)
//	{
//		x = m.x;
//		y = m.y;
//	}
//
//	int operator==(CPunct &p)
//	{
//		return ((m.x == p.m.x) && (m.y == p.m.y));
//	}
//
//	void marcheaza()
//	{
//		glBegin(GL_POINTS);
//		glVertex2d(m.x, m.y);
//		glEnd();
//	}
//
//	void print(FILE *fis)
//	{
//		fprintf(fis, "(%+f,%+f)", m.x, m.y);
//	}
//
//};
//
//class CVector : public C2coord
//{
//public:
//	CVector() : C2coord(0.0, 0.0)
//	{
//		normalizare();
//	}
//
//	CVector(double x, double y) : C2coord(x, y)
//	{
//		normalizare();
//	}
//
//	CVector &operator=(CVector &p)
//	{
//		m.x = p.m.x;
//		m.y = p.m.y;
//		return *this;
//	}
//
//	int operator==(CVector &p)
//	{
//		return ((m.x == p.m.x) && (m.y == p.m.y));
//	}
//
//	CPunct getDest(CPunct &orig, double lungime)
//	{
//		double x, y;
//		orig.getxy(x, y);
//		CPunct p(x + m.x * lungime, y + m.y * lungime);
//		return p;
//	}
//
//	void rotatie(double grade)
//	{
//		double x = m.x;
//		double y = m.y;
//		double t = 2 * (4.0 * atan(1.0)) * grade / 360.0;
//		m.x = x * cos(t) - y * sin(t);
//		m.y = x * sin(t) + y * cos(t);
//		normalizare();
//	}
//
//	void deseneaza(CPunct p, double lungime)
//	{
//		double x, y;
//		p.getxy(x, y);
//		glColor3f(1.0, 0.1, 0.1);
//		glBegin(GL_LINE_STRIP);
//		glVertex2d(x, y);
//		glVertex2d(x + m.x * lungime, y + m.y * lungime);
//		glEnd();
//	}
//
//	void print(FILE *fis)
//	{
//		fprintf(fis, "%+fi %+fj", C2coord::m.x, C2coord::m.y);
//	}
//
//private:
//	void normalizare()
//	{
//		double d = sqrt(C2coord::m.x * C2coord::m.x + C2coord::m.y * C2coord::m.y);
//		if (d != 0.0)
//		{
//			C2coord::m.x = C2coord::m.x * 1.0 / d;
//			C2coord::m.y = C2coord::m.y * 1.0 / d;
//		}
//	}
//};
//
//class Mandelbrot {
//public:
//	Mandelbrot() {
//		m.nriter = NRITER_M;
//		m.modmax = MODMAX_M;
//	};
//
//	~Mandelbrot() {}
//
//	void setmodmax(double v) { m.modmax = v; }
//	double getmodmax() { return m.modmax; }
//	void setnriter(int v) { m.nriter = v; }
//	int getnriter() { return m.nriter; }
//
//	int isIn(CComplex &x)
//	{
//		int in = 0;
//		CComplex z0, z1;
//
//		z0 = CComplex(0, 0);
//		for (int i = 0; i < m.nriter; i++)
//		{
//			z1 = z0 * z0 + x;
//			if (z1.getModul() > m.modmax)
//			{
//				in = 1;
//				return in;
//			}
//			z0 = z1;
//		}
//
//		return in;
//	}
//	void display(double xmin, double ymin, double xmax, double ymax)
//	{
//		glPushMatrix();
//		glLoadIdentity();
//		// afisarea propriu-zisa
//		glBegin(GL_POINTS);
//		for (double x = xmin; x <= xmax; x += RX_JF)
//			for (double y = ymin; y <= ymax; y += RY_JF)
//			{
//				CComplex z(x, y);
//				int r = isIn(z);
//				if (r == 0)
//					glColor3f(1, 0, 0);
//				else
//					glColor3f(1, 1, 1);
//				glVertex3d(1.75 * x / 2 + 0.5, 1.75 * y / 2, 0);
//			}
//		glEnd();
//		glPopMatrix();
//	}
//
//private:
//	struct SDate {
//		CComplex c;
//		// nr. de iteratii
//		int nriter;
//		// modulul maxim
//		double modmax;
//	} m;
//
//};
//
//class Imaginea1
//{
//public:
//	int ratie = 3;
//
//	void build_image1(double lungime, int nivel, CPunct p, CVector v)
//	{
//		CPunct p1;
//
//		if (nivel == 0)
//		{
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//		}
//		else
//		{
//			nivel -= 1;
//
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//			v.rotatie(-90);
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//
//			lungime = double(lungime / ratie);
//
//			p1 = v.getDest(p, 2 * lungime);
//			v.rotatie(-90);
//			p1 = v.getDest(p1, lungime);
//			build_image1(lungime, nivel, p1, v);
//
//			p1 = v.getDest(p1, 3 * lungime);
//			build_image1(lungime, nivel, p1, v);
//
//			p1 = v.getDest(p1, -6 * lungime);
//			build_image1(lungime, nivel, p1, v);
//
//			v.rotatie(-90);
//			p1 = v.getDest(p1, 3 * lungime);
//			v.rotatie(90);
//			build_image1(lungime, nivel, p1, v);
//
//			v.rotatie(-90);
//			p1 = v.getDest(p1, 3 * lungime);
//			v.rotatie(90);
//			build_image1(lungime, nivel, p1, v);
//
//			p1 = v.getDest(p1, 3 * lungime);
//			build_image1(lungime, nivel, p1, v);
//
//			p1 = v.getDest(p1, 3 * lungime);
//			build_image1(lungime, nivel, p1, v);
//
//			v.rotatie(90);
//			p1 = v.getDest(p1, 3 * lungime);
//			v.rotatie(-90);
//			build_image1(lungime, nivel, p1, v);
//		}
//	}
//
//	void afisare(double lungime, int nivel)
//	{
//		CVector v(0.0, 1.0);
//		CPunct p(-lungime / 6, -lungime / 6);
//
//		build_image1(lungime / ratie, nivel, p, v);
//	}
//};
//
//class Imaginea2
//{
//public:
//	void construct_figura2(double lungime, int nivel, double factordiviziune, CPunct p, CVector v)
//	{
//		assert(factordiviziune != 0);
//		CPunct p1, p2;
//		if (nivel == 0) {}
//		else
//		{
//			nivel -= 1;
//
//			v.rotatie(-45);
//			v.deseneaza(p, lungime);
//			p1 = v.getDest(p, lungime);
//			construct_figura2(lungime * factordiviziune, nivel, factordiviziune, p1, v);
//
//			v.rotatie(90);
//			v.deseneaza(p, lungime);
//			p1 = v.getDest(p, lungime);
//			p2 = p1;
//
//			v.rotatie(15);
//			v.deseneaza(p1, lungime);
//			p1 = v.getDest(p1, lungime);
//			construct_figura2(lungime * factordiviziune, nivel, factordiviziune, p1, v);
//
//			p1 = p2;
//			v.rotatie(-60);
//			v.deseneaza(p1, lungime);
//			p1 = v.getDest(p1, lungime);
//			p2 = p1;
//
//			lungime = lungime * factordiviziune;
//			v.rotatie(30);
//			v.deseneaza(p1, lungime);
//			p1 = v.getDest(p1, lungime);
//			construct_figura2(lungime, nivel, factordiviziune, p1, v);
//
//			p1 = p2;
//			v.rotatie(-120);
//			v.deseneaza(p1, lungime);
//			p1 = v.getDest(p1, lungime);
//			construct_figura2(lungime, nivel, factordiviziune, p1, v);
//		}
//	}
//
//	void afisare(double lungime, int nivel)
//	{
//		CVector v(0.0, -1.0);
//		CPunct p(0.0, 2.0);
//
//		v.deseneaza(p, 0.25);
//		p = v.getDest(p, 0.25);
//		construct_figura2(lungime, nivel, 0.4, p, v);
//	}
//};
//
//class Imaginea3
//{
//public:
//	void build_Image3(double lungime, int nivel, CPunct &p, CVector &v, int angle)
//	{
//		CPunct p1;
//		if (nivel == 0)
//		{
//			v.deseneaza(p, lungime);
//			p = v.getDest(p, lungime);
//		}
//		else
//		{
//			nivel -= 1;
//
//			build_Image3(lungime / 2, nivel, p, v, -angle);
//			v.rotatie(angle);
//			build_Image3(lungime / 2, nivel, p, v, angle);
//			v.rotatie(angle);
//			build_Image3(lungime / 2, nivel, p, v, -angle);
//		}
//	}
//
//	void afisare(double lungime, int nivel)
//	{
//		CVector v(0.0, 1.0);
//		CPunct p(-lungime / 2, -lungime / 2);
//
//		if (nivel % 2 != 0)
//		{
//			v.rotatie(-60);
//			build_Image3(lungime, nivel, p, v, 60);
//		}
//		else
//		{
//			build_Image3(lungime, nivel, p, v, 60);
//		}
//	}
//};
//
//// Mandelbrot
//void Display1() {
//	Mandelbrot cm;
//
//	glColor3f(1.0, 0.1, 0.1);
//	cm.setmodmax(4.0);
//	cm.setnriter(127);
//	cm.display(-2, -2, 2, 2);
//}
//
//void DisplayImagine1()
//{
//	Imaginea1 Imaginea1;
//
//	char c[3];
//	sprintf(c, "%2d", nivel);
//	glRasterPos2d(-0.98, -0.98);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'v');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'l');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '=');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[0]);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[1]);
//
//	glRasterPos2d(-1.0, 0.93);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'm');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'g');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'n');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '1');
//
//	glPushMatrix();
//	glLoadIdentity();
//	Imaginea1.afisare(1.8, nivel);
//	glPopMatrix();
//	nivel++;
//}
//
//void DisplayImagine2()
//{
//	Imaginea2 Imaginea2;
//
//	char c[3];
//	sprintf(c, "%2d", nivel);
//	glRasterPos2d(-0.98, -0.98);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'v');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'l');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '=');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[0]);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[1]);
//
//	glRasterPos2d(-1.0, 0.9);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'm');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'g');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'n');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '2');
//
//	glPushMatrix();
//	glLoadIdentity();
//	glScaled(0.4, 0.4, 1);
//	glTranslated(-0.5, 0.0, 0.0);
//	Imaginea2.afisare(1, nivel);
//	glPopMatrix();
//	nivel++;
//}
//
//void DisplayImagine3()
//{
//	Imaginea3 Imaginea3;
//	Imaginea3.afisare(1.5, nivel);
//
//	char c[3];
//	sprintf(c, "%2d", nivel);
//	glRasterPos2d(-0.98, -0.98);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'N');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'v');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'l');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '=');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[0]);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[1]);
//
//	glRasterPos2d(-1.0, 0.9);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'I');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'm');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'g');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'i');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'n');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'e');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'a');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ' ');
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '3');
//
//	nivel++;
//}
//
//void Init(void) {
//
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//
//	glLineWidth(1);
//
//	glPointSize(3);
//
//	glPolygonMode(GL_FRONT, GL_LINE);
//}
//
//void Display(void) {
//	switch (prevKey) {
//	case '-':
//		glClear(GL_COLOR_BUFFER_BIT);
//		nivel = 0;
//		fprintf(stderr, "nivel = %d\n", nivel);
//		break;
//	case '1':
//		glClear(GL_COLOR_BUFFER_BIT);
//		Display1();
//		break;
//	case '2':
//		glClear(GL_COLOR_BUFFER_BIT);
//		DisplayImagine1();
//		break;
//	case '3':
//		glClear(GL_COLOR_BUFFER_BIT);
//		DisplayImagine2();
//		break;
//	case '4':
//		glClear(GL_COLOR_BUFFER_BIT);
//		DisplayImagine3();
//		break;
//	default:
//		break;
//	}
//
//	glFlush();
//}
//
//void Reshape(int w, int h) {
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//}
//
//void KeyboardFunc(unsigned char key, int x, int y) {
//	prevKey = key;
//	if (key == 27) // escape
//		exit(0);
//	glutPostRedisplay();
//}
//
//void MouseFunc(int button, int state, int x, int y) {
//}
//
//int main(int argc, char** argv) {
//
//	glutInit(&argc, argv);
//
//	glutInitWindowSize(dim, dim);
//
//	glutInitWindowPosition(100, 100);
//
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	glutCreateWindow(argv[0]);
//
//	Init();
//
//	glutReshapeFunc(Reshape);
//
//	glutKeyboardFunc(KeyboardFunc);
//
//	glutMouseFunc(MouseFunc);
//
//	glutDisplayFunc(Display);
//
//	glutMainLoop();
//
//	return 0;
//}
