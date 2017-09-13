#pragma once

#include <string>

struct Entry
{
    int no;
    int sec;
    char type;
    int mans;
    int check;
};

// �㣬������Ĭ�ϡ����ƹ��죬norm���������ŷ�Ͼ���
struct Point {
    float x, y;
    Point();
    Point(float a, float b);
    Point(const Point& p);
    Point& operator = (const Point& p);
    Point operator + (const Point& p);
    Point operator * (const float m);
    inline static float Point::norm(const Point& a, const Point& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }
};

struct Passenger {
    int id;
    int arriveTime, checkTime;
    std::string name;
    Point pos;
    Point endPoint;
    bool needMove;
    int texId;
    Passenger();
    Passenger(float x, float y);
    Passenger(int id, int arriveTime, int checkTime, std::string name);
};

