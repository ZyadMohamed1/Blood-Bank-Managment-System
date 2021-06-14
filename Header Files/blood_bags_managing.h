#ifndef BLOOD_BAGS_MANAGING_H
#define BLOOD_BAGS_MANAGING_H

#include <QWidget>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

namespace Ui {
class BLOOD_BAGS_MANAGING;
}

class BLOOD_BAGS_MANAGING : public QWidget
{
    Q_OBJECT
private:
    fstream savedFile;
    ofstream temp;
    string resultLine;
    string getProductionDate();
    string getExpiryDate();
    int convertToInteger(string);
    int calculateDifference(int, int);
public:
    explicit BLOOD_BAGS_MANAGING(QWidget *parent = nullptr);
    void insertBloodBag(string , string );
    ~BLOOD_BAGS_MANAGING();

private slots:
    void on_cancel_clicked();

    void on_DEPOSIT_clicked();

private:
    Ui::BLOOD_BAGS_MANAGING *ui;
};

#endif // BLOOD_BAGS_MANAGING_H
