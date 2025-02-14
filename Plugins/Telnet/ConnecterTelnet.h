#ifndef CCONNECTERTELNET_H
#define CCONNECTERTELNET_H

#include "ConnecterPluginsTerminal.h"
#include "ParameterTelnet.h"
#include <QTcpSocket>

class CConnecterTelnet : public CConnecterPluginsTerminal
{
    Q_OBJECT
public:
    explicit CConnecterTelnet(CPluginViewer *parent);
    virtual ~CConnecterTelnet();
    
    // CConnecterPluginsTerminal interface
protected:
    virtual QDialog *GetDialogSettings(QWidget *parent) override;
    virtual CParameterTerminal *GetPara() override;
    virtual int SetParamter() override;
    virtual int OnConnect() override;
    virtual int OnDisConnect() override;
    virtual int OnLoad(QDataStream &d) override;
    virtual int OnSave(QDataStream &d) override;
    
protected Q_SLOTS:
    void slotSendData(const char *data, int size);
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError err);
    
private:
    CParameterTelnet* m_pPara;
    QTcpSocket* m_pSocket;
};

#endif // CCONNECTERTELNET_H
