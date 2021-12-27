#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include "Node.h"
using namespace std;

class dijkstra{
public:
	void Initdijkstra(vector<vector<node*>> &_maze);
	std::list<node*> GetPath(node& startPoint, node& endPoint, bool isIgnoreCorner, Mat& background, int imgGridSize);
private:
	node *findPath(node &startPoint, node &endPoint, bool isIgnoreCorner, Mat& background, int imgGridSize);
	vector<node *> getSurroundPoints(node *point, bool isIgnoreCorner) const;
	bool isCanreach(node *point, node *target, bool isIgnoreCorner) const; //�ж�ĳ���Ƿ����������һ���ж�
	node *isInList(const std::list<node *> &list, node *point) const; //�жϿ���/�ر��б����Ƿ����ĳ��
	node *getLeastGpoint();
private:
	vector<vector<node*>> maze;
	std::list<node *> openList;  //�����б�
	std::list<node *> closeList; //�ر��б�
};

#endif