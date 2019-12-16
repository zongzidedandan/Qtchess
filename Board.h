#ifndef BOARD_H
#define BOARD_H

#include <QFrame>
#include "Stone.h"
#include "Step.h"
#include <QVector>

class Board : public QFrame
{
    Q_OBJECT
public:
    explicit Board(QWidget *parent = 0);
    ~Board();

    /* game data */
    Stone _s[32];  //棋子的个数
    int _r;        //棋子的半径 
    QPoint _off;   //棋盘于页面的距离 
    bool _bSide;   //指定红边还是黑边

    QVector<Step*> _steps;  //悔棋所记录的步数

    /* game status */
    int _selectid;  //  指走棋子的时候选中的是哪个棋子
    bool _bRedTurn; //红走还是黑走
    void init(bool bRedSide); //是初始还棋子的位置   红棋在下面还是黑棋在下面  

    /* draw functions */
    void paintEvent(QPaintEvent *);   //绘制棋盘
    void drawPlate(QPainter& p);    //绘制九宫格
    void drawPlace(QPainter& p);    // 楚河
    void drawInitPosition(QPainter& p); //绘制炮和兵的初始位置以及碎花
    void drawInitPosition(QPainter& p, int row, int col); //
    void drawStone(QPainter& p);    //绘制棋子
    void drawStone(QPainter& p, int id);  //

    /* function for coordinate */
    QPoint center(int row, int col);  //行和列的对应像素中心点 坐标转换函数
    QPoint center(int id);            //某一刻象棋的中心点的位置
    QPoint topLeft(int row, int col); //知道棋子的坐标点，来获取坐上角的点
    QPoint topLeft(int id);
    QRect cell(int row, int col);    //获得一个控制范围的点 
    QRect cell(int id);

    bool getClickRowCol(QPoint pt, int& row, int& col);   //通过点击事件知道棋盘的行和列

    /* help function */
    QString name(int id);   //通过名字来获取棋子的id
    bool red(int id);       //通过id 来判断是红棋还是黑棋
    bool sameColor(int id1, int id2); //通过id 来判断是不是
    int getStoneId(int row, int col);//通过棋盘的坐标来获取棋子的id 
    void killStone(int id); //
    void reliveStone(int id);
    void moveStone(int moveid, int row, int col);
    bool isDead(int id);

    /* move stone */
    void mouseReleaseEvent(QMouseEvent *);
    void click(QPoint pt);
    virtual void click(int id, int row, int col);
    void trySelectStone(int id); //尝试选择棋子的时候所显示的效果
    void tryMoveStone(int killid, int row, int col);
    void moveStone(int moveid, int killid, int row, int col);//会记录悔棋信息
    void saveStep(int moveid, int killid, int row, int col, QVector<Step*>& steps); //
    void backOne();//悔棋一步
    void back(Step* step);
    virtual void back(); //悔棋操作

    /* rule */
    bool canMove(int moveid, int killid, int row, int col);
    bool canMoveChe(int moveid, int killid, int row, int col);
    bool canMoveMa(int moveid, int killid, int row, int col);
    bool canMovePao(int moveid, int killid, int row, int col);
    bool canMoveBing(int moveid, int killid, int row, int col);
    bool canMoveJiang(int moveid, int killid, int row, int col);
    bool canMoveShi(int moveid, int killid, int row, int col);
    bool canMoveXiang(int moveid, int killid, int row, int col);

    bool canSelect(int id);  //棋子能不能选择

    /* rule helper */
    int getStoneCountAtLine(int row1, int col1, int row2, int col2);//看两个坐标点之间有没有棋子
    int relation(int row1, int col1, int row, int col);
    bool isBottomSide(int id); 

signals:

public slots:
    void slotBack();

};

#endif // BOARD_H
