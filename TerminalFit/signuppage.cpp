#include "signuppage.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout> // Include QHBoxLayout
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include <QFormLayout>

#include "mainwindow.h"

SignUpPage::SignUpPage(QWidget *parent) : QWidget(parent)
{
    // Create the content for the sign-up page
    QLabel *titleLabel = new QLabel("Welcome to Terminal Fitness", this);
    titleLabel->setFont(QFont("Times New Roman", 30));
    titleLabel->setAlignment(Qt::AlignCenter);

    emailLabel = new QLabel("Email:", this);
    emailLineEdit = new QLineEdit(this);
    emailLineEdit->setFixedSize(200, 30);
    emailLineEdit->setAlignment(Qt::AlignCenter);
    emailLabel->setFont(QFont("Arial", 15));

    nameLabel = new QLabel("Username:", this);
    nameLineEdit = new QLineEdit(this);
    nameLineEdit->setFixedSize(200, 30);
    nameLabel->setFont(QFont("Arial", 15));

    passwordLabel = new QLabel("Password:", this);
    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setFixedSize(200, 30);
    passwordLabel->setFont(QFont("Arial", 15));

    weightLabel = new QLabel("Weight:", this);
    weightLineEdit = new QLineEdit(this);
    weightLineEdit->setFixedSize(200, 30);
    weightLabel->setFont(QFont("Arial", 15));

    genderLabel = new QLabel("Gender:", this);
    genderComboBox = new QComboBox(this);
    genderComboBox->addItem("Male");
    genderComboBox->addItem("Female");
    genderComboBox->setFixedSize(200, 30);
    genderLabel->setFont(QFont("Arial", 15));

    signupButton = new QPushButton("Sign Up", this);
    signupButton->setFixedSize(100, 30);
    connect(signupButton, &QPushButton::clicked, this, &SignUpPage::goBackToDashboard); // Connect the button to the new slot

    // Add a "Back" button to return to the main menu
    QPushButton *backButton = new QPushButton("Back", this);
    connect(backButton, &QPushButton::clicked, this, &SignUpPage::goBackToMainPage);
    backButton->setFixedSize(100, 30); // Set the size of the "Back" button

    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(10); // Reduce spacing
    layout->addWidget(titleLabel, 0, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(emailLabel, 1, 0);
    layout->addWidget(emailLineEdit, 1, 1);
    layout->addWidget(nameLabel, 2, 0);
    layout->addWidget(nameLineEdit, 2, 1);
    layout->addWidget(passwordLabel, 3, 0);
    layout->addWidget(passwordLineEdit, 3, 1);
    layout->addWidget(weightLabel, 4, 0);
    layout->addWidget(weightLineEdit, 4, 1);
    layout->addWidget(genderLabel, 5, 0);
    layout->addWidget(genderComboBox, 5, 1);
    layout->addWidget(signupButton, 6, 0, 1, 2, Qt::AlignCenter);
    layout->addWidget(backButton, 7, 0, 1, 2, Qt::AlignCenter);

    signupButton->setStyleSheet("background-color: #4CAF50; color: white; border: none; padding: 5px 20px;");
    backButton->setStyleSheet("background-color: #f44336; color: white; border: none; padding: 5px 20px;");

    layout->setContentsMargins(50, 20, 50, 20);

    QPixmap appIcon("C:/Users/james/OneDrive/Pictures/terminalfit.png");
    setWindowIcon(appIcon);

    setLayout(layout);
}

void SignUpPage::saveUserDataToFile(const QString &username, const QString &password)
{
    // Open the text file for appending
    QFile file("user_credentials.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << username << " " << password << "\n"; // Store the username and password
        file.close();
    }
}

void SignUpPage::goBackToMainPage()
{
    // Get the username and password from the QLineEdit widgets
    QString username = emailLineEdit->text();
    QString password = passwordLineEdit->text();

    // Save the user information to a text file
    saveUserDataToFile(username, password);

    // Navigate back to the main page
    MainWindow *mainWindow = new MainWindow;
    this->hide(); // Hide the sign-up page
    mainWindow->show(); // Show the main page

}

void SignUpPage::goBackToDashboard()
{
    // Get the username and password from the QLineEdit widgets
    QString username = emailLineEdit->text();
    QString password = passwordLineEdit->text();

    // Save the user information to a text file
    saveUserDataToFile(username, password);

    // Navigate to the dashboard page
    DashboardPage *dashboardPage = new DashboardPage;
    this->hide(); // Hide the sign-up page
    dashboardPage->show(); // Show the dashboard page
}

