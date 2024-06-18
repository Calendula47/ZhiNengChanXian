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
    ui->zuixiaochangdu->setRange(100,300);
    ui->zuixiaochangdu->setSingleStep(50);
    ui->zuixiaochangdu->setValue(100);
    ui->zuidachangdu->setRange(500,1500);
    ui->zuidachangdu->setSingleStep(50);
    ui->zuidachangdu->setValue(900);
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
    int number = dis(gen);
    return number;
}

void Widget::generateItem()//随机生成入库货物的长度和重量
{
    totalItemLength=0;
    for (int i = 0; i < ui->shuruhuowu->value(); ++i)
    {
        int itemLength = randomNumberGenerate(ui->zuixiaochangdu->value(),ui->zuidachangdu->value());
        items.push_back({itemLength, itemLength * randomNumberGenerate(1,5)});
        totalItemLength += (itemLength + ui->huowujianju->value());
    }
}

void Widget::generatePlace()//随机生成已存在的货物并随机放在货架的层上
{
    for (int i = 0; i < ui->yiyouhuowu->value(); ++i)//随机生成已存在的货物，货物的大小从10cm~90cm不等
    {
        itemOnShelf.push_back(randomNumberGenerate(ui->zuixiaochangdu->value(),ui->zuidachangdu->value()));
    }

    totalPlaceLength=0;
    int currentLayer = 0;
    int currentItemOnShelfID = 0;
    while(totalPlaceLength <= totalItemLength + ui->huojiachangdu->value())//检测当前生成的所有空段能否放下所有物体，且给出一整排货架长度作为缓冲以免遗传算法生成个体时难以生成可行解
    {
        int usedLength = 0;
        int itemsOnThisLayer = randomNumberGenerate(0,(ui->huojiachangdu->value()/(2*ui->zuidachangdu->value())));//随机选择本层应该生成多少个货物，为了保证货物的分散，个数的最大值为货架被【两倍最大长度的货物】填满时的个数
        if (itemsOnThisLayer == 0)//如果这层放0个货物则空段长度为整层的长度
        {
            places.push_back({currentLayer, 0, ui->huojiachangdu->value()});
            totalPlaceLength += ui->huojiachangdu->value();
        }
        else
        {
            for(int i = 0; i < itemsOnThisLayer; ++i)
            {
                if(currentItemOnShelfID < itemOnShelf.size())//如果还有货物
                {
                    int thisLength=randomNumberGenerate(0,(ui->huojiachangdu->value()-usedLength)/(itemsOnThisLayer-i+1));//随机生成一个空位长度，范围为剩余长度 ÷ 本层未放置的物品数量
                    usedLength += thisLength;
                    if(thisLength >= (ui->zuixiaochangdu->value() + ui->huowujianju->value()))//如果这一位能放下物品则记录其数值
                    {
                        places.push_back({currentLayer, usedLength - thisLength, thisLength});
                        totalPlaceLength += thisLength;
                    }
                    usedLength+=itemOnShelf[currentItemOnShelfID];
                    ++currentItemOnShelfID;
                }
                else
                {break;}
            }
            if((ui->huojiachangdu->value() - usedLength) >= (ui->zuixiaochangdu->value() + ui->huowujianju->value()))//如果本层还有位置
            {
                places.push_back({currentLayer, usedLength, ui->huojiachangdu->value() - usedLength, 0, 0});
                totalPlaceLength += ui->huojiachangdu->value() - usedLength;
            }
        }
        ++currentLayer;
    }
}

std::vector<int> Widget::generateIndividual()//生成个体（第i个个体的值表示第i个货物放在这个值的空段中）
{
    for (int i = 0; i < items.size(); ++i)
    {
        individual.push_back(randomNumberGenerate(0, places.size() - 1));
    }
    return individual;
}

std::vector<std::vector<int> > Widget::generatePopulation()//生成种群
{
    for (int i = 0; i < ui->zhongqundaxiao->value() - 1; ++i)
    {
        population.push_back(generateIndividual());
    }
    return population;
}

double Widget::fitness(const std::vector<int> &individual)//适应度函数（现在只做出来了长度判断，重量有点没思路）
{
    for (int i = 0; i < individual.size(); ++i)//将每个货物的长度和重量更新进放这个货物的空段的被使用长度中
    {
        places[individual[i]].usedLength += (items[i].length + ui->huowujianju->value());
        places[individual[i]].usedWeight += items[i].weight;
    }

    double usedRatio = 0;
    for (int i = 0; i < (places.size() - 1); ++i)//计算每个空段的填充度,不考虑最后一个空段
    {
        if(places[i].length < places[i].usedLength)//如果空段被使用的长度大于本身长度则直接返回适应度为0
        {
            return 0;
        }
        else
        {
            if(places[i].usedLength == 0)//如果一个空段未被使用则认为其被填满以满足货物在未使用完空段就填满的情况
            {
                usedRatio += 1;
            }
            else
            {
                usedRatio += (places[i].usedLength / places[i].length);
            }
        }
    }
    return usedRatio / places.size();//返回整个排样方法的总填充度
}



void Widget::on_pushButton_clicked()
{
    items.clear();
    places.clear();
    ui->shuchu->clear();
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

