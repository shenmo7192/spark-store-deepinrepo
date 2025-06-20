#ifndef DOWNLOADITEM_H
#define DOWNLOADITEM_H

#include <QWidget>
#include <QTextBrowser>
#include <QMenu>
#include <QAction>
#include "utils/utils.h"
#include <DDialog>
DWIDGET_USE_NAMESPACE

namespace Ui {
class DownloadItem;
}

class DownloadItem : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadItem(QWidget *parent = nullptr);
    ~DownloadItem();

    int num;
    bool free;
    static bool isInstall;
    bool reinstall;
    QString speed;
    QString out;
    QString pkgName;
    bool close;
    int download;
    void setValue(qint64);
    void setMax(qint64);
    void setName(QString);
    QString getName();
    int readyInstall();

    void setFileName(QString);
    void seticon(const QPixmap);
    void closeDownload();
    void setSpeed(QString);

    void install(int);

    // 新增：安装时额外参数
    QString installExtraArg;

private:
    Ui::DownloadItem *ui;

    QMenu *menu_install;
    QAction *action_dpkg;
    QAction *action_deepin;
    QAction *action_gdebi;

    DDialog *output_w;
    QTextBrowser *textbrowser;

private slots:
    void on_pushButton_install_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

    void slotAsyncInstall(int t);

signals:
    void finished(bool success);
};

#endif // DOWNLOADITEM_H
