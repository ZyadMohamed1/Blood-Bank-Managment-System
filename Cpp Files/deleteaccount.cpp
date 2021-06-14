#include "deleteaccount.h"
#include "ui_deleteaccount.h"
#include <string>
#include "Filestream.h"
#include "QFile"
using namespace std;
DeleteAccount::DeleteAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteAccount)
{
    ui->setupUi(this);
}

DeleteAccount::~DeleteAccount()
{
    delete ui;
}



void DeleteAccount::deleteAcc(string id, string pass){
      string Fid, Fpass;
      ifstream f;
      f.open("Dindex");
      ofstream temp;
      temp.open("temp");
      while (f >> Fid >> Fpass)
      {

          if ((id == Fid) && (pass == Fpass))
          {
              continue;
          }
          else
          {
              temp << Fid << " " << Fpass << endl;
          }
      }
      string s = "temp";
      string a = "index";
      char* char_arr;
      char_arr = &id[0];
      char* oldname = &s[0];
      char* newname =&a[0];

      if (remove(char_arr))
      {


      }
      f.close();
      temp.close();
      remove("Dindex");
      rename("temp", "Dindex");

}

void DeleteAccount::on_Delete_clicked()
{
    string id = ui->takeid->text().toStdString();
    string pass = ui->pass->text().toStdString();
    deleteAcc(id,pass);
    hide();
}

