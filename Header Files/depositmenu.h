#ifndef DEPOSITMENU_H
#define DEPOSITMENU_H

#include <QDialog>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

namespace Ui {
class depositMenu;
}

class depositMenu : public QDialog
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
    void depositBloodBag(string  , string );
public:
    explicit depositMenu(QWidget *parent = nullptr);
    ~depositMenu();

private slots:
    void on_DEPOSIT_clicked();

    void on_cancel_clicked();

private:
    Ui::depositMenu *ui;
};

#endif // DEPOSITMENU_H
