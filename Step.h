#ifndef STEP_H
#define STEP_H

#include <QObject>
//主要用在悔棋的一方面
class Step : public QObject
{
    Q_OBJECT
public:
    explicit Step(QObject *parent = 0);  //最优走法
    ~Step();

    int _moveid;    //走的是哪步棋
    int _killid;    //我走了棋之后哪个骑被杀了
    int _rowFrom;   //c从哪里过去的
    int _colFrom;   
    int _rowTo;      //到哪里去
    int _colTo;

signals:

public slots:
};

#endif // STEP_H
