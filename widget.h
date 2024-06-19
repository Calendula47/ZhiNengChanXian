#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <random>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int randomNumberGenerate(int start, int end);
    void generateItem();
    void generatePlace();
    std::vector<int> generateIndividual();
    std::vector<std::vector<int>> generatePopulation();
    double fitness(const std::vector<int> &individual) const;
    std::vector<int> selection() const;
    std::pair<std::vector<int>,std::vector<int>> crossover(const std::vector<int>& parent1, const std::vector<int>& parent2) const;
    void mutate(std::vector<int>& individual) const;
    std::vector<int> getBestIndividual() const;
    void runGeneticAlgorithm();
    void printBestSolution() const;

    struct Item{int length;int weight;};
    struct Place{int layer;int position;int length;int usedLength;int usedWeight;};
    std::vector<Item> items;
    std::vector<Place> places;
    std::vector<int> itemOnShelf;
    int totalItemLength;
    int totalPlaceLength;
    std::vector<int> individual;
    std::vector<std::vector<int>> population;
    int currentGeneration;

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
