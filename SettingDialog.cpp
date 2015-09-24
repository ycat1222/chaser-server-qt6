#include "SettingDialog.h"
#include "ui_SettingDialog.h"
#include <QSettings>
#include <QFileDialog>

SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    QSettings* mSettings;
    mSettings = new QSettings( "setting.ini", QSettings::IniFormat ); // iniファイルで設定を保存
    mSettings->setIniCodec( "UTF-8" ); // iniファイルの文字コード
    ui->setupUi(this);


    QVariant v = mSettings->value( "LogFilepath" );
    if (v.type() != QVariant::Invalid)
    {
        ui->Log->setText(v.toString());
    }
    v = mSettings->value( "Timeout" );
    if (v.type() != QVariant::Invalid)
    {
        ui->Timeout->setValue(v.toInt());
    }
    v = mSettings->value( "Gamespeed" );
    if (v.type() != QVariant::Invalid)
    {
        ui->Gamespeed->setValue(v.toInt());
    }
}

void SettingDialog::Export(){

    QSettings* mSettings;
    mSettings = new QSettings( "setting.ini", QSettings::IniFormat ); // iniファイルで設定を保存
    mSettings->setIniCodec( "UTF-8" ); // iniファイルの文字コード

    mSettings->setValue( "LogFilepath", ui->Log->text() );
    mSettings->setValue( "Timeout", ui->Timeout->value() );
    mSettings->setValue( "Gamespeed", ui->Gamespeed->value());
}

void SettingDialog::openDirectory(){
    ui->Log->setText(QFileDialog::getExistingDirectory(this, tr("ログファイル保存先を選択")));
}


SettingDialog::~SettingDialog()
{
    delete ui;
}
