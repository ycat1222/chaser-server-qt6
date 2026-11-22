#ifndef CLIENTSETTINGFORM_H
#define CLIENTSETTINGFORM_H

#include <QGroupBox>
#include <QProcess>
#include <QFile>

#include "TcpClient.h"
#include "ComClient.h"
#include "ManualClient.h"

namespace Ui {
class ClientSettingForm;
}

class ClientSettingForm : public QGroupBox
{
    Q_OBJECT

public:
    BaseClient* client;

    explicit ClientSettingForm(QWidget *parent = 0);
    ~ClientSettingForm();
    void SetPortSpin(int num);
    void SetBotSettings(const QString &filePath, const QString &name);

    inline static const QString DEFAULT_BOT_FILE_PATH = QStringLiteral("./2019-U16asahikawaBot/u16asahikawaBot.exe");
    inline static const QString DEFAULT_BOT_NAME = QStringLiteral("botV4");

public slots:
    void SetStandby ();
    void Connected  ();
    void DisConnected();
    void ConnectionToggled(bool state);
    void ComboBoxChenged(QString text);

signals:
    void Standby(ClientSettingForm* client,bool complate);//準備完了
private:
    QString botFilePath = DEFAULT_BOT_FILE_PATH;
    QString botName = DEFAULT_BOT_NAME;

    Ui::ClientSettingForm *ui;
    QProcess *botProcess = nullptr;
};

#endif // CLIENTSETTINGFORM_H
