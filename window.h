#ifndef WINDOW_H
#define WINDOW_H
#include "startingwindow.h"
#include <QDialog>
#include "path.h"
namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Window *ui;
    StartingWindow *win;
    Path *path;
};

#endif // WINDOW_H
