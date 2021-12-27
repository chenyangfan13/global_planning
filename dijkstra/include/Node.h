#ifndef _NODE_H
#define _NODE_H

#include <vector>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;

const int kCost1 = 10; //ֱ��һ������
const int kCost2 = 14; //б��һ������

// �����洢�ڵ�
class node {
public:
	node(int _x = 0, int _y = 0, int _G = 0);
    ~node();
	int getx();
	int gety();

	int calG(node *temp_start);
	void setG(int g);
	int getG();

	void setObstacle();
	bool isObstacle();
	void setParent(node* backNode);
	node* getParent();
	void drawNode(Mat& background, int imgGridSize, const Scalar& color, int shift = -1);
private:
    int x, y;       // ����
    int  G;	
    bool obstacle;   // �Ƿ����ϰ���
    node* parent; // ǰ���ڵ�
};

#endif
