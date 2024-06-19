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

    ui->jiaochagailv->setRange(0,1);
    ui->jiaochagailv->setSingleStep(0.01);
    ui->jiaochagailv->setValue(0.7);
    ui->tubiangailv->setRange(0,1);
    ui->tubiangailv->setDecimals(3);
    ui->tubiangailv->setSingleStep(0.001);
    ui->tubiangailv->setValue(0.01);
    ui->zhongqundaxiao->setRange(20,500);
    ui->zhongqundaxiao->setSingleStep(10);
    ui->zhongqundaxiao->setValue(70);
    ui->diedaicishu->setRange(100,50000);
    ui->diedaicishu->setSingleStep(100);
    ui->diedaicishu->setValue(5000);
}

Widget::~Widget()
{
    delete ui;
}

int Widget::randomNumberGenerate(int start, int end) const//随机数生成器
{
    std::mt19937 gen(std::random_device{}());
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
    itemOnShelf.clear();
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
    individual.clear();
    for (int i = 0; i < places.size(); ++i)
    {
        places[i].usedLength = 0;
        places[i].usedWeight = 0;
    }

    for (int i = 0; i < items.size(); ++i)
    {
        int placeIn;
        while(true)//检测这次生成的是否是可以放货物的空段
        {
            placeIn = randomNumberGenerate(0, places.size() - 1);
            if((places[placeIn].length - places[placeIn].usedLength) > (items[i].length + ui->huowujianju->value()))
            {
                break;//如果是才执行下面的步骤，否则一直尝试随机生成空段ID
            }
        }
        places[placeIn].usedLength += (items[i].length + ui->huowujianju->value());
        places[placeIn].usedWeight += items[i].weight;
        individual.push_back(placeIn);
    }
    return individual;
}

std::vector<std::vector<int> > Widget::generatePopulation()//生成种群
{
    individual.clear();
    for (int i = 0; i < ui->zhongqundaxiao->value(); ++i)
    {
        population.push_back(generateIndividual());
    }
    return population;
}

double Widget::fitness(const std::vector<int> &individual) const//适应度函数（现在只做出来了长度判断，重量有点没思路）
{
    std::vector<Place> tempPlaces = places;
    for (int i = 0; i < tempPlaces.size(); ++i)//清空每个位置被占用的长度，因为这个数值在之前生成排样方法时被用过
    {
        tempPlaces[i].usedLength = 0;
        tempPlaces[i].usedWeight = 0;
    }
    for (int i = 0; i < individual.size(); ++i)
    {
        tempPlaces[individual[i]].usedLength += (items[i].length + ui->huowujianju->value());
        tempPlaces[individual[i]].usedWeight += items[i].weight;
    }
    double usedRatio = 0;
    for (int i = 0; i < (tempPlaces.size() - 1); ++i)//计算每个空段的填充度,不考虑最后一个空段
    {
        if(tempPlaces[i].length < tempPlaces[i].usedLength)//如果空段被使用的长度大于本身长度则直接返回适应度为0
        {
            return 0;
        }
        else
        {
            if(tempPlaces[i].usedLength == 0)//如果一个空段未被使用则认为其被填满以满足货物在未使用完空段就填满的情况
            {
                usedRatio += 1;
            }
            else
            {
                usedRatio += (static_cast<double>(tempPlaces[i].usedLength) / static_cast<double>(tempPlaces[i].length));
            }
        }
    }
    return usedRatio / static_cast<double>(tempPlaces.size());//返回整个排样方法的总填充度
}

std::vector<int> Widget::selection() const//选择
{
    std::vector<double> fitnessValues;
    for(const auto& ind : population)
    {
        fitnessValues.push_back(fitness(ind));
    }

    std::discrete_distribution<int> dist(fitnessValues.begin(),fitnessValues.end());
    std::mt19937 gen{std::random_device{}()};
    return population[dist(gen)];
}

std::pair<std::vector<int>, std::vector<int> > Widget::crossover(const std::vector<int> &parent1, const std::vector<int> &parent2) const//交叉
{
    std::mt19937 gen(std::random_device{}());
    double canCrossover = std::uniform_real_distribution<double>(0.0, 1.0)(gen);
    if(canCrossover < ui->jiaochagailv->value())
    {
        int point = std::uniform_int_distribution<int>(1, static_cast<int>(parent1.size() - 1))(gen);

        std::vector<int> child1(parent1.begin(), parent1.begin() + point);
        child1.insert(child1.end(), parent2.begin() + point, parent2.end());

        std::vector<int> child2(parent2.begin(), parent2.begin() + point);
        child2.insert(child2.end(), parent1.begin() + point, parent1.end());

        std::vector<std::vector<int>> findMaxFitness = {parent1, parent2, child1, child2};
        std::sort(findMaxFitness.begin(),findMaxFitness.end(),[this](const auto& a, const auto& b){return fitness(a) > fitness(b);});

        return {findMaxFitness[0], findMaxFitness[1]};
    }
    else
    {
        return {parent1, parent2};
    }
}

void Widget::mutate(std::vector<int> &individual) const//变异
{
    std::mt19937 gen(std::random_device{}());
    if (std::uniform_real_distribution<double>{0.0, 1.0}(gen) < ui->tubiangailv->value())
    {
        int i = std::uniform_int_distribution<int>{0, static_cast<int>(individual.size() - 1)}(gen);//进行一次两个位点的随机交换
        int j = std::uniform_int_distribution<int>{0, static_cast<int>(individual.size() - 1)}(gen);
        std::swap(individual[i], individual[j]);

        int k = std::uniform_int_distribution<int>{0, static_cast<int>(individual.size() - 1)}(gen);//进行一次单个位点的随机变化
        individual[k] = randomNumberGenerate(0, places.size() - 1);
    }
}

std::vector<int> Widget::getBestIndividual() const//寻找最大适应度的个体
{
    return *std::max_element(population.begin(), population.end(), [this](const auto& a, const auto& b){return fitness(a) > fitness(b);});
}

void Widget::printBestSolution() const
{
    auto best = getBestIndividual();
    auto bestValue = fitness(best);
    QString text;
    text.clear();
    // text.append("第");
    // text.append(QString::number(currentGeneration));
    // text.append("次迭代填充度：");
    text.append(QString::number(bestValue));
    ui->shuchu->append(text);
}

void Widget::runGeneticAlgorithm()//遗传函数本体
{
    generatePopulation();//创建初始种群
    for (int generation = 0; generation < ui->diedaicishu->value(); ++generation)
    {
        currentGeneration = generation;
        std::vector<std::vector<int>> newPopulation;
        std::vector<std::vector<int>> prevPopulation = population;
        for (int i = 0; i < (ui->zhongqundaxiao->value() / 2); ++i)
        {
            auto parent1 = selection();
            auto parent2 = selection();
            auto [child1, child2] = crossover(parent1, parent2);
            mutate(child1);
            mutate(child2);
            newPopulation.push_back(child1);
            newPopulation.push_back(child2);
        }
        population = newPopulation;
        if(fitness(getBestIndividual()) == 0.0)
        {
            population = prevPopulation;
        }
        printBestSolution();
    }
}

void Widget::on_pushButton_clicked()
{
    items.clear();
    places.clear();
    ui->shuchu->clear();
    generateItem();
    generatePlace();
    runGeneticAlgorithm();
}
