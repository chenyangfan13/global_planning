#include"jps.h"


//�ж��ھ����ͣ��Ƿ�������ھӺ�ǿ���ھ�
//��Σ���Ԫ��ͼ8λ�����Ƹ�ʽ(ʮ���Ʒ�Χ0-255)�����ڵ�λ��(0-8)�������ھӵ�λ��(0-8)
//��ǰ���ڵ�Ԫ��ͼ��4λ��
bool* Jps::Prune(short unitMap,char p,char n){
    static bool retType[2];//���ص�����
    char obstaclePos = 0;

 #if 0
    //��Ԫ��ͼԤ����
    char unitMapTmp =0;
    if(p ==0){//��Ԫ��ͼ˳ʱ��ת180��
        unitMapTmp = unitMapTmp | (unitMap<<8 &(1<<8) );//0->8
        unitMapTmp = unitMapTmp | (unitMap<<6 &(1<<7) );//1->7
        unitMapTmp = unitMapTmp | (unitMap<<4 &(1<<6) );//2->6
        unitMapTmp = unitMapTmp | (unitMap<<2 &(1<<5) );//3->5
        unitMapTmp = unitMapTmp | (unitMap>>2 &(1<<3) );//5->3
        unitMapTmp = unitMapTmp | (unitMap>>4 &(1<<2) );//6->2
        unitMapTmp = unitMapTmp | (unitMap>>6 &(1<<1) );//7->1
        unitMapTmp = unitMapTmp | (unitMap>>8 &(1<<0) );//8->0
        p = 8;
    }
#endif // 0

    if(p == 0){
        if(n ==7 ||n ==5 || n ==8){
            retType[0] = true;
            retType[1] = false;
        }

        if(n ==2){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==3){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 1){
        if(n ==7){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==6){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 0||n ==2||n ==3||n ==5){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 2){
        if(n ==7 ||n ==6 || n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==5){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 3){
        if(n ==5){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==2){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 0||n ==1||n ==6||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 5){
        if(n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>1 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 1||n ==2||n ==7||n ==8){
            retType[0] = false;
            retType[1] = false;
        }
    }


    if(p == 6){
        if(n ==1 ||n ==2 || n ==5){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==8){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }

        if(n == 3||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    if(p == 7){
        if(n ==1){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==0){
            obstaclePos = unitMap>>3 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==2){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 3||n ==5||n ==6||n ==8){
            retType[0] = false;
            retType[1] = false;
        }

    }

    if(p == 8){
        if(n ==0 ||n ==1 || n ==3){
            retType[0] = true;
            retType[1] = false;
        }
        if(n ==2){
            obstaclePos = unitMap>>5 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n ==6){
            obstaclePos = unitMap>>7 & 0x01;
            if( 1 == obstaclePos){
                retType[0] = true;
                retType[1] = true;
            }
            if( 0 == obstaclePos){
                retType[0] = false;
                retType[1] = false;
            }
        }
        if(n == 5||n ==7){
            retType[0] = false;
            retType[1] = false;
        }
    }

    return retType;
}

void Jps::Init(int **_map,int _height,int _width){

    //��ʼ���սڵ�
    nullNode.isnull = true;
    nullNode.isMidJumpNode = false;

    height = _height;
    width = _width;

    //����������ͼ
    pathMap = new PathNode**[height];
    for(int i=0;i<height;i++){
        pathMap[i] = new PathNode*[width];
        for(int j=0;j<width;j++){
            pathMap[i][j] = new PathNode;
            memset(pathMap[i][j],0, sizeof(PathNode));
            pathMap[i][j]->row = i;
            pathMap[i][j]->col = j;
            pathMap[i][j]->isfind = false;
            pathMap[i][j]->isroute = false;
            pathMap[i][j]->value = _map[i][j];
        }
    }

}

//ֱ��Ծ��λ�����Ż���
//��Σ�������ͼ����ǰ�ڵ㡢ֱ��Ծ����-x����ֵ��y����ֵ
//��������
Jps::PathNode Jps::JumpStraightBit(PathNode*** _pathMap,PathNode currenNode,Direct dir){
    PathNode nodeTmp = currenNode;
    PathNode jumpNode = currenNode;

    unsigned int bitMap = 0;//��ʱ�ڵ㵱ǰ�л��������ж�λ��ͼ
    unsigned int bitMapUp = 0;//��ʱ�ڵ���һ�������ж�λ��ͼ
    unsigned int bitMapDown = 0;//��ʱ�ڵ���һ�������ж�λ��ͼ
    unsigned int bitMapLeft = 0;
    unsigned int bitMapRight = 0;

    char barrierUpBit = 0;//�ϰ�����һ��ֵ
    char barrierDownBit = 0;//�ϰ���һ��ֵ
    char barrierLeftBit = 0;//�ϰ���һ��ֵ
    char barrierRightBit = 0;//�ϰ���һ��ֵ
    char barrierLeftUpBit = 0;//�ϰ�����ֵ
    char barrierLeftDownBit = 0;//�ϰ�����ֵ
    char barrierRightUpBit = 0;//�ϰ�����ֵ
    char barrierRightDownBit = 0;//�ϰ�����ֵ

    int n,j;
    //���ݷ����ʼ����ʼ��Ѱ�ĵ�
    switch(dir)
    {
    case p_up:
        nodeTmp.row = currenNode.row -1;
        nodeTmp.col = currenNode.col;
        break;
    case p_down:
        nodeTmp.row = currenNode.row +1;
        nodeTmp.col = currenNode.col;
        break;
    case p_left:
        nodeTmp.row = currenNode.row;
        nodeTmp.col = currenNode.col -1;
        break;
    case p_right:
        nodeTmp.row = currenNode.row;
        nodeTmp.col = currenNode.col +1;
        break;
    default:
        break;
    }

    //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
    if(height <= nodeTmp.row || 0 > nodeTmp.row||
       width <= nodeTmp.col || 0 > nodeTmp.col ||
        1 == _pathMap[nodeTmp.row][nodeTmp.col]->value
       ){
        return nullNode;
    }

    while(1){
        //���λ��ͼ
        bitMapUp = 0;
        bitMap = 0;
        bitMapDown = 0;
        bitMapLeft = 0;
        bitMapRight = 0;
        //����ϰ�����Χ��ֵ
        barrierUpBit = 0;//�ϰ�����һ��ֵ
        barrierDownBit = 0;//�ϰ���һ��ֵ
        barrierLeftBit = 0;//�ϰ���һ��ֵ
        barrierRightBit = 0;//�ϰ���һ��ֵ
        barrierLeftUpBit = 0;//�ϰ�����ֵ
        barrierLeftDownBit = 0;//�ϰ�����ֵ
        barrierRightUpBit = 0;//�ϰ�����ֵ
        barrierRightDownBit = 0;//�ϰ�����ֵ


        //�����ʱ�ڵ㲻�ڵ�ͼ�У���˵���˴���Ѱû�����㣬ֱ�ӷ��ؿսڵ㣻
        if(0 > nodeTmp.row ||height <= nodeTmp.row ||0 > nodeTmp.col ||width <= nodeTmp.col) return nullNode;

        if(p_right == dir){
            //����λ��ͼ
            for(int i=0;i < 32;i++){
                if(0 <= nodeTmp.col +i && width >nodeTmp.col +i){//��������ڵ�ͼ������Χ��
                    if(0 <= nodeTmp.row -1 && height >nodeTmp.row +1){//û���������ڵ��ͼ
                        bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col +i]->value;
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -0][nodeTmp.col +i]->value;
                        bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col +i]->value;
                    }
                    if(0 > nodeTmp.row +1 ||height <= nodeTmp.row -1){//����ȫ������ͼ��ȫ��1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |1;
                        bitMap   = bitMap<<1 |1;
                        bitMapDown = bitMapDown<<1 |1;
                    }
                    if(0 == nodeTmp.row +1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |1;
                        bitMap   = bitMap   <<1 |1;
                        bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col +i]->value;
                    }
                    if(height -1 == nodeTmp.row -1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col +i]->value;
                        bitMap   = bitMap   <<1 |1;
                        bitMapDown = bitMapDown<<1 |1;
                    }
                    if(0 == nodeTmp.row ||height -1 == nodeTmp.row){//�м����ڵ�ͼ�ϻ��±߽���
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -0][nodeTmp.col +i]->value;
                        if(-1 == nodeTmp.row -1) bitMapUp = bitMapUp<<1 |1;//�����һ�����ϱ߽����һ�У���1
                        else bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col +i]->value;
                        if(height == nodeTmp.row +1) bitMapDown = bitMapDown<<1 |1;//�����һ�����±߽����һ�У���1
                        else bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col +i]->value;
                    }

                }
                else{//����������ڵ�ͼ������Χ��
                    bitMapUp = bitMapUp<<1 |1;
                    bitMap   = bitMap<<1 |1;
                    bitMapDown = bitMapDown<<1 |1;
                }
            }//end - ����λ��ͼ
            //bit map test
            //cout<<endl<<"bit map test:"<<bitMapUp<<" "<<bitMap<<" "<<bitMapDown<<endl;
            //cout<<""<<currenNode.row<<","<<currenNode.col<<endl;
            //cout<<"__builtin_clz(bitMap):"<<__builtin_clz(bitMap)<<endl;

            n = __builtin_clz(bitMap);
            barrierUpBit = bitMapUp>>(32 -n-1) &1;//��λ��ͼ�еõ��ϰ���Χ��ֵ
            barrierLeftUpBit = bitMapUp>>(32 -n-1 +1) &1;
            barrierDownBit = bitMapDown>>(32 -n-1) &1;
            barrierLeftDownBit = bitMapDown>>(32 -n-1 +1) &1;
            j = __builtin_clz(  ( (bitMapUp>>1)& (~bitMapUp)) |( (bitMapDown>>1)& (~bitMapDown)) );
            if(31 == n && 31 == j){//������뵱ǰ1-32����û�ҵ����㣬���л�����30��
                nodeTmp.row = nodeTmp.row;
                nodeTmp.col = nodeTmp.col + 30;
            }
            else{
                if(n <= j){
                    if( (1 == barrierLeftUpBit ||1 == barrierUpBit) &&
                       (1 == barrierLeftDownBit ||1 == barrierDownBit)
                       ) return nullNode;//������ϰ����(���� ||��) && (���� ||��)�ĵ�Ϊ�ϰ���֤���˴���Ѱû�����㣬ֱ�ӷ��ؿսڵ㣻
                    jumpNode.row = nodeTmp.row;
                    jumpNode.col = nodeTmp.col +n-1;
                    return jumpNode;
                }
                if(n > j){
                    jumpNode.row = nodeTmp.row;
                    jumpNode.col = nodeTmp.col +j-1;
                    return jumpNode;
                }
            }

        }
        if(p_left == dir){
            //����λ��ͼ
            for(int i=0;i < 32;i++){
                if(0 <= nodeTmp.col -i && width >nodeTmp.col -i){//��������ڵ�ͼ������Χ��
                    if(0 <= nodeTmp.row -1 && height >nodeTmp.row +1){//û���������ڵ��ͼ
                        bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col -i]->value;
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -0][nodeTmp.col -i]->value;
                        bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col -i]->value;
                    }
                    if(0 > nodeTmp.row +1 ||height <= nodeTmp.row -1){//����ȫ������ͼ��ȫ��1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |1;
                        bitMap   = bitMap<<1 |1;
                        bitMapDown = bitMapDown<<1 |1;
                    }
                    if(0 == nodeTmp.row +1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |1;
                        bitMap   = bitMap   <<1 |1;
                        bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col -i]->value;
                    }
                    if(height -1 == nodeTmp.row -1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col -i]->value;
                        bitMap   = bitMap   <<1 |1;
                        bitMapDown = bitMapDown<<1 |1;
                    }
                    if(0 == nodeTmp.row ||height -1 == nodeTmp.row){//�м����ڵ�ͼ�ϻ��±߽���
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -0][nodeTmp.col -i]->value;
                        if(-1 == nodeTmp.row -1) bitMapUp = bitMapUp<<1 |1;//�����һ�����ϱ߽����һ�У���1
                        else bitMapUp = bitMapUp<<1 |_pathMap[nodeTmp.row -1][nodeTmp.col -i]->value;
                        if(height == nodeTmp.row +1) bitMapDown = bitMapDown<<1 |1;//�����һ�����±߽����һ�У���1
                        else bitMapDown = bitMapDown<<1 |_pathMap[nodeTmp.row +1][nodeTmp.col -i]->value;
                    }

                }
                else{//����������ڵ�ͼ������Χ��
                    bitMapUp = bitMapUp<<1 |1;
                    bitMap   = bitMap<<1 |1;
                    bitMapDown = bitMapDown<<1 |1;
                }
            }//end - ����λ��ͼ
            //bit map test
            //cout<<endl<<"bit map test:"<<bitMapUp<<" "<<bitMap<<" "<<bitMapDown<<endl;
            //cout<<""<<currenNode.row<<","<<currenNode.col<<endl;
            //cout<<"__builtin_clz(bitMap):"<<__builtin_clz(bitMap)<<endl;

            n = __builtin_clz(bitMap);
            barrierUpBit = bitMapUp>>(32 -n-1) &1;//��λ��ͼ�еõ��ϰ���Χ��ֵ
            barrierRightUpBit = bitMapUp>>(32 -n-1 +1) &1;
            barrierDownBit = bitMapDown>>(32 -n-1) &1;
            barrierRightDownBit = bitMapDown>>(32 -n-1 +1) &1;
            j = __builtin_clz(  ( (bitMapUp>>1)& (~bitMapUp)) |( (bitMapDown>>1)& (~bitMapDown)) );
            if(31 == n && 31 == j){//������뵱ǰ1-32����û�ҵ����㣬���л�����30��
                nodeTmp.row = nodeTmp.row;
                nodeTmp.col = nodeTmp.col - 30;
            }
            else{
                if(n <= j){
                    if( (1 == barrierRightUpBit ||1 == barrierUpBit) &&
                       (1 == barrierRightDownBit ||1 == barrierDownBit)
                       ) return nullNode;//������ϰ����(���� ||��) && (���� ||��)�ĵ�Ϊ�ϰ���֤���˴���Ѱû�����㣬ֱ�ӷ��ؿսڵ㣻
                    jumpNode.row = nodeTmp.row;
                    jumpNode.col = nodeTmp.col -n+1;
                    return jumpNode;
                }
                if(n > j){
                    jumpNode.row = nodeTmp.row;
                    jumpNode.col = nodeTmp.col -j+1;
                    return jumpNode;
                }
            }

        }//end-if(p_left == dir)
        if(p_down == dir){
            //����λ��ͼ
            for(int i=0;i < 32;i++){
                if(0 <= nodeTmp.row +i && height >nodeTmp.row +i){//��������ڵ�ͼ������Χ��
                    if(0 <= nodeTmp.col -1 && width >nodeTmp.col +1){//û���������ڵ��ͼ
                        bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col -1]->value;
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col + 0]->value;
                        bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col +1]->value;
                    }
                    if(0 > nodeTmp.col +1 ||width <= nodeTmp.col -1){//����ȫ������ͼ��ȫ��1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |1;
                        bitMap   = bitMap<<1 |1;
                        bitMapRight = bitMapRight<<1 |1;
                    }
                    if(0 == nodeTmp.col +1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |1;
                        bitMap   = bitMap   <<1 |1;
                        bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col +1]->value;
                    }
                    if(width -1 == nodeTmp.col -1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col -1]->value;
                        bitMap   = bitMap   <<1 |1;
                        bitMapRight = bitMapRight<<1 |1;
                    }
                    if(0 == nodeTmp.col ||width -1 == nodeTmp.col){//�м����ڵ�ͼ����ұ߽���
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col]->value;
                        if(-1 == nodeTmp.col -1) bitMapLeft = bitMapLeft<<1 |1;//�����һ������߽����һ�У���1
                        else bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col -1]->value;
                        if(width == nodeTmp.col +1) bitMapRight = bitMapRight<<1 |1;//�����һ�����ұ߽����һ�У���1
                        else bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row +i][nodeTmp.col +1]->value;
                    }

                }
                else{//����������ڵ�ͼ������Χ��
                    bitMapLeft = bitMapLeft<<1 |1;
                    bitMap   = bitMap<<1 |1;
                    bitMapRight = bitMapRight<<1 |1;
                }
            }//end - ����λ��ͼ
            //bit map test
            //cout<<endl<<"bit map test:"<<bitMapLeft<<" "<<bitMap<<" "<<bitMapRight<<endl;
            //cout<<""<<currenNode.row<<","<<currenNode.col<<endl;
            //cout<<"__builtin_clz(bitMap):"<<__builtin_clz(bitMap)<<endl;

            n = __builtin_clz(bitMap);
            barrierLeftBit = bitMapLeft>>(32 -n-1) &1;//��λ��ͼ�еõ��ϰ���Χ��ֵ
            barrierLeftUpBit = bitMapLeft>>(32 -n-1 +1) &1;
            barrierRightBit = bitMapRight>>(32 -n-1) &1;
            barrierRightUpBit = bitMapRight>>(32 -n-1 +1) &1;

            j = __builtin_clz( ( (bitMapLeft>>1)& (~bitMapLeft)) |( (bitMapRight>>1)& (~bitMapRight)) );
            if(31 == n && 31 == j){ //__builtin_clz( (unsigned int)0 ) ��ֵΪ31
                nodeTmp.row = nodeTmp.row + 30;
                nodeTmp.col = nodeTmp.col;
            }
            else{
                if(n <= j){
                    if( (1 == barrierLeftUpBit ||1 == barrierLeftBit) &&
                       (1 == barrierRightUpBit ||1 == barrierRightBit)
                       ) return nullNode;//������ϰ����(���� ||��) && (���� ||��)�ĵ�Ϊ�ϰ���֤���˴���Ѱû�����㣬ֱ�ӷ��ؿսڵ㣻
                    jumpNode.row = nodeTmp.row +n-1;
                    jumpNode.col = nodeTmp.col;
                    return jumpNode;
                }
                if(n > j){
                    jumpNode.row = nodeTmp.row +j-1;
                    jumpNode.col = nodeTmp.col;
                    return jumpNode;
                }
            }
        }//end-if(p_down == dir)
        if(p_up == dir){
            //����λ��ͼ
            for(int i=0;i < 32;i++){
                if(0 <= nodeTmp.row -i && height >nodeTmp.row -i){//��������ڵ�ͼ������Χ��
                    if(0 <= nodeTmp.col -1 && width >nodeTmp.col +1){//��ǰ��û���������ڵ��ͼ
                        bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col -1]->value;
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col + 0]->value;
                        bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col +1]->value;
                    }
                    if(0 > nodeTmp.col +1 ||width <= nodeTmp.col -1){//����ȫ������ͼ��ȫ��1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |1;
                        bitMap   = bitMap<<1 |1;
                        bitMapRight = bitMapRight<<1 |1;
                    }
                    if(0 == nodeTmp.col +1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |1;
                        bitMap   = bitMap   <<1 |1;
                        bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col +1]->value;
                    }
                    if(width -1 == nodeTmp.col -1){//�����г�����ͼ����������1���ȼ�Ϊ�ϰ�
                        bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col -1]->value;
                        bitMap   = bitMap   <<1 |1;
                        bitMapRight = bitMapRight<<1 |1;
                    }
                    if(0 == nodeTmp.col ||width -1 == nodeTmp.col){//�м����ڵ�ͼ����ұ߽���
                        bitMap   = bitMap<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col]->value;
                        if(-1 == nodeTmp.col -1) bitMapLeft = bitMapLeft<<1 |1;//�����һ������߽����һ�У���1
                        else bitMapLeft = bitMapLeft<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col -1]->value;
                        if(width == nodeTmp.col +1) bitMapRight = bitMapRight<<1 |1;//�����һ�����ұ߽����һ�У���1
                        else bitMapRight = bitMapRight<<1 |_pathMap[nodeTmp.row -i][nodeTmp.col +1]->value;
                    }

                }
                else{//����������ڵ�ͼ������Χ��
                    bitMapLeft = bitMapLeft<<1 |1;
                    bitMap   = bitMap<<1 |1;
                    bitMapRight = bitMapRight<<1 |1;
                }
            }//end - ����λ��ͼ
            //bit map test
            //cout<<endl<<"bit map test:"<<bitMapLeft<<" "<<bitMap<<" "<<bitMapRight<<endl;
            //cout<<""<<currenNode.row<<","<<currenNode.col<<endl;
            //cout<<"__builtin_clz(bitMap):"<<__builtin_clz(bitMap)<<endl;

            n = __builtin_clz(bitMap);
            barrierLeftBit = bitMapLeft>>(32 -n-1) &1;//��λ��ͼ�еõ��ϰ���Χ��ֵ
            barrierLeftDownBit = bitMapLeft>>(32 -n-1 +1) &1;
            barrierRightBit = bitMapRight>>(32 -n-1) &1;
            barrierRightDownBit = bitMapRight>>(32 -n-1 +1) &1;

            j = __builtin_clz( ( (bitMapLeft>>1)& (~bitMapLeft)) |( (bitMapRight>>1)& (~bitMapRight)) );
            if(31 == n && 31 == j){ //__builtin_clz( (unsigned int)0 ) ��ֵΪ31
                nodeTmp.row = nodeTmp.row + 30;
                nodeTmp.col = nodeTmp.col;
            }
            else{
                if(n <= j){
                    if( (1 == barrierLeftDownBit ||1 == barrierLeftBit) &&
                       (1 == barrierRightDownBit ||1 == barrierRightBit)
                       ) return nullNode;//������ϰ����(���� ||��) && (���� ||��)�ĵ�Ϊ�ϰ���֤���˴���Ѱû�����㣬ֱ�ӷ��ؿսڵ㣻
                    jumpNode.row = nodeTmp.row -n+1;
                    jumpNode.col = nodeTmp.col;
                    return jumpNode;
                }
                if(n > j){
                    jumpNode.row = nodeTmp.row -j+1;
                    jumpNode.col = nodeTmp.col;
                    return jumpNode;
                }
            }
        }//end-if(p_up == dir)

    }

    return nullNode;
}


