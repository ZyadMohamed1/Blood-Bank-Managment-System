#ifndef UPDATEFORM_H
#define UPDATEFORM_H
#include "QFile"
#include <QDialog>

namespace Ui {
class UpdateForm;
}

class UpdateForm : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateForm(QString userID, QWidget *parent = nullptr);
    ~UpdateForm();
      QString id;
       void getID(QString id);
       QString userID;

private slots:
    void on_update_clicked();

private:
    Ui::UpdateForm *ui;
    void rename(QFile *file, QString newid);

};

#endif // UPDATEFORM_H
