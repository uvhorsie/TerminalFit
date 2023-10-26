#ifndef DASHBOARDPAGE_H
#define DASHBOARDPAGE_H
#include "qlabel.h"
#include "qlineedit.h"
#include "qradiobutton.h"
#include <QWidget>


class DashboardPage : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardPage(QWidget *parent = nullptr);

private slots:
    void goBackToMainPage();

signals:

public slots:
    void calculateCalories();

private:
    QLineEdit *weightInput;
    QLineEdit *heightInput;
    QLineEdit *ageInput;
    QRadioButton *maleRadioButton;
    QRadioButton *femaleRadioButton;
    QLabel *calorieResult;


};

#endif // DASHBOARDPAGE_H
