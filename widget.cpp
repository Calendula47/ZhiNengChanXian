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
    totalItemLength=0;
    for (int i = 0; i < ui->shuruhuowu->value(); ++i)
    {
        int itemLength = randomNumberGenerate(100,900);
        items.push_back({itemLength,itemLength*randomNumberGenerate(1,5)});
        totalItemLength+=itemLength;
    }
}

void Widget::generatePlace()//随机生成已存在的货物并随机放在货架的层上
{
    for (int i = 0; i < ui->yiyouhuowu->value(); ++i)//随机生成已存在的货物
    {
        itemOnShelf.push_back(randomNumberGenerate(100,900));
    }

    totalPlaceLength=0;

    int currentLayer = 0;
    int currentItemOnShelfID = 0;
    while(totalPlaceLength<=totalItemLength)
    {
        int usedLength = 0;
        int itemsOnThisLayer = randomNumberGenerate(0,3);
        if (itemsOnThisLayer == 0)//如果这层放0个货物则直接输出整个layer长度
        {
            places.push_back({currentLayer,0,ui->huojiachangdu->value()});
            totalPlaceLength+=ui->huojiachangdu->value();
        }
        else
        {
            for(int i = 0; i < itemsOnThisLayer; ++i)
            {
                if(currentItemOnShelfID<itemOnShelf.size())//如果还有货物
                {
                    int thisLength=randomNumberGenerate(0,(ui->huojiachangdu->value()-usedLength)/(itemsOnThisLayer-i+1));//随机生成一个空位长度，长度范围为剩余长度/本层未放置的物品数量
                    usedLength+=thisLength;
                    if(thisLength>=100+ui->huowujianju->value())//如果这一位能放下物品则记录其数值
                    {
                        places.push_back({currentLayer,usedLength-thisLength,thisLength});
                        totalPlaceLength+=thisLength;
                    }
                    usedLength+=itemOnShelf[currentItemOnShelfID];
                    ++currentItemOnShelfID;
                }
                else
                {break;}
            }
            if(ui->huojiachangdu->value()-usedLength>=100+ui->huowujianju->value())//如果本层还有位置
            {
                places.push_back({currentLayer,usedLength,ui->huojiachangdu->value()-usedLength});
                totalPlaceLength+=ui->huojiachangdu->value()-usedLength;
            }
        }
        ++currentLayer;
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