Jps::PathNode* Jps::JumpOblique(PathNode*** _pathMap,PathNode currenNode,Direct dir){
    static PathNode retNode[3];
    int delta_x = 0;
    int delta_y = 0;
    short unitMap = 0;
    char valueT = 0;//�洢������ͼ�е����ʱֵ�����������Ԫ��ͼֵ
    bool* nodeTyp;
    char parent;//��Ԫ��ͼ�У����ڵ�
    char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//��Ԫ��ͼ��,Ҫ̽����ھ��飬��ʼ��Ϊ��(0-8)��ֵ��Ϊ9�ĵ�Ϊ�����е�
    Direct straightDirs[2] = {p_up,p_up};
    switch(dir)
    {
    case p_leftup:
        delta_x = -1;
        delta_y = -1;
        parent = 8;
        straightDirs[0] = p_left;
        straightDirs[1] = p_up;
        break;
    case p_leftdown:
        delta_x = -1;
        delta_y = 1;
        parent = 2;
        straightDirs[0] = p_left;
        straightDirs[1] = p_down;
        break;
    case p_rightup:
        delta_x = 1;
        delta_y = -1;
        parent = 6;
        straightDirs[0] = p_right;
        straightDirs[1] = p_up;
        break;
    case p_rightdown:
        delta_x = 1;
        delta_y = 1;
        parent = 0;
        straightDirs[0] = p_right;
        straightDirs[1] = p_down;
        break;
    default:
        break;
    }

    PathNode nodeTmp = currenNode;//��ָ��������Ѱ�ĵ�
    //��ָ��������Ѱ��ֱ���ҵ����㣬�������ϰ���򳬳���ͼ
    while(1){
        for(int i=0;i <3; i++){//��ʼ��retnode���ÿսڵ�
            retNode[i] = nullNode;
        }
        nodeTmp.row += delta_y;
        nodeTmp.col += delta_x;
        //cout<<"б��Ծ��"<<nodeTmp.row<<","<<nodeTmp.col<<endl;
        //�����Ѱ���յ�ͷ���
        if(nodeTmp.row == endNode.row &&
           nodeTmp.col == endNode.col){
            retNode[0] = nodeTmp;
            return retNode;
           }
        //�����Ѱ�㣬���ϰ�����߳��˵�ͼ�����ؿ�
        if(height <= nodeTmp.row || 0 > nodeTmp.row||
           width <= nodeTmp.col || 0 > nodeTmp.col ||
            1 == _pathMap[nodeTmp.row][nodeTmp.col]->value
           ){
            retNode[0] = nullNode;
            return retNode;
           }

        //��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���
        unitMap = 0;//��յ�Ԫ��ͼ
        for(int i=0; i<9; i++){//��ʼ���ھ���
            neighbGroup[i] = 9;
        }

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = nodeTmp.row +i-1;//��ȡ��Χ�ĵ��ֵ
                int col_t = nodeTmp.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//ȷ����Χ��û������ͼ
                    valueT = _pathMap[row_t][col_t]->value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//��Ϊ�ϰ�
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        //��ȡ��ǰ��Ѱ����Χ�����ͣ��������ǿ���ھӣ����ص�ǰ��Ѱ��
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               parent != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//����ھ����е㲻Ϊ����(9)����ǰ��Ѱ��(4)�����ڵ�
                nodeTyp = Prune(unitMap, parent, neighbGroup[i]);
                if(1 == nodeTyp[1]){//�������ǿ���ھӣ����ص�ǰ��Ѱ��
                    retNode[0] = nodeTmp;
                    retNode[0].isMidJumpNode = false;
                    return retNode;
                }

            }
        }//end-��ȡ��ǰ��Ѱ����Χ������

        //����ǰ���ֱ�ߡ��档�ھӡ�����ֱ��Ծ����������ؿգ����ص�ǰ��
        PathNode jumpNode;//���ڱ���ֱ��Ծ�ķ��ؽڵ�
        bool willRet = false;
        for(int i=0;i <2; i++){
            jumpNode = JumpStraightBit(_pathMap, nodeTmp, straightDirs[i]);    //----------------�޸�
            if(false == jumpNode.isnull){
                willRet = true;
                retNode[0] = nodeTmp;
                retNode[0].isMidJumpNode = true;
                retNode[i +1] = jumpNode;
            }
            if(jumpNode.isnull){
                retNode[i +1] = jumpNode;
            }
        }
        if(willRet) return retNode;


    }
}



