#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include "dashboardpage.h"

class SignUpPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);

signals:

public slots:
    void goBackToMainPage();
    void goBackToDashboard();

private slots:
    void saveUserDataToFile(const QString &username, const QString &password);

private:
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QLabel *weightLabel;
    QLineEdit *weightLineEdit;
    QLabel *genderLabel;
    QComboBox *genderComboBox;
    QPushButton *signupButton;
};

#endif // SIGNUPPAGE_H
