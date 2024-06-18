#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->huojiachangdu->setRange(10000,50000);
    ui->huojiachangdu->setSingleStep(1000);
    ui->huojiachangdu->setValue(12000);
    ui->huowujianju->setRange(0,50);
    ui->huowujianju->setValue(10);
    ui->yiyouhuowu->setRange(0,100);
    ui->yiyouhuowu->setValue(20);
    ui->shuruhuowu->setRange(0,200);
    ui->shuruhuowu->setValue(50);
    ui->diedaicishu->setRange(0,500);
    ui->diedaicishu->setSingleStep(10);
    ui->diedaicishu->setValue(150);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::randomNumberGenerate(int start, int end)//随机数生成器
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution dis(start,end);
    int number=dis(gen);
    return number;
}

void Widget::generateItem()//随机生成入库货物的长度和重量
{
    for (int i = 0; i < ui->shuruhuowu->value(); ++i)
    {
        int itemLength = randomNumberGenerate(1000,9000);
        items.push_back({itemLength,itemLength*randomNumberGenerate(1,5)});
    }
}

void Widget::generatePlace()//随机生成已存在的货物并每层放一个（一层放多个有点点难，先不做）
{
    std::vector<int> itemOnShelf;
    for (int i = 0; i < ui->yiyouhuowu->value(); ++i)
    {
        itemOnShelf.push_back(randomNumberGenerate(1000,9000));
        int firstLength=randomNumberGenerate(0,ui->huojiachangdu->value()-itemOnShelf[i]);
        int secondLength=ui->huojiachangdu->value()-itemOnShelf[i]-firstLength;
        places.push_back({i,0,firstLength});
        if(secondLength > 1000+ui->huowujianju->value())
        {
            places.push_back({i,firstLength+itemOnShelf[i],secondLength});
        }
    }
}



void Widget::on_pushButton_clicked()
{
    generateItem();
    generatePlace();
    for (int i = 0; i < items.size(); ++i)
    {
        ui->shuchu->append(QString::number(items[i].length));
        ui->shuchu->append(QString::number(items[i].weight));
        ui->shuchu->append("----------");
    }
    for (int j = 0; j < places.size(); ++j)
    {
        ui->shuchu->append(QString::number(places[j].layer));
        ui->shuchu->append(QString::number(places[j].position));
        ui->shuchu->append(QString::number(places[j].length));
        ui->shuchu->append("----------");
    }
}

