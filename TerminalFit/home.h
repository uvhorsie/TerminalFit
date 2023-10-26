#ifndef HOME_H
#define HOME_H


#include "qwidget.h"
class Home : public QWidget
{
    Q_OBJECT

public:
    Home(const QString& username, QWidget* parent = nullptr);
};


#endif // HOME_H
