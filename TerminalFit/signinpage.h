#ifndef SIGNINPAGE_H
#define SIGNINPAGE_H

#include <QLabel>
#include <QLineEdit>
#include <QWidget>

class SignInPage : public QWidget
{
    Q_OBJECT

public:
    explicit SignInPage(QWidget *parent = nullptr);

private slots:
    void goBackToMainPage();
    void checkUserCredentials(const QString &username, const QString &password);

public slots:
    void signIn();

private:
    QLabel *usernameLabel;
    QLineEdit *usernameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
};

#endif // SIGNINPAGE_H