//Ѱ·�����ü�֦
vector<Jps::PathNode> Jps::FindPathPrune(PathNode _startNode,PathNode _endNode){
    //���ÿ�ʼ������
    startNode = _startNode;
    endNode = _endNode;
    bool findGoal = false;//�Ƿ��ҵ��˽���Ŀ��

    vector<Direct> jumpDirs;//��ŵ�ǰ��Ҫ��Ծ�ķ���
    vector<Direct>::iterator dirsIt;//���ڼ����������ĵ�����
    PathNode jumpNode;//���ص�����
    PathNode* jumpNodes = new PathNode[3];//���ص�������
    bool* nodeTyp;//���ص��ھ�����

    PathNode currentNode;//��ǰ�ڵ�
    vector<PathNode> openTree;//�����б��ر��б����ø�����ͼ�����isfind����ά����
    vector<PathNode>::iterator it;//���ڵ���
    vector<PathNode>::iterator minF_iter;//�����Сfֵ�ڵ�

    currentNode =  startNode;//��ǰ��Ϊ��ʼ��
    pathMap[currentNode.row][currentNode.col]->isfind = true;

    //Ϊ���ҵ��յ㣬���յ���Ϊ�ϰ������ܼ�⵽�յ���Χ������ʱ����һ���ҵ��յ�
    pathMap[endNode.row][endNode.col]->value = 1;

    //��ʼ���������˸�����
    for(int i=0;i <8;i++){
        jumpDirs.push_back( (Direct)i);
    }

    //Ѱ·
    while(1){
        //���õ�ǰ�㣬�Լ�parent���������С��档�ھӡ�������Ծ
        for(dirsIt = jumpDirs.begin();dirsIt != jumpDirs.end(); dirsIt++){
            PathNode nodeTmp = currentNode;//��ʱ�����ڵ㣬���ڵ�ǰ�����ϵļ���
            while(1){//�ڵ�ǰ����һֱѰ�����㣬ֱ��û���ҵ�����
                //cout<<"����"<<(*dirsIt)<<" "<<endl;
                for(int i=0;i <3; i++){
                    jumpNodes[i] = nullNode;
                }
                if( *(dirsIt) == p_up|| *(dirsIt) == p_down|| *(dirsIt) == p_left|| *(dirsIt) == p_right){
                    jumpNodes[0] = JumpStraightBit(pathMap, nodeTmp, (*dirsIt) );
                }
                if( *(dirsIt) == p_leftup|| *(dirsIt) == p_leftdown|| *(dirsIt) == p_rightup|| *(dirsIt) == p_rightdown){
                    jumpNodes = JumpOblique(pathMap, nodeTmp, (*dirsIt) );
                }

                //�ӷ��صĽڵ��У���Ѱ���㣬������g��h��fֵ
                for(int i =0;i <3; i++){
                    //������ص�����Ч�ڵ㣬�Ҳ��ڹر��б��У�δ�ҹ���
                    if(false == jumpNodes[i].isnull &&
                       false == pathMap[jumpNodes[i].row][jumpNodes[i].col]->isfind &&//���ڹر��б��У�δ�ҹ���
                       false == jumpNodes[i].isMidJumpNode)//�����м�����
                       {
                        PathNode parentTmp;//��ʱ���ڵ㣬���ڼ���gֵ���ж��Ƿ���¸��ڵ�
                        if(pathMap[nodeTmp.row][nodeTmp.col]->isMidJumpNode){//������ֵ�ǰ��Ϊ�м�����,�ͰѺ����ڵ�ĸ��ڵ���Ϊ��ǰ�ڵ�ĸ��ڵ�
                            parentTmp.row = pathMap[nodeTmp.row][nodeTmp.col]->parent->row;
                            parentTmp.col = pathMap[nodeTmp.row][nodeTmp.col]->parent->col;
                        }
                        if(false == pathMap[nodeTmp.row][nodeTmp.col]->isMidJumpNode){//������ֵ�ǰ�㲻���м�����
                            parentTmp.row = pathMap[nodeTmp.row][nodeTmp.col]->row;
                            parentTmp.col = pathMap[nodeTmp.row][nodeTmp.col]->col;
                        }
                        jumpNodes[i].g = pathMap[parentTmp.row][parentTmp.col]->g +GetDis( parentTmp, jumpNodes[i]);
                        //����õ��Ѿ��ڿ����б��У��Ƚ�gֵ��ȡgֵ��С�ĵ�����ԣ��������ٴμ��뿪���б�
                        if(pathMap[jumpNodes[i].row][jumpNodes[i].col]->inopen){
                            if(pathMap[jumpNodes[i].row][jumpNodes[i].col]->g > jumpNodes[i].g){
                                pathMap[jumpNodes[i].row][jumpNodes[i].col]->g = jumpNodes[i].g;
                                pathMap[jumpNodes[i].row][jumpNodes[i].col]->GetF();

                                pathMap[jumpNodes[i].row][jumpNodes[i].col]->parent = pathMap[parentTmp.row][parentTmp.col];
                            }

                        }
                        //������ڿ����б���
                        if(false == pathMap[jumpNodes[i].row][jumpNodes[i].col]->inopen){
                            jumpNodes[i].h = GetH(jumpNodes[i], endNode);
                            jumpNodes[i].GetF();
                            jumpNodes[i].inopen = true;

                            //��̽�����뿪���б�
                            openTree.push_back(jumpNodes[i]);
                            //���¸�����ͼ�ж�Ӧ̽���Ľڵ�����
                            pathMap[jumpNodes[i].row][jumpNodes[i].col]->g = jumpNodes[i].g;
                            pathMap[jumpNodes[i].row][jumpNodes[i].col]->h = jumpNodes[i].h;
                            pathMap[jumpNodes[i].row][jumpNodes[i].col]->f = jumpNodes[i].f;
                            pathMap[jumpNodes[i].row][jumpNodes[i].col]->parent = pathMap[parentTmp.row][parentTmp.col];
                            pathMap[jumpNodes[i].row][jumpNodes[i].col]->inopen = jumpNodes[i].inopen;
                        }
                        //�ж��Ƿ��ҵ����յ�--������Χ�����յ�
                        int t_row,t_col;
                        t_row = jumpNodes[i].row;
                        t_col = jumpNodes[i].col;
                        if(endNode.row == jumpNodes[i].row){
                            if(endNode.col == t_col -1 ||
                               endNode.col == t_col +1
                               ){
                                findGoal = true;
                                pathMap[endNode.row][endNode.col]->parent = pathMap[jumpNodes[i].row][jumpNodes[i].col];
                                break;
                               }
                        }
                        if(endNode.col == jumpNodes[i].col){
                            if(endNode.row == t_row -1 ||
                               endNode.row == t_row +1
                               ){
                                findGoal = true;
                                pathMap[endNode.row][endNode.col]->parent = pathMap[jumpNodes[i].row][jumpNodes[i].col];
                                break;
                               }
                        }

                    }//end--//������ص�����Ч�ڵ㣬�Ҳ��ڹر��б��У�δ�ҹ���


                }//end--�ӷ��صĽڵ��У���Ѱ���㣬������g��h��fֵ

                if(findGoal) break;

                if(false == jumpNodes[0].isnull &&
                   false == pathMap[jumpNodes[0].row][jumpNodes[0].col]->inopen &&//���ڿ����б�
                   jumpNodes[0].isMidJumpNode) //����ҵ��м����㣬��Ǹ�����ͼ�иõ���м���������Ϊtrue
                {
                    pathMap[jumpNodes[0].row][jumpNodes[0].col]->isMidJumpNode = true;
                    if(pathMap[nodeTmp.row][nodeTmp.col]->isMidJumpNode){//�����ǰ������Ϊ�м����㣬�������ҵ����м�����ĸ��ڵ�Ϊ��ǰ������ĸ��ڵ�
                        PathNode parentTmp;
                        parentTmp.row = pathMap[nodeTmp.row][nodeTmp.col]->parent->row;
                        parentTmp.col = pathMap[nodeTmp.row][nodeTmp.col]->parent->col;
                        pathMap[jumpNodes[0].row][jumpNodes[0].col]->parent = pathMap[parentTmp.row][parentTmp.col];
                    }
                    if(false == pathMap[nodeTmp.row][nodeTmp.col]->isMidJumpNode)
                        pathMap[jumpNodes[0].row][jumpNodes[0].col]->parent = pathMap[nodeTmp.row][nodeTmp.col];
                }
                //����ҵ����㣬�ѵ�ǰ��������Ϊ������
                if(false == jumpNodes[0].isnull){
                    nodeTmp.row = jumpNodes[0].row;
                    nodeTmp.col = jumpNodes[0].col;
                }

                if(jumpNodes[0].isnull) break;//���û���ҵ����㣬��������ǰ�����ѭ��

            }//end--while(1)//�ڵ�ǰ����һֱѰ������

            if(findGoal) break;
        }//end---for(dirsIt = jumpDirs.begin();dirsIt != jumpDirs.end(); dirsIt++)

        if(findGoal) break;

        if(openTree.size() == 0) break;
        //����һ��
        minF_iter = openTree.begin();
        //cout<<endl<<"����һ��"<<endl;
        for(it =openTree.begin();it !=openTree.end(); it++){
            //cout<<(*it).row<<","<<(*it).col<<endl;
            if(pathMap[(*it).row][(*it).col]->f < pathMap[(*minF_iter).row][(*minF_iter).col]->f){
                minF_iter = it;
            }
        }

#if 0   //����
        cout<<endl<<"�ҵ�����һ��: ";
        cout<<(*minF_iter).row<<","<<(*minF_iter).col<<endl;
        cout<<"�˽ڵ㸸�ڵ����꣺";
        PathNode tmp = { (*minF_iter).row,(*minF_iter).col};
        while(NULL != pathMap[tmp.row][tmp.col]->parent){
            int t_row = tmp.row,t_col = tmp.col;
            tmp.row = pathMap[t_row][t_col]->parent->row;
            tmp.col = pathMap[t_row][t_col]->parent->col;
            cout<<tmp.row<<","<<tmp.col<<" ";
        }
        cout<<endl;
#endif

        currentNode = (*minF_iter);
        pathMap[currentNode.row][currentNode.col]->isfind = true;

        if(currentNode.row == endNode.row && currentNode.col == endNode.col) break;

        openTree.erase(minF_iter);

        //��ȡ��ǰ�ڵ㼴��Ҫ��Ѱ�ķ���jumpDirs
        jumpDirs.clear();
        int delta_y = currentNode.row - pathMap[currentNode.row][currentNode.col]->parent->row;
        int delta_x = currentNode.col - pathMap[currentNode.row][currentNode.col]->parent->col;
        char p;//��Ԫ��ͼ�и���
        short unitMap = 0;
        char neighbGroup[9] = {9,9,9,9,9,9,9,9,9};//��Ԫ��ͼ��,Ҫ̽����ھ��飬��ʼ��Ϊ��(0-8)��ֵ��Ϊ9�ĵ�Ϊ�����е�

        if(0 > delta_y && 0 ==delta_x) p = 7;//��Ѱ����Ϊ��
        if(0 < delta_y && 0 ==delta_x) p = 1;//��Ѱ����Ϊ��
        if(0 == delta_y && 0 >delta_x) p = 5;//��Ѱ����Ϊ��
        if(0 == delta_y && 0 <delta_x) p = 3;//��Ѱ����Ϊ��

        if(0 > delta_y && 0 >delta_x) p = 8;//��Ѱ����Ϊ����
        if(0 < delta_y && 0 >delta_x) p = 2;//��Ѱ����Ϊ����
        if(0 > delta_y && 0 <delta_x) p = 6;//��Ѱ����Ϊ����
        if(0 < delta_y && 0 <delta_x) p = 0;//

        //��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        for(int i = 0;i <3; i++){
            for(int j= 0;j <3; j++){
                int row_t = currentNode.row +i-1;//��ȡ��Χ�ĵ�����
                int col_t = currentNode.col +j-1;
                if(height > row_t && 0 <= row_t &&
                    width > col_t && 0 <= col_t
                    ){//ȷ����Χ��û������ͼ
                    int valueT = pathMap[row_t][col_t]->value;
                    unitMap = unitMap|valueT<<(i*3 +j);
                    if(1 != valueT){//��Ϊ�ϰ�
                        neighbGroup[i*3+j] = (i*3 +j);
                    }
                }
            }
        }//end-��ȡ��Ѱ����Χ3x3��Ԫ��ͼ�����ҵ��ھ���

        //��ȡ��ǰ��Ѱ����Χ�����ͣ�����ֵ̽�ⷽ����
        for(int i=0;i <9;i++){
            if(9 != neighbGroup[i] &&
               p != neighbGroup[i] &&
               4 != neighbGroup[i]
               ){//����ھ����е㲻Ϊ����(9)����ǰ��Ѱ��(4)�����ڵ�
                nodeTyp = Prune(unitMap, p, neighbGroup[i]);
                if(1 == nodeTyp[0]){//������ڹؼ��ھӣ�����̽�ⷽ�����м��뵱ǰ����
                    if(1==i) jumpDirs.push_back(p_up);
                    if(7==i) jumpDirs.push_back(p_down);
                    if(3==i) jumpDirs.push_back(p_left);
                    if(5==i) jumpDirs.push_back(p_right);

                    if(0==i) jumpDirs.push_back(p_leftup);
                    if(6==i) jumpDirs.push_back(p_leftdown);
                    if(2==i) jumpDirs.push_back(p_rightup);
                    if(8==i) jumpDirs.push_back(p_rightdown);

                }

            }
        }//end-��ȡ��ǰ��Ѱ����Χ�����ͣ�����ֵ̽�ⷽ����

        //system("pause");
    }//end-Ѱ·-while(1)

    //����·��
    vector<PathNode> retPathTmp;
    PathNode nodeTmp = endNode;
    while(1){
        int row_t = nodeTmp.row;
        int col_t = nodeTmp.col;
        retPathTmp.push_back(nodeTmp);
        if(NULL == pathMap[nodeTmp.row][nodeTmp.col]->parent) break;
        nodeTmp.row = pathMap[row_t][col_t]->parent->row;
        nodeTmp.col = pathMap[row_t][col_t]->parent->col;
    }
    //��·������Ϊ�ӿ�ʼ�������˳��
    for(it =retPathTmp.end()-1;it != retPathTmp.begin() -1; it--){
        retPath.push_back(*it);
    }

    vector<PathNode>().swap(retPathTmp);//�ͷ��ڴ�
    return retPath;


}

void Jps::PrintRoute(){
      cout<<retPath[5].row<<"  "<<retPath[5].col<<endl;
      cout<<retPath[6].row<<"  "<<retPath[6].col<<endl;
      cout<<retPath.size()<<endl;
//    vector<PathNode>::iterator it;//���ڵ��� 
//    for(it =retPath.begin();it != retPath.end(); it++){
//        node temp_node((*it).row,(*it).col);
//        temp_node.drawNode(background, imgGridSize, Scalar(0, 255, 255),1);
//        imshow("jps",background);
//        waitKey(5);
//    }
//    //
//    //while(retPath){
//    //    retPath.begin().drawNode(background, imgGridSize, Scalar(0,255,255),1);
//    //    imshow("jps",background);
//    //    waitKey(5);   
//    //}
}
vector<Jps::PathNode> Jps::translatenode()
{
    return retPath;
}
