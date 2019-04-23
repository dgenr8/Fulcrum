#ifndef ECMGR_H
#define ECMGR_H

#include <QObject>
#include <QList>
#include "EXClient.h"
class EXClient;

class EXMgr : public QObject
{
    Q_OBJECT
public:
    explicit EXMgr(QObject *parent = nullptr);
    virtual ~EXMgr();
signals:

public slots:

protected slots:
    void onNewConnection();
    void onLostConnection();
    void onResponse(EXResponse);

private slots:
    void checkClients();

private:
    void loadServers();
    QList<EXClient *> clients;
    QTimer *checkClientsTimer = nullptr;
};

#endif // ECMGR_H