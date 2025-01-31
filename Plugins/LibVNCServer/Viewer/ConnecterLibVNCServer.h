#ifndef CCONNECTERLIBVNC_H
#define CCONNECTERLIBVNC_H

#include "ConnecterDesktop.h"
#include "ConnectLibVNCServer.h"

class CDlgSettingsLibVnc;
class CConnecterLibVNCServer : public CConnecterDesktop
{
public:
    explicit CConnecterLibVNCServer(CPluginViewer *parent);
    virtual ~CConnecterLibVNCServer() override;

public:
    virtual qint16 Version() override;

protected:
    virtual QDialog *GetDialogSettings(QWidget *parent) override;
    virtual int OnLoad(QDataStream& d) override;
    virtual int OnSave(QDataStream& d) override;
    virtual CConnect* InstanceConnect() override;
    
private:
    CConnectLibVNCServer::strPara m_Para;
    
    friend CConnectLibVNCServer;
    friend CDlgSettingsLibVnc;
};

#endif // CCONNECTERLIBVNC_H
