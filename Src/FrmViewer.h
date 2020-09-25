#ifndef FRMVIEWER_H
#define FRMVIEWER_H

#pragma once

#include <QWidget>
#include "rabbitremotecontrol_export.h"

namespace Ui {
class CFrmViewer;
}

class CConnect;

class RABBITREMOTECONTROL_EXPORT CFrmViewer : public QWidget
{
    Q_OBJECT
    
public:
    explicit CFrmViewer(QWidget *parent = nullptr);
    virtual ~CFrmViewer() override;
        
    enum ADAPT_WINDOWS {
        Auto,
        Original,        // Original desktop size, the left-top of the desktop is aligned with the left-top of the window
        OriginalCenter,  // Original desktop size, the center of the desktop is aligned with the center of the window
        Zoom,            // Desktop adapt to windows
        AspectRation,    // Keep desktop aspectration adapt to windows
    };
    void SetAdaptWindows(ADAPT_WINDOWS aw = Original);
    void SetConnect(CConnect* c);
    void SetClipboard(bool enable = true);
    
public Q_SLOTS:
    void slotConnect();
    void slotDisconnect();
    void slotSetDesktopSize(int width, int height);
    void slotUpdateRect(const QRect& r, const QImage& image);
    void slotServerCutText(const QString &text);
    
Q_SIGNALS:
    void sigMousePressEvent(QMouseEvent *event);
    void sigMouseReleaseEvent(QMouseEvent *event);
    void sigMouseDoubleClickEvent(QMouseEvent *event);
    void sigMouseMoveEvent(QMouseEvent *event);
    void sigWheelEvent(QWheelEvent *event);
    void sigKeyPressEvent(QKeyEvent *event);
    void sigKeyReleaseEvent(QKeyEvent *event);
    
private:
    Ui::CFrmViewer *ui;
    
    // QWidget interface
protected:    
    virtual void resizeEvent(QResizeEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void wheelEvent(QWheelEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    
private:
    QSize m_DesktopSize;
    QImage m_Desktop;
    
    ADAPT_WINDOWS m_AdaptWindows;
    bool m_bClipboard;
    
    CConnect* m_pConnect;
};

#endif // FRMVIEWER_H
