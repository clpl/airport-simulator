#ifndef VIEW_H
#define VIEW_H

#include <SOIL.h>
#include <GL/glut.h>
#include <cmath>

// ���ڿ��
const int windowWidth = 720;
const int windowHeight = 480;

// �������ֵ�ö�ٱ�����ʵ�ֶ�ͼ��ʱ����Ҫ��
enum texName;

// �㣬������Ĭ�ϡ����ƹ��죬norm���������ŷ�Ͼ���
struct Point {
    float x, y;
    Point();
    Point(float a, float b);
    Point(const Point& p);
    Point& operator = (const Point& p);
    inline static float Point::norm(const Point& a, const Point& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }
};

// ��������
class Passenger {
public:
    Point pos;
    Point endPoint;
    bool needMove;
    Passenger(float x=0, float y=0) {pos.x = x; pos.y = y; needMove = true;}
};

// ��������
void show(int argc, char *argv[]);

void drawInit();
/* ��ͼǰ��ʼ��������
    ���ñ���
    �������
*/
// ���ļ���ȡ����
void loadTexture();

// ʲôҲ���������㺯��
void display();

// ���󽻻��ص�����
void onEscPressed(unsigned char key, int x, int y);


// ���ߺ�����
void drawObject(texName, Point&, float, float);
void flush(int value);


#endif