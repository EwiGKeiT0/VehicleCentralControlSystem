#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
// #include "widget.h"
#include <qpixmap.h>
#include <QEvent>
#include<qmessagebox.h>
#include <QtSvg/QtSvg>
#include <QMediaPlayer>
#include <QFileDialog>
#include <qsvgrenderer.h>
#include <qpainter.h>
#include <QMessageBox>
#include <QAudioOutput>
#include <QMediaMetaData>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QTimer>
#include <qlistwidget.h>
#include <QImage>
#include <QLabel>
#include "streamthread.h"
#include "audiostreamthread.h"
namespace Ui {
    class mediaWidget;
}
    class Widget;
class mediaWidget : public QWidget
{
    Q_OBJECT
protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
    void updateAlbumArt();
public slots:
    void startStream(const QString &url);
    void stopStream();
    void onSearch(const QString &url);

private slots:
    void onFrameReady(const QImage &image);
    void onErrorOccurred(const QString &error);
    void on_listWidget_itemClicked(QListWidgetItem *item);

private:
    QMediaPlayer *player;
    QMediaPlayer *videoPlayer;
    QVideoWidget *videoWidget;
    QTimer *timer;
public:
    explicit mediaWidget(QWidget *parent = nullptr, Widget *father = nullptr);
    ~mediaWidget();

private:
    StreamThread *streamThread;
    AudioStreamThread *audioStreamThread;
    Ui::mediaWidget *ui;
    Widget *mainWindow;
};

#endif // MEDIAWIDGET_H
