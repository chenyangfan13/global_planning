#include <iostream> //"#"代表预处理命令
#include<cstring>
#include<fstream>//读写头文件
#include<time.h>
#include"jps.h"

#include "Node.h"
#include <vector>
#include <algorithm>
#include <cmath>
#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;    //使用standard命名空间

const int mapSize = 50;   // 地图大小
const int imgGridSize = 5;// 显示的图像栅格大小


// 设置障碍物
void defineObstacle(vector<vector<node*>>& roadmap) {
    // 先框住四周
    for (int i = 0; i < mapSize; ++i) {
        roadmap[0][i]->setObstacle();
        roadmap[i][0]->setObstacle();
        roadmap[i][mapSize - 1]->setObstacle();
        roadmap[mapSize - 1][i]->setObstacle();
    }

    // 再定义一个条形快
    for (int i = 1; i < mapSize / 2; ++i) {
        roadmap[mapSize * 2 / 3][i]->setObstacle();
        roadmap[mapSize * 2 / 3 - 1][i]->setObstacle();
        roadmap[mapSize * 1 / 3][mapSize - i]->setObstacle();
        roadmap[mapSize * 1 / 3 - 1][mapSize - i]->setObstacle();
    }
}

// 画出地图
void drawMap(Mat& background, node startNode, node goalNode, vector<vector<node*>> roadmap) {
    // 画出障碍物
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            if (roadmap[i][j]->isObstacle())
                roadmap[i][j]->drawNode(background, imgGridSize, Scalar(128, 138, 135));
        }
    }

    // 画出起始点和终点
    startNode.drawNode(background, imgGridSize, Scalar(255, 0, 0));//起点为蓝色
    goalNode.drawNode(background, imgGridSize, Scalar(0, 0, 255)); //目标位置为红色
}

int main(int argc, char* argv[]) {
    node startNode(40, 10);// 起始点
    node goalNode(10, 40); // 目标点

    vector<vector<node*>> roadmap;// 地图

    // 初始化roadmap
    for (int i = 0; i < mapSize; ++i) {
        vector<node*> tmp;
        for (int j = 0; j < mapSize; ++j) {
            node* tmpNode = new node(i, j);
            tmp.push_back(tmpNode);
        }
        roadmap.push_back(tmp);
    }

    // 添加障碍物
    defineObstacle(roadmap);

    // 打开一个窗口
    namedWindow("jps", WINDOW_NORMAL);
    
    Mat background(mapSize * imgGridSize,
               mapSize * imgGridSize,
               CV_8UC3,//8位无符号char型,3通道
               cv::Scalar(0, 0, 0));

    // 画出地图
    drawMap(background, startNode, goalNode, roadmap);
    imshow("jps", background);
    waitKey(500);

    int **pMap;//地图二维指针数组
    pMap = new int* [mapSize];
    for(int i=0;i < mapSize;i++){
        pMap[i] = new int[mapSize];
        for(int j=0;j < mapSize;j++){
            if(roadmap[i][j]->isObstacle()) pMap[i][j] = 1;
            else pMap[i][j] = 0;
        }
    }

    //JPS
    cout<<"------------JPS---------------"<<"\n";
    Jps jps;
    Jps::PathNode jStart = {startNode.gety(),startNode.getx()};
    Jps::PathNode jEnd = {goalNode.gety(), goalNode.getx()};

    time_t time_start_ms,time_end_ms;//时间记录ms
    time_start_ms = clock();//JpsPrune寻路开始时间

    jps.Init(pMap, mapSize, mapSize);
    cout<<"--------FindPathPrune---------"<<"\n";
    jps.FindPathPrune(jStart, jEnd);

    time_end_ms = clock();//JpsPrune寻路结束时间
    cout<<"JpsPrune run time："<<difftime(time_end_ms, time_start_ms)<<"ms"<<endl;
    //测试
    //cout<<retPath[1].row<<"  "<<retPath[1].col<<endl;
    jps.PrintRoute();
    vector<Jps::PathNode> vecpnode =jps.translatenode();
    int temp_num= vecpnode.size();
    //vector<node> vecdrawnode;
    node drawnode;
    for(int i=0;i<temp_num;i++)
    {
        drawnode.x=vecpnode[i].row;
        drawnode.y = vecpnode[i].col;
        //cout<<"test"<<endl;
        //vecdrawnode.push_back(drawnode);
        drawnode.drawNode(background, imgGridSize , Scalar(0,255,255),1);
        imshow("jps",background);
        waitKey(5000);

     
    }

    //imshow("jps", background);
    //waitKey(5);
    return 0;
}
