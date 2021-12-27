#include "dijkstra.h"

void dijkstra::Initdijkstra(vector<vector<node*>> &_maze){
	maze = _maze;
}
node* dijkstra::getLeastGpoint(){                                                            
    if (!openList.empty()){
        auto resPoint = openList.front();
        for (auto point : openList){
            if (point->getG() < resPoint->getG()) {
                resPoint = point;
            }
        }
        return resPoint;
    }
    return NULL;
}


node* dijkstra::isInList(const std::list<node *> &list, node* point) const
{
	//�ж�ĳ���ڵ��Ƿ����б��У����ﲻ�ܱȽ�ָ�룬��Ϊÿ�μ����б����¿��ٵĽڵ㣬ֻ�ܱȽ�����
	for (auto p : list){
		if (p->getx() == point->getx()  &&  p->gety() == point->gety())
			return p;
	}
	return NULL;
}


bool dijkstra::isCanreach(node *point, node *target, bool isIgnoreCorner) const //�ж�ĳ���Ƿ����������һ���ж�
{
	if (target->getx() < 0 || target->getx() > maze.size() - 1
		|| target->gety() < 0 || target->gety() > maze[0].size() - 1
		|| maze[target->getx()][target->gety()]->isObstacle()
		|| (target->getx() == point->getx() && target->gety() == point->gety())
		|| isInList(closeList, target)) {//����㳬����ͼ�����ϰ���뵱ǰ�ڵ��غϡ������ڹر��б��У�����false
		return false;
	}
	else{
		if (abs(point->getx() - target->getx()) + abs(point->gety() - target->gety()) == 1) {//��б�ǿ���
			return true;
		}
		else{
			//б�Խ�Ҫ�ж��Ƿ��ס
			if (!maze[point->getx()][target->gety()]->isObstacle() && !maze[target->getx()][point->gety()]->isObstacle()) {
				return true;
			}
			else {
				return isIgnoreCorner;
			}
				
		}
	}
}


vector<node *> dijkstra::getSurroundPoints(node *point, bool isIgnoreCorner) const{
	std::vector<node *> surroundPoints;
	for (int x = point->getx() - 1; x <= point->getx() + 1; x++) {
		for (int y = point->gety() - 1; y <= point->gety() + 1; y++) {
			if (isCanreach(point, new node(x, y), isIgnoreCorner)) {
				surroundPoints.push_back(new node(x, y));
			}
		}
	}
	return surroundPoints;
}


node* dijkstra::findPath(node &startPoint, node &endPoint, bool isIgnoreCorner, Mat& background, int imgGridSize)
{
	openList.push_back(new node(startPoint.getx(), startPoint.gety())); //�������,��������һ���ڵ㣬�������
	while (!openList.empty()){
		auto curPoint = getLeastGpoint(); //�ҵ�Fֵ��С�ĵ�
		curPoint->drawNode(background, imgGridSize, Scalar(84, 46, 84),2);
		imshow("dijkstra", background);
		waitKey(5);
		openList.remove(curPoint); //�ӿ����б���ɾ��
		closeList.push_back(curPoint); //�ŵ��ر��б�
		//1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���
		auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto &target : surroundPoints){
			//2,��ĳһ�����ӣ���������ڿ����б��У����뵽�����б����õ�ǰ��Ϊ�丸�ڵ㣬����F G H
			if (!isInList(openList, target)){
				target->setParent(curPoint);
				target->setG(target->calG(curPoint));
				openList.push_back(target);
				/*target->drawNode(background, imgGridSize, Scalar(0, 255, 0), 0);
				imshow("aStar", background);
				waitKey(5);*/
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F
			else{
				int tempG = target->calG(curPoint);
				if (tempG < target->getG()){
					target->setParent(curPoint);
					target->setG(tempG);
				}
			}
			node *resPoint = isInList(openList, &endPoint);
			if (resPoint)
				return resPoint; //�����б���Ľڵ�ָ�룬��Ҫ��ԭ�������endpointָ�룬��Ϊ���������
		}
	}
	return NULL;
}



std::list<node*> dijkstra::GetPath(node& startPoint, node& endPoint, bool isIgnoreCorner, Mat& background, int imgGridSize)
{
	node *result = findPath(startPoint, endPoint, isIgnoreCorner, background, imgGridSize);
	std::list<node *> path;
	//����·�������û�ҵ�·�������ؿ�����
	while (result){
		result->drawNode(background, imgGridSize, Scalar(0, 255, 255),1);
		imshow("dijkstra", background);
		waitKey(5);
		path.push_front(result);
		result = result->getParent();
	}
	return path;
}
