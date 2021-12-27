#include <iostream> //"#"����Ԥ��������
#include<cstring>
#include<fstream>//��дͷ�ļ�
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
using namespace std;    //ʹ��standard�����ռ�

const int mapSize = 50;   // ��ͼ��С
const int imgGridSize = 5;// ��ʾ��ͼ��դ���С


// �����ϰ���
void defineObstacle(vector<vector<node*>>& roadmap) {
    // �ȿ�ס����
    for (int i = 0; i < mapSize; ++i) {
        roadmap[0][i]->setObstacle();
        roadmap[i][0]->setObstacle();
        roadmap[i][mapSize - 1]->setObstacle();
        roadmap[mapSize - 1][i]->setObstacle();
    }

    // �ٶ���һ�����ο�
    for (int i = 1; i < mapSize / 2; ++i) {
        roadmap[mapSize * 2 / 3][i]->setObstacle();
        roadmap[mapSize * 2 / 3 - 1][i]->setObstacle();
        roadmap[mapSize * 1 / 3][mapSize - i]->setObstacle();
        roadmap[mapSize * 1 / 3 - 1][mapSize - i]->setObstacle();
    }
}

// ������ͼ
void drawMap(Mat& background, node startNode, node goalNode, vector<vector<node*>> roadmap) {
    // �����ϰ���
    for (int i = 0; i < mapSize; ++i) {
        for (int j = 0; j < mapSize; ++j) {
            if (roadmap[i][j]->isObstacle())
                roadmap[i][j]->drawNode(background, imgGridSize, Scalar(128, 138, 135));
        }
    }

    // ������ʼ����յ�
    startNode.drawNode(background, imgGridSize, Scalar(255, 0, 0));//���Ϊ��ɫ
    goalNode.drawNode(background, imgGridSize, Scalar(0, 0, 255)); //Ŀ��λ��Ϊ��ɫ
}

int main(int argc, char* argv[]) {
    node startNode(40, 10);// ��ʼ��
    node goalNode(10, 40); // Ŀ���

    vector<vector<node*>> roadmap;// ��ͼ

    // ��ʼ��roadmap
    for (int i = 0; i < mapSize; ++i) {
        vector<node*> tmp;
        for (int j = 0; j < mapSize; ++j) {
            node* tmpNode = new node(i, j);
            tmp.push_back(tmpNode);
        }
        roadmap.push_back(tmp);
    }

    // ����ϰ���
    defineObstacle(roadmap);

    // ��һ������
    namedWindow("jps", WINDOW_NORMAL);
    
    Mat background(mapSize * imgGridSize,
               mapSize * imgGridSize,
               CV_8UC3,//8λ�޷���char��,3ͨ��
               cv::Scalar(0, 0, 0));

    // ������ͼ
    drawMap(background, startNode, goalNode, roadmap);
    imshow("jps", background);
    waitKey(500);

    int **pMap;//��ͼ��άָ������
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

    time_t time_start_ms,time_end_ms;//ʱ���¼ms
    time_start_ms = clock();//JpsPruneѰ·��ʼʱ��

    jps.Init(pMap, mapSize, mapSize);
    cout<<"--------FindPathPrune---------"<<"\n";
    jps.FindPathPrune(jStart, jEnd);

    time_end_ms = clock();//JpsPruneѰ·����ʱ��
    cout<<"JpsPrune run time��"<<difftime(time_end_ms, time_start_ms)<<"ms"<<endl;
    //����
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
