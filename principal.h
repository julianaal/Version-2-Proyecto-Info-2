#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "multiwidget.h"
#include "widget.h"
#include "menu.h"
#include "registro.h"

#include <QTimer>

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = 0);
    ~Principal();

private slots:
    void Login();
    void Menus();
    void Single();
    void SingleBMenu(void);
    void Multi();
    void MultiBMenu(void);
    void Record(void);
    void RecordBMenu(void);

private:
    Menu *menu;
    Registro *registro;
    Widget *GalagaS;
    MultiWidget *GalagaM;
    QTimer *time,*timer,*timer2,*time2,*time3,*timer3,*time4,*timer4;
};

#endif // PRINCIPAL_H
