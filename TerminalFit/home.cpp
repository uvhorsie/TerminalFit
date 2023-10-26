#include "home.h"
#include <QLabel>
#include <QWidget>

Home::Home(const QString& username, QWidget* parent) : QWidget(parent)
{
    QLabel* welcomeLabel = new QLabel("Welcome, " + username, this);
    welcomeLabel->setFont(QFont("Times New Roman", 30));
    welcomeLabel->setAlignment(Qt::AlignCenter);

    // Add any additional widgets or content to your "Home" page as needed.
}
