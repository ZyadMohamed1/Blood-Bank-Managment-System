#include "adminpage.h"
#include "ui_adminpage.h"
#include "showallbagsinfo.h"
#include "depositmenu.h"
#include "showdonationrequstes.h"
#include "showrecipientrequests.h"
#include "adminwithdraw.h"

AdminPage::AdminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminPage)
{
    ui->setupUi(this);
}

AdminPage::~AdminPage()
{
    delete ui;
}


void AdminPage::on_EXIT_clicked()
{

}
void AdminPage::on_showAllInfo_clicked()
{
    showAllBagsInfo showInfo;
    showInfo.setModal(true);
    showInfo.exec();

}


void AdminPage::on_deposit_clicked()
{
    depositMenu deposit;
    deposit.setModal(true);
    deposit.exec();
}


void AdminPage::on_showDonation_clicked()
{
    showDonationRequstes show;
    show.setModal(true);
    show.exec();
}







void AdminPage::on_pushButton_22_clicked()
{
    AdminWithdraw Ad;
    Ad.setModal(true);
    Ad.exec();

}


void AdminPage::on_EXIT_4_clicked()
{
    hide();
}

